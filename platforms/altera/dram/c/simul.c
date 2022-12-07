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

void nios_ssd_display_char(int i, char c)
{
  printf("nios_ssd_display_char(%d,%d)\n", i, c);
}

void nios_led_set(int i, bool b)
{
  printf("nios_led_set(%d,%d)\n", i, b);
}

bool nios_switch_get(int i)
{
  printf("nios_switch_get(%d):\n", i);
  return getchar()=='1';
}

bool nios_button_get(int i)
{
  printf("nios_button_get(%d):\n", i);
  return getchar()=='1';
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

int nios_system_get_sys_freq()
{
  printf("nios_system_get_sys_freq()\n");
  return 0;
}
