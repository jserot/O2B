let arr_sum a =
  let sum = ref 0 in  (* Imperative implementation *)
  for i=0 to Array.length a - 1 do
    sum := !sum + a.(i)
  done;
  !sum
  
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
  
let a0 = Array.init 1024 (fun i -> 1)
                 
let chrono f =
  let t1 = Timer.get_us () in
  let r = f a0 in
  let t2 = Timer.get_us () in
  r, t2-t1
  
let () =
  let _ = Sys.sys_id () in 
  if Timer.init () < 0 then error "Timer init failed";
  for i=1 to 4 do
    let r1, t1 = chrono arr_sum in
    let r2, t2 = chrono C.arr_sum in
    let r3, t3 = chrono Rtl.arr_sum in
    (* let r2, t2 = 0, 0 in
     * let r3, t3 = 0, 0 in *)
    print_timings [t1;t2;t3];
    (* print_int ((r2-r1)*10+(r3-r1)) (\* should be 0 *\) *)
    print_int (((r1 mod 100)*10000+(r2 mod 100)*100+(r3 mod 100)))
  done
