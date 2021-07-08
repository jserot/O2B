This directory contains test applications for the Quartus "basic" platform (DE10Lite board with Nios2 CPU)

- "mini" is a simple application computing `fact 5` and displaying the result (120) on the seven-segments
  display (SSD) of the board
- "ios" shows how to use the various board IOs (push buttons, LEDs, switches, SSDs)
- "rotdisplay" displays a rotating message on the SSD
- "sieve" computes and displays the first 50 prime numbers 
- "sieve2" is a variant of "sieve" using tail recursive functions (and hence reducing the stack and
   heap memory requirements)
- "ledshade" makes the 10 LEDs pulsating using a PWM
