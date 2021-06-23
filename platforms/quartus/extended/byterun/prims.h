/* C-interface between:                             */
/*   -> prims/bindings.c                            */
/*   -> simul/sf-regs.c | ?.c                       */

#include<stdint.h>
#include<stdbool.h>

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

#ifndef PRIMS_H
#define PRIMS_H

bool read_bit(uint8_t reg, uint8_t bit);
void set_bit(uint8_t reg, uint8_t bit);
void clear_bit(uint8_t reg, uint8_t bit);
void write_register(uint8_t reg, uint8_t val);
uint8_t read_register(uint8_t reg);

/******************************************************************************/

void delay(int ms);
int millis();

#endif

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
void nios_serial_write_char(char c);
/* void nios_serial_write_int(int n); */
/* void nios_serial_write_string(char* s); */
char nios_serial_read_char();
/* char* nios_serial_read_string(); */

void nios_ssd_display_char(int i, char c);

void nios_led_set(int i, bool b);

bool nios_switch_get(int i);

bool nios_button_get(int i);

int nios_timer_init();
int nios_timer_get_us();
int nios_timer_get_ms();

int nios_get_sys_id();

// Extended functions

int nios_gcd(int m, int n);

int nios_gcd_ci(int m, int n);

int nios_gcd_cc(int m, int n);
