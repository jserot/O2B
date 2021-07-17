library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.caml.all;

entity lred_cc is
	port (
        -- SLAVE INTERFACE ( <-> Nios )
		avs_s0_address   : in  std_logic_vector(2 downto 0); 
        -- 000 : control/status register (writing asserts start, reading gets rdy)
        -- 001 : arg1 register (Avalon address of the caml heap)
        -- 010 : arg2 register (caml value representing the list)
        -- 011 : result register (final accumulator)
        -- other addresses are reserved for other args / results
		avs_s0_write     : in  std_logic;
		avs_s0_writedata : in  std_logic_vector(31 downto 0);
		avs_s0_read      : in  std_logic;
		avs_s0_readdata  : out std_logic_vector(31 downto 0);                  
		clock_clk        : in  std_logic;
		reset_reset      : in  std_logic;
        -- -- WRITE MASTER INTERFACE ( <-> Shlred_cc memory )
		-- avm_wm_address   : out std_logic_vector(31 downto 0);                 
		-- avm_wm_write      : out std_logic;                                       
		-- avm_wm_writedata  : out  std_logic_vector(31 downto 0);
		-- avm_wm_waitrequest : in  std_logic;
        -- avm_wm_response: in std_logic_vector(1 downto 0)
        -- READ MASTER INTERFACE ( <-> Shlred_cc memory )
		avm_rm_address   : out std_logic_vector(31 downto 0);                 
		avm_rm_read      : out std_logic;                                       
		avm_rm_readdata  : in  std_logic_vector(31 downto 0);
		avm_rm_waitrequest : in  std_logic;
        avm_rm_response: in std_logic_vector(1 downto 0)
	);
end entity;

architecture rtl of lred_cc is

  type t_state is (Idle, DecodeValue, GetHead, GetTail);
  signal state: t_state;
  signal caml_heap_base: unsigned(31 downto 0);
  signal v: std_logic_vector(31 downto 0);
  signal acc: signed(30 downto 0);
  signal rdy: std_logic;
  
  function f(x: caml_int; y: caml_int) return caml_int is  -- the reducing function (to be adjusted)
  begin
    return x+y;
  end;

begin

  WRITE: process (reset_reset, clock_clk)
    variable data: caml_int;
    variable blk_addr: unsigned(31 downto 0);
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
                acc <= caml_int_const(0);
                state <= DecodeValue;
              when "001" =>
                caml_heap_base <= unsigned(avs_s0_writedata);
              when "010" =>
                v <= avs_s0_writedata;
              when others =>
                null; 
            end case;
          end if;
        when DecodeValue =>
          if caml_is_block(v) then
            -- value [v] is a pointer to a block allocated in the heap
            blk_addr := caml_heap_addr(caml_heap_base, v);
            avm_rm_address <= std_logic_vector(blk_addr);
            avm_rm_read <= '1';
            state <= GetHead; 
          else -- Immediate value. This must be 0 and means end of list
            rdy <= '1';
            state <= Idle;
          end if;
        when GetHead =>  
          if avm_rm_waitrequest = '0' then -- end of read transfer
            avm_rm_read <= '0';
            data := caml_decode_int(avm_rm_readdata); -- head value
            acc <= acc + data;
            avm_rm_address <= std_logic_vector(blk_addr+4);
            avm_rm_read <= '1';
            state <= GetTail; 
          end if;
         when GetTail =>  
          if avm_rm_waitrequest = '0' then -- end of read transfer
            avm_rm_read <= '0';
            v <= avm_rm_readdata; -- tail value
            state <= DecodeValue;
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
          when "001" => avs_s0_readdata <= std_logic_vector(caml_heap_base);
          when "010" => avs_s0_readdata <= std_logic_vector(v);
          when "011" => avs_s0_readdata <= std_logic_vector(resize(acc,32));
          when others => null; 
        end case;
      end if;
    end if;
  end process;

end architecture; 
