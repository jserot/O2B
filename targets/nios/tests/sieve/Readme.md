This application computes and displays the 50 first prime numbers on the SSD display
using the Eratosthene Sieve algorithm.
The compute functions are taken verbatim from those given in `../../../../../pic32/tests/lchip/sieve/sieve.ml` 
For this version to run, the stack and heap sizes of the OMicroB interpreter must be increased to
1024 (see `OMICROB_OPTS` in `./Makefile`).
Timing is performed using a high resolution timer provided by the `basic` Nios platform.
The underlying implementation uses a hardware counter providing ticks each 20 ns. 
