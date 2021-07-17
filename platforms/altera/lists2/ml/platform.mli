val delay : int -> unit
val millis : unit -> int

module Serial : (* JTAG-UART *)
  sig
    external write_char : char -> unit = "caml_nios_serial_write_char" [@@noalloc]
    val write_int : int -> unit
    val write_string : string -> unit
    (* external write_string : string -> unit = "caml_nios_serial_write_string" [@@noalloc] *)
    (* external write_int : int -> unit = "caml_nios_serial_write_int" [@@noalloc] *)
    external read_char : unit -> char = "caml_nios_serial_read_char" [@@noalloc]
    val read_int : unit -> int
    val read_string : ?eol:char -> unit -> string
    (* external read_string : unit -> string = "caml_nios_serial_read_string" [@@noalloc] *)
  end

module Timer : (* High-tes timer using the HAL timestamp driver *)
sig 
    external init : unit -> int = "caml_nios_timer_init" [@@noalloc]
      (* Returns [-1] if the corresponding device is not available *)
    external get_us : unit -> int = "caml_nios_timer_get_us" [@@noalloc]
    (* Returns the number of elapsed us.
       Warning : this may overflow for long running programs *)
    external get_ms : unit -> int = "caml_nios_timer_get_ms" [@@noalloc]
    (* Returns the number of elapsed ms *)
end

module C : (* Primitives implemented in C *)
sig
  external list_reduce : int list -> int * int = "caml_nios_list_reduce"
  (* First result is the accumulated value, second the list length *)
  (* The [reduce] is not explicitely given as argument. It will be hardcoded in the implementation. *)
end

module Rtl : (* Primitives implemented as RT-level custom instruction or component *)
sig
  external list_reduce : int list -> int * int = "caml_nios_list_reduce_cc"
  (* First result is the accumulated value, second the list length *)
  (* The [reduce] is not explicitely given as argument. It will be hardcoded in the implementation. *)
end
