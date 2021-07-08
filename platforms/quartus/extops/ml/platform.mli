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

module Ssd :  (* HEX0-HEX5 *)
  sig
    val size: int
    external display_char : int -> char -> unit = "caml_nios_ssd_display_char" [@@noalloc]
    val display_string : string -> unit
    val display_int : int -> unit
  end

module Led : (* LED0-LED9 *)
sig
    val size: int
    external set : int -> bool -> unit = "caml_nios_led_set" [@@noalloc]
end

module Switch : (* SW0-SW9 *)
sig
    val size: int
    external get : int -> bool = "caml_nios_switch_get" [@@noalloc]
end

module Button : (* PB0-PB1 *)
sig
    val size: int
    external get : int -> bool = "caml_nios_button_get" [@@noalloc]
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

module System : (* System description *)
sig
    external sys_id : unit -> int = "caml_nios_get_sys_id" [@@noalloc]
end

module C : (* Primitives implemented in C *)
sig
  external gcd : int -> int -> int = "caml_nios_gcd" [@@noalloc]
end

module Rtl : (* Primitives implemented as RT-level custom instruction and component *)
sig
  external gcd_ci : int -> int -> int = "caml_nios_gcd_ci" [@@noalloc]
  external gcd_cc : int -> int -> int = "caml_nios_gcd_cc" [@@noalloc]
end
