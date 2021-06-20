let rec fact n =
  if n=0 then 1
  else n * fact (n-1)
  
let () =
  let _ = Platform.Sys.sys_id () in
  let r = fact 5 in
  Platform.Serial.write_int r;
  Platform.Ssd.display_int r
