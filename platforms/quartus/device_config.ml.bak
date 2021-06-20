(* let arch_args = [] *)

module type NIOSCONFIG = sig
  val cpu : string
  val folder : string
  val modules : string list 
end

module DE10LiteConfig : NIOSCONFIG = struct
  let cpu = "NIOS2"
  let folder = "de10lite"
  let modules = []
end

let default_cxx_options = [ ]

module NiosConfig (P : NIOSCONFIG) : DEVICECONFIG = struct

  let compile_ml_to_byte ~ppx_options ~mlopts ~cxxopts ~local ~trace ~verbose inputs output =
    let libdir = libdir local in
    let vars = [ ("CAMLLIB", libdir) ] in
    let cmd = [ Config.ocamlc ] @ default_ocamlc_options @ ppx_options @ [ "-custom" ] @ mlopts in
    let cmd = if trace > 0 then cmd @ [ "-ccopt"; "-DDEBUG=" ^ string_of_int trace ] else cmd in
    let cmd = cmd @ List.flatten (List.map (fun cxxopt -> [ "-ccopt"; cxxopt ]) cxxopts) in
    let cmd = cmd @
              [ "-I"; Filename.concat libdir "targets/nios" ; Filename.concat libdir "targets/nios/nios.cma";
                "-I"; Filename.concat libdir (Filename.concat "targets/nios" P.folder) ] in

    let append_module_cmo module_name = 
      [ Filename.concat libdir 
          (Filename.concat "targets/nios" 
            (Filename.concat P.folder 
              ((String.uncapitalize_ascii module_name)^".cmo"))) ] in

    let rec add_module_cmo module_name = 
      match module_name with
      | [] -> []
      | head::body -> append_module_cmo (head) @ add_module_cmo body in

    let cmd = cmd @ add_module_cmo P.modules in 
    let cmd = cmd @ [ "-open"; Printf.sprintf "Nios" ] in 
    let append_module_name (module_name) = [ "-open"; Printf.sprintf "%s" module_name ] in 
    let rec add_module_name module_name =
      match module_name with 
      | [] -> []
      | head::body -> append_module_name (head) @ add_module_name body in 
    let cmd = cmd @ add_module_name P.modules in 
    
    let cmd = cmd @ inputs @ [ "-o"; output ] in
    run ~vars ~verbose cmd
end

let get_config name = match name with
  | "de10lite" -> (module NiosConfig(DE10LiteConfig) : DEVICECONFIG)
  | _ -> get_config name

let all_config_names () = [
  "de10lite"
]@(all_config_names ())
