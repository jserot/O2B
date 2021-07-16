void nios_serial_write_char(char c);
char nios_serial_read_char();

int nios_timer_init();
int nios_timer_get_us();
int nios_timer_get_ms();

#ifdef __OCAML__
#include <caml/mlvalues.h>
#else
#include "vm/values.h"
#endif

int nios_arr_reduce(value v);
int nios_arr_reduce_cc(int* src);
