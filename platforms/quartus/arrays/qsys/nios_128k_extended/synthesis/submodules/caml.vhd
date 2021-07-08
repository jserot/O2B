library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package caml is
  subtype caml_int is signed(30 downto 0); -- 31 bits only
  function caml_decode_int (x: std_logic_vector(31 downto 0)) return caml_int;
  function caml_encode_int (x: caml_int) return std_logic_vector;
  function caml_int_const (c: integer) return caml_int;
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
  
end;
