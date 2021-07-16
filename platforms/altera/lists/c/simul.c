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

#ifdef __OCAML__
#include <caml/mlvalues.h>
#else
#include "vm/values.h"
#endif

int nios_list_reduce(value v)
{
  printf("nios_list_reduce(%x)\n", v);
  return 0;
}

int nios_list_reduce_cc(int* src)
{
  printf("nios_list_reduce_cc(%x)\n", src);
  return 0;
}

