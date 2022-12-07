module top(

      ///////// Clocks /////////
      // input              ADC_CLK_10,
      input              MAX10_CLK1_50,
      // input              MAX10_CLK2_50,

      // ///////// KEY /////////
      input    [ 1: 0]   KEY,

      // ///////// SW /////////
      input    [ 9: 0]   SW,

      // ///////// LEDR /////////
      output   [ 9: 0]   LEDR,

      // ///////// HEX /////////
      output   [ 7: 0]   HEX0,
      output   [ 7: 0]   HEX1,
      output   [ 7: 0]   HEX2,
      output   [ 7: 0]   HEX3,
      output   [ 7: 0]   HEX4,
      output   [ 7: 0]   HEX5,

      // ///////// SDRAM /////////
      output             DRAM_CLK,
      output             DRAM_CKE,
      output   [12: 0]   DRAM_ADDR,
      output   [ 1: 0]   DRAM_BA,
      inout    [15: 0]   DRAM_DQ,
      output             DRAM_LDQM,
      output             DRAM_UDQM,
      output             DRAM_CS_N,
      output             DRAM_WE_N,
      output             DRAM_CAS_N,
      output             DRAM_RAS_N

      // ///////// VGA /////////
      // output             VGA_HS,
      // output             VGA_VS,
      // output   [ 3: 0]   VGA_R,
      // output   [ 3: 0]   VGA_G,
      // output   [ 3: 0]   VGA_B,

      // ///////// Clock Generator I2C /////////
      // output             CLK_I2C_SCL,
      // inout              CLK_I2C_SDA,

      // ///////// GSENSOR /////////
      // output             GSENSOR_SCLK,
      // inout              GSENSOR_SDO,
      // inout              GSENSOR_SDI,
      // input    [ 2: 1]   GSENSOR_INT,
      // output             GSENSOR_CS_N,

      // ///////// GPIO /////////
      // inout    [35: 0]   GPIO,

      // ///////// ARDUINO /////////
      // inout    [15: 0]   ARDUINO_IO,
      // inout              ARDUINO_RESET_N 

);


platform u0 (
        .altpll_0_areset_conduit_export    (),     
        .altpll_0_locked_conduit_export    (),    
        .clk_clk                           (MAX10_CLK1_50),                           
        .reset_reset_n                     (1'b1),
		.led_external_connection_export (LEDR),
		.button_external_connection_export (KEY[1:0]), 
		.switch_external_connection_export (SW[9:0]),
		.hex0_external_connection_export (HEX0),
		.hex1_external_connection_export (HEX1),
		.hex2_external_connection_export (HEX2),
		.hex3_external_connection_export (HEX3),
		.hex4_external_connection_export (HEX4),
		.hex5_external_connection_export (HEX5), 
        .sdram_wire_addr(DRAM_ADDR),                
		.sdram_wire_ba(DRAM_BA),                  
		.sdram_wire_cas_n(DRAM_CAS_N),               
		.sdram_wire_cke(DRAM_CKE),                 
		.sdram_wire_cs_n(DRAM_CS_N),                
		.sdram_wire_dq(DRAM_DQ),                  
		.sdram_wire_dqm({DRAM_UDQM,DRAM_LDQM}),                 
		.sdram_wire_ras_n(DRAM_RAS_N),               
		.sdram_wire_we_n(DRAM_WE_N),
		.sdram_clk_clk(DRAM_CLK)
	 );

	// assign LEDR[0] = KEY[1];

endmodule
