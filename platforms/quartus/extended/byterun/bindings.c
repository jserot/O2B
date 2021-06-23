#ifdef __OCAML__
#include <caml/mlvalues.h>
#else
#include "vm/values.h"
#endif

#include "prims.h"
#include "stdlib/random.h"
#include "stdlib/trace.h"

/******************************************************************************/

value caml_random_init(value n) {
  random_init(Int_val(n));
  return Val_unit;
}

value caml_random_bits(value bound) {
  return Val_int(random_bits((uint32_t) Int_val(bound)));
}

value caml_random_bool(value unit) {
  return Val_bool(random_bool());
}

/******************************************************************************/

value caml_unsafe_string_of_bytes(value b) {
  return b;
}

value caml_unsafe_bytes_of_string(value s) {
  return s;
}

/******************************************************************************/

#ifdef __OCAML__
#define String_field(val, i) String_val(val)[i]
#endif

value caml_debug_trace(value msg) {
  mlsize_t sz = string_length(msg);
  mlsize_t i;
  debug_trace_open();
  for (i = 0; i < sz; i ++) {
    debug_trace_char(String_field(msg, i));
  }
  debug_trace_close();
  return Val_unit;
}

value caml_debug_tracei(value n) {
  debug_trace_int(Int_val(n));
  return Val_unit;
}

/******************************************************************************/

value caml_set_bit(value reg, value bit) {
  set_bit(Int_val(reg), Int_val(bit));
  return Val_unit;
}

value caml_clear_bit(value reg, value bit) {
  clear_bit(Int_val(reg), Int_val(bit));
  return Val_unit;
}

value caml_read_bit(value reg, value bit) {
  return Val_bool(read_bit(Int_val(reg), Int_val(bit)));
}

/******************************************************************************/

value caml_write_register(value reg, value val) {
  write_register(Int_val(reg), Int_val(val));
  return Val_unit;
}

value caml_read_register(value reg) {
  return Val_int(read_register(Int_val(reg)));
}

/******************************************************************************/

value caml_delay(value ms) {
  delay(Int_val(ms));
  return Val_unit;
}

value caml_millis(value unit) {
  return Val_int(millis());
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
value caml_nios_serial_write_char(value val) {
  nios_serial_write_char(Int_val(val));
  return Val_unit;
}

/* value caml_nios_serial_write_int(value val) { */
/*   nios_serial_write_int(Int_val(val)); */
/*   return Val_unit; */
/* } */

/* value caml_nios_serial_write_string(value val) { */
/*   nios_serial_write_string(String_val(val)); */
/*   return Val_unit; */
/* } */

value caml_nios_serial_read_char(value unit) {
  return Val_int(nios_serial_read_char());
}

/* value caml_nios_serial_read_string(value unit) { */
/*   return Val_string(nios_serial_read_string()); */
/* } */

value caml_nios_ssd_display_char(value i, value c) {
  nios_ssd_display_char(Int_val(i), Int_val(c));
  return Val_unit;
}

value caml_nios_led_set(value i, value b) {
  nios_led_set(Int_val(i), Int_val(b));
  return Val_unit;
}

value caml_nios_switch_get(value i) {
  return Val_bool(nios_switch_get(Int_val(i)));
}

value caml_nios_button_get(value i) {
  return Val_bool(nios_button_get(Int_val(i)));
}

value caml_nios_timer_init(value unit) {
  return Val_int(nios_timer_init());
}

value caml_nios_timer_get_us(value unit) {
  return Val_int(nios_timer_get_us());
}

value caml_nios_timer_get_ms(value unit) {
  return Val_int(nios_timer_get_ms());
}

value caml_nios_get_sys_id(value unit) {
  return Val_int(nios_get_sys_id());
}

// Wrappers for the fonctions in the extension library

value caml_nios_gcd(value m, value n) {
  return Val_int(nios_gcd(Int_val(m), Int_val(n)));
}

value caml_nios_gcd_ci(value m, value n) {
  return Val_int(nios_gcd_ci(Int_val(m), Int_val(n)));
}

value caml_nios_gcd_cc(value m, value n) {
  return Val_int(nios_gcd_cc(Int_val(m), Int_val(n)));
}
