open Platform
   
let get_text () =
  Serial.write_string "Enter text:";
  Serial.read_string () |> String.uppercase_ascii
  
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
  Ssd.display_string !txt;
  Led.set 9 !led;
  while true do
    txt := rotate !txt;
    led := not !led;
    delay 500;
    Ssd.display_string !txt;
    Led.set 9 !led
  done
