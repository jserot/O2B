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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void nios_serial_write_char(char c)
{
  printf("nios_serial_write_char(%c)\n", c);
}

char nios_serial_read_char()
{
  printf("nios_serial_read_char():\n");
  return getchar();
}

int nios_timer_init()
{
  printf("nios_timer_init()\n");
  return 0;
}

unsigned long nios_timer_get()
{
  printf("nios_timer_get()\n");
  return 0;
}

int nios_timer_get_us()
{
  printf("nios_timer_get_ms()\n");
  return 0;
}

int nios_timer_get_ms()
{
  printf("nios_timer_get_ms()\n");
  return 0;
}
