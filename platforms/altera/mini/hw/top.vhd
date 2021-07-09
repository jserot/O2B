library ieee ;
use ieee.std_logic_1164.all;

entity top is
  port (MAX10_CLK1_50: in std_logic
       ); 
end entity;

architecture rtl of top is

	component platform is
		port (
			clk_clk                           : in  std_logic                    := 'X';             -- clk
			reset_reset_n                     : in  std_logic                    := 'X'
            );
			end component;

begin

	u0 : component platform
		port map (
			clk_clk                           => MAX10_CLK1_50,
			reset_reset_n                     => '1'
		);

end architecture;
