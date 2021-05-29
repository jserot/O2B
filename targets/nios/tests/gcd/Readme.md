Evaluating performance on three implementations of a (naive) GCD algorithm :
- `gcd` function written in OCaml
- `gcd` function written in C and called as an external primtive from OCaml
- `gcd_ci` function implemented in hardware and called as a custom instruction of the Nios2 uP
- `gcd_cc` function implemented in hardware and called as a custom component interfaced to the
           nios uP using the Avalon bus

The three latter implementations are provided by the `extended` Nios platform. 
