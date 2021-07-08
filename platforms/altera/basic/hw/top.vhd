library ieee ;
use ieee.std_logic_1164.all;

entity top is
  port (MAX10_CLK1_50: in std_logic;
	    HEX0: out std_logic_vector(7 downto 0);
	    HEX1: out std_logic_vector(7 downto 0);
	    HEX2: out std_logic_vector(7 downto 0);
	    HEX3: out std_logic_vector(7 downto 0);
	    HEX4: out std_logic_vector(7 downto 0);
	    HEX5: out std_logic_vector(7 downto 0);
	    KEY: in std_logic_vector(1 downto 0);
	    LEDR: out std_logic_vector(9 downto 0);
	    SW: in std_logic_vector(9 downto 0)
       ); 
end entity;

architecture rtl of top is

	component platform is
		port (
			button_external_connection_export : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			clk_clk                           : in  std_logic                    := 'X';             -- clk
			hex0_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			hex1_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			hex2_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			hex3_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			hex4_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			hex5_external_connection_export   : out std_logic_vector(7 downto 0);                    -- export
			led_external_connection_export    : out std_logic_vector(9 downto 0);                    -- export
			reset_reset_n                     : in  std_logic                    := 'X';             -- reset_n
			switch_external_connection_export : in  std_logic_vector(9 downto 0) := (others => 'X')  -- export
            );
			end component;

   signal ledFromNios: std_logic_vector(9 downto 0);
 
begin

	u0 : component platform
		port map (
			button_external_connection_export => KEY,
			clk_clk                           => MAX10_CLK1_50,
			hex0_external_connection_export   => HEX0, 
			hex1_external_connection_export   => HEX1, 
			hex2_external_connection_export   => HEX2, 
			hex3_external_connection_export   => HEX3, 
			hex4_external_connection_export   => HEX4, 
			hex5_external_connection_export   => HEX5, 
			led_external_connection_export    => ledFromNios,
			reset_reset_n                     => '1',
			switch_external_connection_export => SW
		);

	LEDR(9 downto 0) <= ledFromNios(9 downto 2) & SW(1) & not KEY(1);
    -- LED0 is hardwired to BUT1
    -- LED1 is hardwired to SW1
    -- LED3 will be controled by Nios instance u0
    
end architecture;
