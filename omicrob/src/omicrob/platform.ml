let default_ocamlc_options = [ "-g"; "-w"; "A"; "-safe-string"; "-strict-sequence"; "-strict-formats"; "-ccopt"; "-D__OCAML__" ]

let platform_module_name = "platform"

let compile_ml_to_byte ~ppx_options ~mlopts ~cxxopts ~local ~trace ~verbose ~platform_dir inputs output =
    let libdir = Tools.libdir local in
    let mldir = Tools.filename_concat [ platform_dir; "ml" ] in
    let bytedir = Tools.filename_concat [ platform_dir; "c" ] in
    let vars = [ ("CAMLLIB", libdir) ] in
    let cmd = [ Config.ocamlc ] @ default_ocamlc_options @ ppx_options @ [ "-custom" ] @ mlopts in
    let cmd = if trace > 0 then cmd @ [ "-ccopt"; "-DDEBUG=" ^ string_of_int trace ] else cmd in
    let cmd = cmd @ List.flatten (List.map (fun cxxopt -> [ "-ccopt"; cxxopt ]) cxxopts) in
    let cmd = cmd @ [ "-I"; bytedir; "-I"; mldir; Filename.concat mldir "platform.cma" ] in
    (* let cmd = cmd @ [ "-open"; String.capitalize_ascii platform_module_name ] in  *)
    let cmd = cmd @ inputs @ [ "-o"; output ] in
    Tools.run ~vars ~verbose cmd

