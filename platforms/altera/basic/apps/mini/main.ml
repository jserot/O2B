let rec fact n =
  if n=0 then 1
  else n * fact (n-1)
  
open Platform
   
let () =
  let _ = Sys.sys_id () in
  let r = fact 5 in
  Serial.write_int r;
  Ssd.display_int r
