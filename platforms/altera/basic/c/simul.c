#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void nios_serial_write_char(char c)
{
  printf("nios_serial_write_char(%c)\n", c);
}

void nios_serial_write_int(int n)
{
  printf("nios_serial_write_int(%d)\n", n);
}

void nios_serial_write_string(char* s)
{
  printf("nios_serial_write_string(%s)\n", s);
}

char nios_serial_read_char()
{
  printf("nios_serial_read_char():\n");
  return getchar();
}

char* nios_serial_read_string()
{
  static char buf[80];
  printf("nios_serial_read_string():\n");
  scanf("%s", buf);
  return buf;
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

int nios_get_sys_id()
{
  printf("nios_get_sys_id()\n");
  return 0;
}
