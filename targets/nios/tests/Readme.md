This directory contains test applications for the Nios target.
All these applications have been tested on a DE10-Lite board.

- "mini" is a simple application computing `fact 5` and displaying the result (120) on the seven-segments
  display (SSD) of the board
- "ios" shows how to use the various board IOs (push buttons, LEDs, switches, SSDs)
- "rotdisplay" displays a rotating message on the SSD
- "sieve" computes and displays the first 50 prime numbers 
- "sieve2" is a variant of "sieve" using tail recursive functions (and hence reducing the stack and
   heap memory requirements)
   
All these applications use the "basic" Nios platform.

- "gcd" illustrates how to use external functions, implemented in C or in VHDL (as custom
  instructions) in the Caml code
  
This application uses the "extended" Nios platform.

  
