open Platform
   
let manifest () =
  Serial.write_string "Press KEY0 to switch on LED0\n";
  Serial.write_string "Press KEY1 to enter and display text on UART and HEX6\n";
  Serial.write_string "Switch on SW9 to switch on LED9\n"

let get_and_display_text () =
  (* let msg = "HELLO" in *)
  Serial.write_string "Enter text:";
  let msg = Serial.read_string () |> String.uppercase in
  Serial.write_string msg;
  Serial.write_string "\n";
  Ssd.display_string msg
  
let () =
  manifest ();
  while true do
    let b0 = Button.get 0 in
    let b1 = Button.get 1 in
    let sw9 = Switch.get 9 in
    Led.set 0 b0;
    Led.set 9 sw9;
    if b1 then get_and_display_text()
  done
