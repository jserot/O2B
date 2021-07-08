let rec gcd m n =
  (* This algorithm is here deliberatly inefficient ! *)
  if m = n then m
  else if m > n then gcd (m-n) n
  else gcd m (n-m)

open Platform
   
let print_int n =
  Ssd.display_int n;
  delay 100

let print_timings ts = 
  List.iter
    (fun t -> 
      Serial.write_int t;
      Serial.write_string " ")
    ts;
  Serial.write_string "\n"

let error msg = 
  Serial.write_string (msg^"\n");
  raise Exit
  
let chrono f =
  let t1 = Timer.get_us () in
  let r = f 500009 500029  in (* Both arguments are prime numbers *)
  let t2 = Timer.get_us () in
  r, t2-t1
  
let () =
  let _ = System.sys_id () in 
  if Timer.init () < 0 then error "Timer init failed";
  while true do
    let r1, t1 = chrono gcd in
    let r2, t2 = chrono C.gcd in
    let r3, t3 = chrono Rtl.gcd_ci in
    let r4, t4 = chrono Rtl.gcd_cc in
    print_timings [t1;t2;t3;t4];
    print_int ((r2-r1)*100+(r3-r1)*10+(r4-r1)) (* should be 0 *)
  done
