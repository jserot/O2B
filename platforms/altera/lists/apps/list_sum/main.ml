open Platform

let list_make n = (* warning: tail recursive version required here unless stack_size in increased in ./config.. *)
  let rec mk acc i = 
    if i > n then acc else mk (i::acc) (i+1) in
  mk [] 1 
  
let l1 = [1; 2; 3]
let l2 = list_make 1000
      
let list_sum l = List.fold_left ( + ) 0 l  (* OCaml implementation *)

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
   
let test l = 
    let r1, t1 = chrono list_sum l in
    print_result r1;
    let r2, t2 = chrono C.list_reduce l in
    print_result r2;
    let r3, t3 = chrono Rtl.list_reduce l in
    print_result r3;
    print_timings [t1;t2;t3]

let () =
  if Timer.init () < 0 then error "Timer init failed";
  test l1;
  test l2
