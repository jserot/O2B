open Tools

(** Per-architecture additional command line arguments *)
let arch_args = []

(******************************************************************************)

(** Signatures for a device's configuration *)
module type DEVICECONFIG = sig
  (** Compile a .ml to a .byte *)
  val compile_ml_to_byte : ppx_options:string list -> mlopts:string list ->
    cxxopts:string list -> local:bool -> trace:int -> verbose:bool ->
    string list -> string -> unit
end

let default_ocamlc_options = [ "-g"; "-w"; "A"; "-safe-string"; "-strict-sequence"; "-strict-formats"; "-ccopt"; "-D__OCAML__" ]

(** Default config, when no device is selected *)
module DefaultConfig : DEVICECONFIG = struct
  let compile_ml_to_byte ~ppx_options ~mlopts ~cxxopts ~local ~trace ~verbose
      inputs output =
    let vars = [ ("CAMLLIB", Tools.libdir local) ] in
    let cmd = [ Config.ocamlc ] @ default_ocamlc_options @ ppx_options @ [ "-custom" ] @ mlopts in
    let cmd = if trace > 0 then cmd @ [ "-ccopt"; "-DDEBUG=" ^ string_of_int trace ] else cmd in
    let cmd = cmd @ List.flatten (List.map (fun cxxopt -> [ "-ccopt"; cxxopt ]) cxxopts) in
    let cmd = cmd @ inputs @ [ "-o"; output ] in
    run ~vars ~verbose cmd
end

(******************************************************************************)

(** Get the configuration for a given device name *)
let get_config _ = invalid_arg "choose_config"

(** Get the names of all configs *)
let all_config_names () = []

(******************************************************************************)
(******************************************************************************)
(******************************************************************************)
