Evaluating performance on three implementations of a function mapping (fun x->x+1) over of an array of ints :
- `arr_map` function written in OCaml
- `arr_map` function written in C and called as an external primtive from OCaml
- `arr_map_cc` function implemented in hardware and called as a custom component interfaced to the
           nios uP using the Avalon bus

The two latter implementations are provided by the `arrays` platform. 
