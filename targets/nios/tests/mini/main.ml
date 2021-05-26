let rec fact n =
  if n=0 then 1
  else n * fact (n-1)
  
let () =
  let _ = Nios.Sys.sys_id () in
  let r = fact 5 in
  Nios.Serial.write_int r;
  Nios.Ssd.display_int r
