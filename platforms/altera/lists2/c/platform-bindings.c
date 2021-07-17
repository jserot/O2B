value caml_nios_serial_write_char(value val) {
  nios_serial_write_char(Int_val(val));
  return Val_unit;
}

value caml_nios_serial_read_char(value unit) {
  return Val_int(nios_serial_read_char());
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

// Wrappers for the fonctions in the extension library

#ifdef __OCAML__
#define BLOCK_ADDR(v) ((int32_t*)(Op_val(v)))
#include "caml/mlvalues.h"
#include "caml/alloc.h"
#define ALLOC_TUPLE(res,sz) res=caml_alloc_tuple(sz)
#define BLOCK_FIELD Field
#else
#define BLOCK_ADDR(v) ((int32_t *)(Ram_block_val(v)))
#include "vm/gc.h"
#define ALLOC_TUPLE(res,sz) OCamlAlloc(res, sz, 0)
#define BLOCK_FIELD Ram_field
#endif

value caml_nios_list_reduce(value v) {
  int32_t res1, res2;
  value res;
  nios_list_reduce(v, &res1, &res2);
  ALLOC_TUPLE(res,2);
  BLOCK_FIELD(res,0) = Val_int(res1);
  BLOCK_FIELD(res,1) = Val_int(res2);
  return res;
}

value caml_nios_list_reduce_cc(value v) {
  int32_t res1, res2;
  value res;
  nios_list_reduce_cc(v, &res1, &res2);
  ALLOC_TUPLE(res,2);
  BLOCK_FIELD(res,0) = Val_int(res1);
  BLOCK_FIELD(res,1) = Val_int(res2);
  return res;
}
