#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
/* #include "shared.h" */
/* #include "simul.h" */

// The following fonctions are defined just to ensure compatibility with OMicrob framework.
// They do not have a direct interpretation on FPGA platforms

void set_bit(uint8_t reg, uint8_t bit) { }

void clear_bit(uint8_t reg, uint8_t bit) { }

bool read_bit(uint8_t reg, uint8_t bit) { return 0; }

void write_register(uint8_t reg, uint8_t val) { }

uint8_t read_register(uint8_t reg) { return 0; }

void delay(int ms) {
  printf("delay(%d)\n", ms);
  usleep((useconds_t) ms * 1000);
}

int millis() {
  printf("millis\n");
  return 0;
}
