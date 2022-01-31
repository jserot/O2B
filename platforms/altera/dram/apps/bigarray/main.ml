open Platform

let size = 32768 (* Adjust [heap_size] in ./config accordingly and (re)run ./make_makefiles *)
         
let a = Array.init size (fun _ -> 1)

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
  if Timer.init () < 0 then error "Timer init failed";
  let f = System.freq () / 1000000 in
  Serial.write_string "CPU freq = ";
  Serial.write_int f;
  Serial.write_string " MHz\n";
  Serial.write_string "Using 64 MBytes for stack and heap !\n";
  let r1, t1 = chrono arr_sum a in
  print_result r1;
  print_timings [t1]
