let get_text () =
  Nios.Serial.write_string "Enter text:";
  Nios.Serial.read_string () |> String.uppercase_ascii
  
let rotate s =
  let l = String.length s in
  let r = Bytes.create l in
  for i = 1 to l-1 do
    Bytes.set r i s.[i-1]
  done;
  Bytes.set r 0 s.[l-1];
  Bytes.to_string r
  
let () =
  (* let txt = ref (get_text ()) in *)
  let txt = ref "ABCDEF" in
  let led = ref true in
  Nios.Ssd.display_string !txt;
  Nios.Led.set 9 !led;
  while true do
    txt := rotate !txt;
    led := not !led;
    Nios.delay 500;
    Nios.Ssd.display_string !txt;
    Nios.Led.set 9 !led
  done
