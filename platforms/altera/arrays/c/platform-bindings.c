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

#ifdef __OCAML__
#define BLOCK_ADDR(v) ((int32_t*)(Op_val(v)))
#else
#define BLOCK_ADDR(v) ((int32_t *)(Ram_block_val(v)))
#endif

value caml_nios_arr_reduce(value a) {
  alt_printf("** caml_nios_arr_reduce: v=%x\n", (int32_t*)v);
  inspect_value(v);
  return Val_int(nios_arr_reduce(BLOCK_ADDR(a),Wosize_val(a)));
}

value caml_nios_arr_reduce_cc(value a) {
  alt_printf("** caml_nios_arr_reduce_cc: v=%x\n", (int32_t*)v);
  inspect_value(v);
  return Val_int(nios_arr_reduce_cc(BLOCK_ADDR(a),Wosize_val(a)));
}

value caml_nios_arr_map(value s, value d) {
  return Val_int(nios_arr_map(BLOCK_ADDR(s), BLOCK_ADDR(d), Wosize_val(s)));
}

value caml_nios_arr_map_cc(value s, value d) {
  return Val_int(nios_arr_map_cc(BLOCK_ADDR(s), BLOCK_ADDR(d), Wosize_val(s)));
}
