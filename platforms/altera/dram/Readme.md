With this platform, the program data (stack, heap, bss) is stored in the external SDRAM.
The program code (text) is still stored in the on-chip memory.
A PLL is used to generate the two (phased locked) clocks required for this configuration
- one for the FPGA device 
- one for the external SDRAM device
Both clocks, generated from the base 50 MHz clock, have been pushed to 100 MHz.
