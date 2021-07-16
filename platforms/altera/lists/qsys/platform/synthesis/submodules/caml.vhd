library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package caml is
  subtype caml_value is std_logic_vector(31 downto 0); 
  subtype caml_int is signed(30 downto 0);
  function caml_decode_int (x: std_logic_vector(31 downto 0)) return caml_int;
  function caml_encode_int (x: caml_int) return std_logic_vector;
  function caml_int_const (c: integer) return caml_int;
  function caml_is_block (x: std_logic_vector(31 downto 0)) return boolean;
  function caml_heap_addr(heap_base: unsigned(31 downto 0); v: caml_value) return unsigned;
end;

package body caml is

  function caml_decode_int (x: std_logic_vector(31 downto 0)) return caml_int is -- Int_val
  begin
    return signed(x(31 downto 1));  -- bit 0 is caml tag (1)
  end;

  function caml_encode_int (x: caml_int) return std_logic_vector is -- Val_int
  begin
    return std_logic_vector(x) & '1' ;  -- bit 0 is caml tag (1)
  end;
  
  function caml_int_const (c: integer) return caml_int is
  begin
    return to_signed(c, 31);
  end;

  function caml_is_block (x: std_logic_vector(31 downto 0)) return boolean is
  -- vm/values-32.h: dynamic heap pointers   (ram) : 0111 1111 1100 xxxx xxxx xxxx xxxx xx00 (unique)
  -- vm/values-32.h: #define Is_block(x) (((uint8_t) (x) & 0x3) == 0x00 && (uint16_t) ((uint32_t) (x) >> 22) == 0x01FF)
  begin
    return x(1 downto 0) = "00" and x(31 downto 22) = "0111111111"; 
  end;

  function caml_heap_addr(heap_base: unsigned(31 downto 0); v: caml_value) return unsigned is
  -- vm/values-32.h: #define Ram_block_val(x)   ((value *) ((char *) ocaml_ram_heap + (((int32_t) (x) << 12) >> 12)))
  --                 #define Flash_block_val(x) ((value *) ((char *) ocaml_flash_heap + ((int32_t) (x) & 0x000FFFFF)))
  begin
    return heap_base + unsigned(v(19 downto 0));
  end;
  
end;
