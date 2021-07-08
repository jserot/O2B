library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.caml.all;

entity ared_cc is
	port (
        -- SLAVE INTERFACE ( <-> Nios )
		avs_s0_address   : in  std_logic_vector(2 downto 0); 
        -- 000 : control/status register (writing asserts start, reading gets rdy)
        -- 001 : arg1 register (start address)
        -- 010 : arg2 register (size)
        -- 011 : result register
        -- other addresses are reserved for other args / results
		avs_s0_write     : in  std_logic;
		avs_s0_writedata : in  std_logic_vector(31 downto 0);
		avs_s0_read      : in  std_logic;
		avs_s0_readdata  : out std_logic_vector(31 downto 0);                  
		clock_clk        : in  std_logic;
		reset_reset      : in  std_logic;
        -- -- WRITE MASTER INTERFACE ( <-> Shared memory )
		-- avm_wm_address   : out std_logic_vector(31 downto 0);                 
		-- avm_wm_write      : out std_logic;                                       
		-- avm_wm_writedata  : out  std_logic_vector(31 downto 0);
		-- avm_wm_waitrequest : in  std_logic;
        -- avm_wm_response: in std_logic_vector(1 downto 0)
        -- READ MASTER INTERFACE ( <-> Shared memory )
		avm_rm_address   : out std_logic_vector(31 downto 0);                 
		avm_rm_read      : out std_logic;                                       
		avm_rm_readdata  : in  std_logic_vector(31 downto 0);
		avm_rm_waitrequest : in  std_logic;
        avm_rm_response: in std_logic_vector(1 downto 0)
	);
end entity;

architecture rtl of ared_cc is

  type t_state is (Idle, SeqRd, WaitRd);
  signal state: t_state;
  signal address: unsigned(31 downto 0);
  signal size: unsigned(31 downto 0);
  signal count: unsigned(31 downto 0);
  signal acc: signed(30 downto 0);
  signal rdy: std_logic;
  
  function f(x: caml_int; y: caml_int) return caml_int is  -- the reducing function (to be adjusted)
  begin
    return x+y;
  end;

begin

  WRITE: process (reset_reset, clock_clk)
    variable data: caml_int;
  begin
    if reset_reset = '1' then
      avm_rm_read <= '0';
      state <= Idle;
      rdy <= '0';
    elsif rising_edge(clock_clk) then 
      case state is
        when Idle =>
          if avs_s0_write = '1' then
            case avs_s0_address is
              when "000" =>  -- writing CSR asserts starts operation
                rdy <= '0';
                count <= to_unsigned(0, 32);
                acc <= caml_int_const(0);
                state <= SeqRd;
              when "001" =>
                address <= unsigned(avs_s0_writedata);
              when "010" =>
                size <= unsigned(avs_s0_writedata);
              when others =>
                null; 
            end case;
          end if;
        when SeqRd =>
          if ( count < size ) then 
            avm_rm_address <= std_logic_vector(address);
            avm_rm_read <= '1';
            state <= WaitRd;
          else -- Done
            rdy <= '1';
            state <= Idle;
          end if;
        when WaitRd =>  
          if avm_rm_waitrequest = '0' then -- end of read transfer
            avm_rm_read <= '0';
            data := caml_decode_int(avm_rm_readdata);
            acc <= f(acc, data);
            address <= address + 4;
            count <= count + 1;
            state <= SeqRd; -- next value
          end if;
      end case;
    end if;
  end process;

  READ: process (clock_clk)
  begin
    if rising_edge(clock_clk) then 
      if avs_s0_read = '1' then
        case avs_s0_address is
          when "000" => avs_s0_readdata <= "0000000000000000000000000000000" & rdy; -- when reading CSR, bit 0 is rdy
          when "001" => avs_s0_readdata <= std_logic_vector(address);
          when "010" => avs_s0_readdata <= std_logic_vector(size);
          when "011" => avs_s0_readdata <= std_logic_vector(resize(acc,32)); -- Val_int encoding will be performed by C stub code
          when others => null; 
        end case;
      end if;
    end if;
  end process;

end architecture; 
