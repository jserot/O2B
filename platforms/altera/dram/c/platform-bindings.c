value caml_nios_serial_write_char(value val) {
  nios_serial_write_char(Int_val(val));
  return Val_unit;
}

value caml_nios_serial_read_char(value unit) {
  return Val_int(nios_serial_read_char());
}

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

value caml_nios_get_sys_freq(value unit) {
  return Val_int(nios_system_get_sys_freq());
}
