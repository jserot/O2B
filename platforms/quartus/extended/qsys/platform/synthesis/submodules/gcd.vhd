-- Core GCD IP

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity gcd is
  port(
  signal clk : in std_logic; 
  signal reset : in std_logic; 
  signal start: in std_logic; 
  signal rdy: out std_logic;
  signal dataa: in unsigned (31 downto 0); 
  signal datab: in unsigned (31 downto 0); 
  signal result : out unsigned (31 downto 0)
  );
end entity;

architecture rtl of gcd is
  type t_state is (Repos, Calcul);
  signal etat: t_state;
  signal a, b: unsigned(31 downto 0);
begin
  process(reset, clk)
  begin
    if ( reset = '1' ) then
      etat <= Repos;
      rdy <= '1';
    elsif rising_edge(clk) then
      case etat is
        when Repos =>
          if (start='1') then
            a <= dataa;
            b <= datab;
            etat <= Calcul;
            rdy <= '0';
          end if;
        when Calcul =>
          if ( a = b ) then
            result <= a;
            rdy <= '1';   
            etat <= Repos;
          elsif ( a > b ) then
            a <= a-b;
          else
            b <= b-a;
          end if;
      end case;	    			
    end if;
  end process;		
end architecture;
