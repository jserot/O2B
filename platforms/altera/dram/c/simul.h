void nios_serial_write_char(char c);
char nios_serial_read_char();

void nios_ssd_display_char(int i, char c);

void nios_led_set(int i, bool b);

bool nios_switch_get(int i);

bool nios_button_get(int i);

int nios_timer_init();
int nios_timer_get_us();
int nios_timer_get_ms();

int nios_system_get_sys_freq();
