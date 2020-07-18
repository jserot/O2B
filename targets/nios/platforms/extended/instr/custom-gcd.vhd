library ieee;
  use ieee.std_logic_1164.all;
  use ieee.numeric_std.all;

entity custom_gcd is
  port(
  signal clk : in std_logic; -- CPU's master-input clk (required for multi-cycle)
  signal reset : in std_logic; -- CPU's master asynchronous reset (required for multi-cycle)
  signal clk_en: in std_logic; -- Clock-qualifier (required for multi-cycle)
  signal start: in std_logic; -- True when this instr. issues (required for multi-cycle)
  signal done: out std_logic; -- True when instr. completes (required for variable muli-cycle)
  signal dataa: in std_logic_vector (31 downto 0); -- operand A (always required)
  signal datab: in std_logic_vector (31 downto 0); -- operand B (optional)
  signal result : out std_logic_vector (31 downto 0) -- result (always required)
  );
end entity;

architecture rtl of custom_gcd is
  type t_state is (Repos, Calcul, Fin);
  signal etat: t_state;
  signal a, b: unsigned(31 downto 0);
begin
  process(reset, clk)
  begin
    if ( reset = '1' ) then
      etat <= Repos;
      done <= '0';
    elsif rising_edge(clk) then
      if ( clk_en = '1' ) then 
      case etat is
        when Repos =>
          if (start='1') then
            a <= unsigned(dataa);
            b <= unsigned(datab);
            etat <= Calcul;
            done <= '0';
          end if;
        when Calcul =>
          if ( a = b ) then
            result <= std_logic_vector(a);
            done <= '1';   
            etat <= Fin;
          elsif ( a > b ) then
            a <= a-b;
          else
            b <= b-a;
          end if;
        when Fin =>
          done <= '0'; -- Asserting done just for one clock cycle
          etat <= Repos;
      end case;	    			
      end if;
    end if;
  end process;		
end architecture;
