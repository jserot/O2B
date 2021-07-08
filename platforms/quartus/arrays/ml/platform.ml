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

module Ssd =
struct 

  let size = 6

  external display_char : int -> char -> unit = "caml_nios_ssd_display_char" [@@noalloc]

  let resize n s =
      let l = String.length s in
      if l < n then s ^ String.make (n-l) ' '
      else if l > n then String.sub s 0 n
      else s

  let display_string s = 
    s |> resize size |> String.iteri (fun i c -> display_char (size-i-1) c)

  let display_int n = n |> string_of_int |> display_string

end

module Led =
struct
  let size = 10
  external set : int -> bool -> unit = "caml_nios_led_set" [@@noalloc]
end

module Switch =
struct
  let size = 10
  external get : int -> bool = "caml_nios_switch_get" [@@noalloc]
end

module Button =
struct
  let size = 2
  external get : int -> bool = "caml_nios_button_get" [@@noalloc]
end

module Timer =
struct 
    external init : unit -> int = "caml_nios_timer_init" [@@noalloc]
    external get_us : unit -> int = "caml_nios_timer_get_us" [@@noalloc]
    external get_ms : unit -> int = "caml_nios_timer_get_ms" [@@noalloc]
end

module Sys =
struct
    external sys_id : unit -> int = "caml_nios_get_sys_id" [@@noalloc]
end

module C =
struct
  external arr_reduce : int array -> int = "caml_nios_arr_reduce" [@@noalloc]
  external arr_map : int array -> int array -> unit = "caml_nios_arr_map" [@@noalloc]
end

module Rtl =
struct
  external arr_reduce : int array -> int = "caml_nios_arr_reduce_cc" [@@noalloc]
  external arr_map : int array -> int array -> unit = "caml_nios_arr_map_cc" [@@noalloc]
end
