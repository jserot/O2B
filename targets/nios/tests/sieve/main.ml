let succ x = x + 1

let rec interval min max =
  if min > max then [] else min :: interval (succ min) max

let rec filter p l = match l with
    []   -> []
  | (a::r) -> if p a then a :: filter p r else filter p r

let remove_multiples_of n =
  filter (fun m -> if (m mod n) = 0 then false else true)

let sieve max =
  let rec filter_again = function
     [] -> []
  | n::r as l ->
      if n*n > max then l else n :: filter_again (remove_multiples_of n r)
  in
    filter_again (interval 2 max)

let print_int n =
  Nios.Ssd.display_int n;
  Nios.delay 100

let print_timing u t1 t2 = 
  Nios.Serial.write_string "Elapsed time: ";
  Nios.Serial.write_int (t2-t1);
  Nios.Serial.write_string (" " ^ u ^ "\n")

let () =
  let r = Nios.Timer.init () in
  if r < 0 then
    Nios.Serial.write_string "Timer init failed\n"
  else
    begin
      Nios.Serial.write_string "Starting\n";
      while true do
        let t1 = Nios.Timer.get_us () in
        let primes = sieve 50 in
        let t2 = Nios.Timer.get_us () in
        print_timing "us" t1 t2;
        List.iter print_int primes
      done
    end
