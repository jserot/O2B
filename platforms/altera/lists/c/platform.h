void nios_serial_write_char(char c);
char nios_serial_read_char();

int nios_timer_init();
int nios_timer_get_us();
int nios_timer_get_ms();

// Extended functions

int nios_list_reduce(uint32_t caml_val);
int nios_list_reduce_cc(uint32_t caml_val);
