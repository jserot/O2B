open Platform
   
let size = 1024
         
let a = Array.init size (fun i -> 1)

let arr_sum a = Array.fold_left ( + ) 0 a
                 
let print_timings ts = 
  List.iter
    (fun t -> 
      Serial.write_int t;
      Serial.write_string " ")
    ts;
  Serial.write_string "\n"

let chrono f a =
  let t1 = Timer.get_us () in
  let r = f a in
  let t2 = Timer.get_us () in
  r, t2-t1

let print_result r = 
  Serial.write_int r;
  Serial.write_string "\n"

let error msg = 
  Serial.write_string (msg^"\n");
  raise Exit

let () =
  let _ = Sys.sys_id () in 
  if Timer.init () < 0 then error "Timer init failed";
  for i=1 to 4 do
    let r1, t1 = chrono arr_sum a in
    print_result r1;
    let r2, t2 = chrono C.arr_reduce a in
    print_result r2;
    let r3, t3 = chrono Rtl.arr_reduce a in
    print_result r3;
    print_timings [t1;t2;t3]
  done
