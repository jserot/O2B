let arr_map src dst =
  for i=0 to Array.length src - 1 do
    Array.set dst i (Array.get src i + 1)
  done
  
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

let print_array m a = 
  Array.iteri
    (fun i v -> 
      if i < m || i >= Array.length a - m then
        begin
          Serial.write_int v;
          Serial.write_string " "
        end)
    a;
  Serial.write_string "\n"

let error msg = 
  Serial.write_string (msg^"\n");
  raise Exit
  
let size = 1000 
let src = Array.init size (fun i -> i)
let dst = Array.make size 0
                 
let chrono f =
  let t1 = Timer.get_us () in
  let _ = f src dst in
  let t2 = Timer.get_us () in
  t2-t1   
  
let () =
  let _ = Sys.sys_id () in 
  if Timer.init () < 0 then error "Timer init failed";
  print_array 4 src;
  for i=1 to 1 do
    let t1 = chrono arr_map in
    print_array 4 dst;
    Array.fill dst 0 (Array.length dst - 1) 0; (* erase previous result *)
    let t2 = chrono C.arr_map in
    (* let t2 = 0 in *)
    print_array 4 dst;
    Array.fill dst 0 (Array.length dst - 1) 0; (* erase previous result *)
    let t3 = chrono Rtl.arr_map in
    (* let t3 = 0 in *)
    print_array 4 dst;
    print_timings [t1;t2;t3]
  done
