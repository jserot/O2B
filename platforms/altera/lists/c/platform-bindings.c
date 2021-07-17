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
#else
#define BLOCK_ADDR(v) ((int32_t *)(Ram_block_val(v)))
#endif

value caml_nios_list_reduce(value v) {
  // inspect_value((int32_t *)v);
  return Val_int(nios_list_reduce(v));
}

value caml_nios_list_reduce_cc(value v) {
  // inspect_value((int32_t *)v);
  return Val_int(nios_list_reduce_cc(v));
}

// The following functions are for debug only

#ifdef __OCAML__
#include <stdio.h>

void margin (int n) { while (n-- > 0) printf(".");  return; }

void print_block (value v, int m) // Taken from "Developing applications with OCaml, chapter 12
{
  int size, i;
  margin(m);
  printf("decoding caml value %x\n", (unsigned int)v);
  if (Is_long(v))
    { printf("immediate value (%ld)\n", Long_val(v));  return; };
  printf ("memory block: addr=%p size=%d  -  ", BLOCK_ADDR(v), size=Wosize_val(v));
  switch (Tag_val(v))
   {
    case Closure_tag :
        printf("closure with %d free variables\n", size-1);
        margin(m+4); printf("code pointer: %p\n",Code_val(v)) ;
        for (i=1;i<size;i++)  print_block(Field(v,i), m+4);
        break;
    case String_tag :
        printf("string: %s (%s)\n", String_val(v),(char *) v);
        break;
    case Double_tag:
        printf("float: %g\n", Double_val(v));
        break;
    case Double_array_tag :
        printf ("float array: ");
        for (i=0;i<size/Double_wosize;i++)  printf("  %g", Double_field(v,i));
        printf("\n");
        break;
    case Abstract_tag : printf("abstract type\n"); break;
      // case Final_tag : printf("abstract finalized type\n"); break;
    default:
        if (Tag_val(v)>=No_scan_tag) { printf("unknown tag"); break; };
        printf("structured block (tag=%d):\n",Tag_val(v));
        for (i=0;i<size;i++)  print_block(Field(v,i),m+4);
   }
  return ;
}
#else
void margin (int n) { while (n-- > 0) alt_printf("%c", '.'); return; }

void print_block (value v, int m) // For debug only
// Adapted from "Developing applications with OCaml, chapter 12
// with informations taken from _build/vm/values-32.h
{
  int size, i;
  int32_t* blk_addr;
  margin(m);
  if ( ! Is_block(v))
    { alt_printf("[%x] is immediate value (%x)\n", v, Int_val(v));  return; };
  blk_addr = Ram_block_val(v); 
  alt_printf("[%x] is memory block: addr=%x, raw content={%x,%x,%x}, size=%x  -  ", v, blk_addr, blk_addr[-1], blk_addr[0], blk_addr[1], size=Wosize_val(v));
  switch (Tag_val(v))
   {
    case Closure_tag :
        alt_printf("closure with %x free variables\n", size-1);
        margin(m+4); printf("code pointer: %x\n", (unsigned int)(Codeptr_val(v))) ;
        for (i=1;i<size;i++)  print_block(Field(v,i), m+4);
        break;
    case String_tag :
        alt_printf("string\n");
        // alt_printf("string: %s (%s)\n", String_val(v),(char *) v);
        break;
    /* case Double_tag: */
    /*     alt_printf("float"); */
    /*     break; */
    /* case Double_array_tag : */
    /*     alt_printf ("float array\n"); */
    /*     //for (i=0;i<size/Double_wosize;i++)  printf("  %g", Double_field(v,i)); */
    /*     //printf("\n"); */
    /*     break; */
    case Abstract_tag : alt_printf("abstract type\n"); break;
      // case Final_tag : printf("abstract finalized type\n"); break;
    default:
        if (Tag_val(v)>=No_scan_tag) { alt_printf("unknown tag"); break; };
        alt_printf("structured block (tag=%x):\n",Tag_val(v));
        for (i=0;i<size;i++)  print_block(Field(v,i),m+4);
   }
  return ;
}
#endif

int inspect_value(value v)
{
  print_block((value)v,4);
  return 0;
}
