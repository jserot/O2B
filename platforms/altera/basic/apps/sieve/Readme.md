This application computes and displays the 50 first prime numbers on the SSD display
using the Eratosthene Sieve algorithm.
For this version to run, the stack and heap sizes of the OMicroB interpreter must be increased to 1024 (see `OMICROB_OPTS` in `./Makefile`).
Timing is performed using a high resolution timer provided by the `basic` platform.
The underlying implementation uses a hardware counter providing ticks each 20 ns. 
