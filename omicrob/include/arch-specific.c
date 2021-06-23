#include "arch-specific.h"

#include "platform.c"

/******************************************************************************/
/************************ General operations **********************************/
/******************************************************************************/

void device_init(const char **argv) {
  return;
}

void device_finish() {
  
}

/******************************************************************************/
/********************************** Debug *************************************/
/******************************************************************************/

void debug_blink_error(void) {
  /* TODO */
  return;
}

void debug_blink_uncatched_exception(void) {
  /* TODO */
  return;
  
}

void debug_blink_message(int n) {
  /* TODO */
  return;
}

void debug_blink_pause(void) {
  /* TODO */
  return;
}

#if DEBUG > 0
#define assert(x) do { if (!(x)) debug_blink_error();  } while(0);
#else
#define assert(x)
#endif

void uncaught_exception(value acc) {
  debug_blink_error();
}

/******************************************************************************/

#define TRACE_INSTRUCTION(instr_name)

/******************************************************************************/
/**************************** Memory operations *******************************/
/******************************************************************************/

static inline char do_read_byte(const opcode_t *ocaml_bytecode, int pc) {
  return ocaml_bytecode[pc];
}

static inline uint8_t do_read_byte_from_flash(const void *flash_ptr, int ind) {
  return ((uint8_t *) flash_ptr)[ind];
}

static inline void *do_get_primitive(void *const primitives[], uint8_t prim_ind) {
  return primitives[prim_ind];
}

static inline value do_read_flash_data_1B(const value flash_global_data[], uint8_t glob_ind) {
  return flash_global_data[glob_ind];
}

static inline value do_read_flash_data_2B(const value flash_global_data[], uint8_t glob_ind) {
  return flash_global_data[glob_ind];
}

/******************************************************************************/
/********************************* Format *************************************/
/******************************************************************************/

void format_int64(char *buf, int bufsize, value v) {
  // snprintf(buf, bufsize, "%lld", Int64_val(v));
  // No-oped, because the Intel/ALtera HAL library does not provide snprintf.
  // TO FIX ?
}

#if OCAML_VIRTUAL_ARCH == 64
void format_long(char *buf, int bufsize, value v) {
  snprintf(buf, bufsize, "%lld", Int_val(v));
}
#endif

// The following fonctions are defined just to ensure compatibility with OMicrob framework.
// They do not have a direct interpretation on FPGA platforms

void set_bit(uint8_t reg, uint8_t bit) { }

void clear_bit(uint8_t reg, uint8_t bit) { }

bool read_bit(uint8_t reg, uint8_t bit) { return 0; }

void write_register(uint8_t reg, uint8_t val) { }

uint8_t read_register(uint8_t reg) { return 0; }

