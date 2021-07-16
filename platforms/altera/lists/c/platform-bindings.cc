# 1 "platform-bindings.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "platform-bindings.c"
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
# 30 "platform-bindings.c"
value caml_nios_list_reduce(value v) {
  inspect_value((int32_t *)v);
  return Val_int(nios_list_reduce(v));
}

value caml_nios_list_reduce_cc(value v) {
  inspect_value((int32_t *)v);

  return nios_list_reduce_cc(v);
}
# 82 "platform-bindings.c"
void margin (int n) { while (n-- > 0) alt_printf("%c", '.'); return; }

void print_block (value v, int m)


{
  int size, i;
  int32_t* blk_addr;
  if ( ! Is_block(v))
    { margin(m); alt_printf("[%x] is immediate value (%x)", v, Int_val(v)); return; };
  margin(m); alt_printf("v=%x\n", v);
  margin(m); alt_printf("Hd_val(%x)=%x\n", v, Hd_val(v));
  margin(m); alt_printf("Field(%x,-1)=%x\n", v, Field(v,-1));
  margin(m); alt_printf("Ram_block_val(%x)=%x\n", v, Ram_block_val(v));
  blk_addr = Ram_block_val(v);
  margin(m); alt_printf("%x[-1]=%x\n", blk_addr, *(blk_addr-1));
  margin(m); alt_printf("[%x] is memory block: addr=%x, raw content={%x,%x,%x}, size=%x  -  ", v, blk_addr, blk_addr[-1], blk_addr[0], blk_addr[1], size=Wosize_val(v));
  switch (Tag_val(v))
   {
    case Closure_tag :
        alt_printf("closure with %x free variables\n", size-1);
        margin(m+4); printf("code pointer: %x\n",Codeptr_val(v)) ;
        for (i=1;i<size;i++) print_block(Field(v,i), m+4);
        break;
    case String_tag :
        alt_printf("string\n");

        break;
# 118 "platform-bindings.c"
    case Abstract_tag : alt_printf("abstract type\n"); break;

    default:
        if (Tag_val(v)>=No_scan_tag) { alt_printf("unknown tag"); break; };
        alt_printf("structured block (tag=%x):\n",Tag_val(v));
        for (i=0;i<size;i++) print_block(Field(v,i),m+4);
   }
  return ;
}


int inspect_value(value v)
{
  print_block((value)v,4);
  return 0;
}
