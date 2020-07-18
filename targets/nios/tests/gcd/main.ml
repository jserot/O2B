let rec gcd m n =
  (* This algorithm is here deliberatly inefficient ! *)
  if m = n then m
  else if m > n then gcd (m-n) n
  else gcd m (n-m)

let print_int n =
  Nios.Ssd.display_int n;
  Nios.delay 100

let print_timings ts = 
  List.iter
    (fun t -> 
      Nios.Serial.write_int t;
      Nios.Serial.write_string " ")
    ts;
  Nios.Serial.write_string "\n"

let error msg = 
  Nios.Serial.write_string (msg^"\n");
  raise Exit
  
let chrono f =
  let t1 = Nios.Timer.get_us () in
  let r = f 500009 500029  in (* Both arguments are prime numbers *)
  let t2 = Nios.Timer.get_us () in
  r, t2-t1
  
let () =
  if Nios.Timer.init () < 0 then error "Timer init failed";
  while true do
    let r1, t1 = chrono gcd in
    let r2, t2 = chrono Nios.C.gcd in
    let r3, t3 = chrono Nios.Rtl.gcd in
    print_timings [t1;t2;t3];
    print_int ((r2-r1)*10+(r3-r1)) (* should be 0 *)
  done
