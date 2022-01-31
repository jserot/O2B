open Platform
   
let () =
  let f = System.freq () / 1000000 in
  Serial.write_string "CPU freq = ";
  Serial.write_int f;
  Serial.write_string " MHz\n";
  Serial.write_string "Using 64 MBytes for stack and heap !\n"
