open Platform
   
let () =
  let f = System.freq () / 1000000 in
  Serial.write_string "CPU freq = ";
  Serial.write_int f;
  Serial.write_string " MHz\n";
  Serial.write_string "Using 64 MBytes for stack and heap !\n";
  Ssd.display_string "64";
  while true do
    for i = 0 to 1 do
      Led.set i (Button.get i)
    done;
    for i = 2 to 9 do
      Led.set i (Switch.get i)
    done
  done
    
