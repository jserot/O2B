let rev l =
  let rec h acc l = match l with
      [] -> acc
    | x::xs -> h (x::acc) xs in
  h [] l

let interval min max =
  let rec h acc i =
    if i > max then acc else h (i::acc) (i+1) in
  rev (h [] min)

let filter p l =
  let rec h acc l = match l with
    [] -> acc
    | x::xs -> if p x then h (x::acc) xs else h acc xs in
  rev (h [] l)

let remove_multiples_of n =
  filter (fun m -> if (m mod n) = 0 then false else true)

let rev_prepend l1 l2 =
  let rec h acc l =
  match l with
    [] -> acc
  | x::xs -> h (x::acc) xs in
  h l2 l1

let sieve max =
  let rec h acc l = match l with
     [] -> acc
  | n::ns ->
      if n*n > max then rev_prepend acc l else h (n::acc) (remove_multiples_of n ns)
  in
    h [] (interval 2 max)

let print_int n =
  Nios.Ssd.display_int n;
  Nios.delay 100

let () =
  while true do
    let primes = sieve 100 in
    List.iter print_int primes
  done
