let manifest () =
  Nios.Serial.write_string "Press KEY0 to switch on LED0\n";
  Nios.Serial.write_string "Press KEY1 to enter and display text on UART and HEX6\n";
  Nios.Serial.write_string "Switch on SW9 to switch on LED9\n"

let get_and_display_text () =
  (* let msg = "HELLO" in *)
  Nios.Serial.write_string "Enter text:";
  let msg = Nios.Serial.read_string () |> String.uppercase in
  Nios.Serial.write_string msg;
  Nios.Serial.write_string "\n";
  Nios.Ssd.display_string msg
  
let () =
  manifest ();
  while true do
    let b0 = Nios.Button.get 0 in
    let b1 = Nios.Button.get 1 in
    let sw9 = Nios.Switch.get 9 in
    Nios.Led.set 0 b0;
    Nios.Led.set 9 sw9;
    if b1 then get_and_display_text()
  done
