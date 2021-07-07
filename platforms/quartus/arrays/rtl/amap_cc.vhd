library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity amap_cc is
	port (
        -- SLAVE INTERFACE ( <-> Nios )
		avs_s0_address   : in  std_logic_vector(2 downto 0); 
        -- 000 : control/status register (writing asserts start, reading gets rdy)
        -- 001 : arg1 register (src array start address)
        -- 010 : arg2 register (dst array start address)
        -- 011 : arg3 register (array size)
        -- other addresses are reserved for other args / results
		avs_s0_write     : in  std_logic;
		avs_s0_writedata : in  std_logic_vector(31 downto 0);
		avs_s0_read      : in  std_logic;
		avs_s0_readdata  : out std_logic_vector(31 downto 0);                  
		clock_clk        : in  std_logic;
		reset_reset      : in  std_logic;
        -- WRITE MASTER INTERFACE ( <-> Shared memory )
		avm_wm_address   : out std_logic_vector(31 downto 0);                 
		avm_wm_write      : out std_logic;                                       
		avm_wm_writedata  : out  std_logic_vector(31 downto 0);
		avm_wm_waitrequest : in  std_logic;
        -- avm_wm_response: in std_logic_vector(1 downto 0)
        -- READ MASTER INTERFACE ( <-> Shared memory )
		avm_rm_address   : out std_logic_vector(31 downto 0);                 
		avm_rm_read      : out std_logic;                                       
		avm_rm_readdata  : in  std_logic_vector(31 downto 0);
		avm_rm_waitrequest : in  std_logic
        -- avm_rm_response: in std_logic_vector(1 downto 0)
	);
end entity;

architecture rtl of amap_cc is

  type t_state is (Idle, Rd, WaitRd, WaitWr);
  signal state: t_state;
  signal raddr, waddr: unsigned(31 downto 0);
  signal size: unsigned(31 downto 0);
  signal count: unsigned(31 downto 0);
  signal rdy: std_logic;
  
begin

  WRITE: process (reset_reset, clock_clk)
    variable arg, res: unsigned(30 downto 0); -- 31 bits values
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
                state <= Rd;
              when "001" =>
                raddr <= unsigned(avs_s0_writedata);
              when "010" =>
                waddr <= unsigned(avs_s0_writedata);
              when "011" =>
                size <= unsigned(avs_s0_writedata);
              when others =>
                null; 
            end case;
          end if;
        when Rd =>
          if ( count <= size ) then 
            avm_rm_address <= std_logic_vector(raddr);
            avm_rm_read <= '1';
            state <= WaitRd;
          else -- Done
            rdy <= '1';
            state <= Idle;
          end if;
        when WaitRd =>  
          if avm_rm_waitrequest = '0' then -- end of read transfer
            avm_rm_read <= '0';
            arg := unsigned(avm_rm_readdata(31 downto 1)); -- Get rid of OCaml tag
            res := arg+to_unsigned(1, 31);  -- TO BE GENERALIZED !
            avm_wm_writedata <= std_logic_vector(res) & '1'; -- Re-tag value
            avm_wm_address <= std_logic_vector(waddr);
            avm_wm_write <= '1';
            state <= WaitWr;
          end if;
        when WaitWr =>  
          if avm_wm_waitrequest = '0' then -- end of write transfer
            avm_wm_write <= '0';
            raddr <= raddr + 4;
            waddr <= waddr + 4;
            count <= count + 1;
            state <= Rd;
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
          when "001" => avs_s0_readdata <= std_logic_vector(raddr);
          when "010" => avs_s0_readdata <= std_logic_vector(waddr);
          when "011" => avs_s0_readdata <= std_logic_vector(size);
          when others => null; 
        end case;
      end if;
    end if;
  end process;

end architecture; 
