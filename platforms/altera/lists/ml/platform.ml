external delay : int -> unit = "caml_delay" [@@noalloc]
external millis : unit -> int = "caml_millis" [@@noalloc]

module Serial = struct
  external write_char : char -> unit = "caml_nios_serial_write_char" [@@noalloc]
  external read_char : unit -> char = "caml_nios_serial_read_char" [@@noalloc]

  (* external write_int : int -> unit = "caml_nios_serial_write_int" [@@noalloc] *)
  (* external write_string : string -> unit = "caml_nios_serial_write_string" [@@noalloc] *)
  (* external read_string : unit -> string = "caml_nios_serial_read_string" [@@noalloc] *)

  let write_string s = String.iter write_char s

  let read_string ?(eol='\n') () =
    let max_length = 32 in
    let s = Bytes.create max_length in
    let rec read i =
      let c = read_char () in
      if c <> eol && i < max_length then begin
          Bytes.set s i c;
          read (i+1)
        end
      else
        s in
    Bytes.to_string (read 0)

  let int_of_string s =
    let rec scan i acc =
      if i < String.length s then 
        let c = String.get s i in
        if c >= '0' && c <= '9' then scan (i+1) (acc*10+Char.code c-Char.code '0')
        else acc
      else acc in
    scan 0 0

  let read_int () = int_of_string (read_string ())

  let write_int n = write_string (string_of_int n)

end

module Timer =
struct 
    external init : unit -> int = "caml_nios_timer_init" [@@noalloc]
    external get_us : unit -> int = "caml_nios_timer_get_us" [@@noalloc]
    external get_ms : unit -> int = "caml_nios_timer_get_ms" [@@noalloc]
end

module C = (* Primitives implemented in C *)
struct
  external list_reduce : int list -> int = "caml_nios_list_reduce" [@@noalloc]
  (* The [reduce] is not explicitely given as argument. It will be hardcoded in the implementation. *)
end

module Rtl = (* Primitives implemented as RT-level custom instruction or component *)
struct
  external list_reduce : int list -> int = "caml_nios_list_reduce_cc" [@@noalloc]
  (* The [reduce] is not explicitely given as argument. It will be hardcoded in the implementation. *)
end
