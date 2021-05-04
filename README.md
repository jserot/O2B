# OCaml on FPGA Boards

O2B is a specific port of the [OMicroB](https://github.com/stevenvar/omicrob) OCaml virtual machine
dedicated to run on micro-processors implemented as soft-cores on FPGAs (such as the Nios2 processor
on Intel/Altera FPGAs)

## Requirements

For compiling the virtual machine :

- OPAM2 + OCaml (>= 4.07 & <  4.08)
  (OCaml versions prior to 4.07 are not supported at the moment because of changes in the bytecode instructions and in the structure of the standard library of the language since v. 4.07)
- obytelib (on OPAM)
- ocamlclean (on OPAM)
- ocamlbuild (on OPAM)
- gcc (for simulation)

For configuring and programming FPGAs :

- QuartusII (>= 15.1) suite of tools (to be downloaded from [Intel FPGA website](https://fpgasoftware.intel.com)). 

O2B currently supports Nios2 platforms on Intel/Altera FPGAs.

## Using 

Predefined hardware platforms are provided in the distribution.

A _platform_ is a combination of 
- a board (device type + peripherals)
- a Nios2 CPU configuration (memory, interfaces, custom instructions, ...)
- a _board support package_ (BSP)

Instructions to design and implement new platforms are given in the directory `targets/nios/platforms`.

When targeting a FPGA, the OMicroB compiler is only used to generate the main C file from the
bytecode representation of the program. This C file is then compiled using the Nios-specific C
compiler to generate an `.elf` file which is then uploaded to the Nios processor which has been
instanciated on the FPGA. The latter steps are carried out using the vendor-specific suite of tools
(Quartus2 for Nios processors running on Intel FPGAs).

### To build / run an application

1. Choose or write a specific platform (see `targets/nios/platforms/Readme.md`)

2. Build the `OMicroB` support for this platform. From the top directory run

   - `./configure -target nios-<platform>` 
   
   where `<platform>` is the name of the selected platform (currently, either `basic` or `extended`)

   - `make clean`
   - `make`

3. Go to the selected platform directory and upload the hardware configuration :

   - `cd targets/nios/platforms/<platform>` 
   - `make bsp`
   - `make hw` 

4. Go to the application directory, build and upload the software

   - `cd targets/nios/tests/<app>` 
   - `make nios-makefile` 
   - `make` 
   - `make run`

When changing the application but not the platform, only step 4 needs to be re-taken.

When changing the platform, steps 2-3 have to be retaken.

The name of the required platform for a given application is given at the top of `<app>/Makefile`.
