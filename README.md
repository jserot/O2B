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
- a system configuration (Softcore CPU type and configuration, memory, interfaces, custom components/instructions, ...)
- a _board support package_ (BSP)

Instructions to design and implement new platforms for Altera/Intel boards are given in the
directory `./platforms/quartus/Reeadme.md`.

When targeting a FPGA, the OMicroB compiler is only used to generate the main C file from the
bytecode representation of the program. This C file is then compiled using the Nios-specific C
compiler to generate an `.elf` file which is then uploaded to the softcore processor which has been
instanciated on the FPGA. The latter steps are carried out using the vendor-specific suite of tools
(Quartus2 for Nios processors running on Intel FPGAs).

### To build / run an application

1. Configure 

   - `./configure`

   This will write in `./etc/Makefile.conf` and `./etc/config.ml` several definitions related to
   your local `ocaml` installation and paths.
   
2. Build the `OMicroB` tools. From the top directory run

   - `make omicrob`

   This will build `./omicrob/bin/{bc2c,omicrob}`  and `./omicrob/lib`.
   
3. Go to the selected platform directory and upload the hardware configuration :

   - `cd platforms/quartus/<platform>` 
   - `make hw` 

4. Go to the application directory and first generate the C code

   - `cd apps/<app>` 
   - `make code`

   This will generate the file `main.c` from the source in `main.ml`. 
   This file can be executed on the host machine (without using the target platform physical IOs of
   course !) by running
   
   - `make sim`
   
5. Build, compile and upload the softcore code on the target board

   - `make platform-makefile` 
   - `make build`
   - `make run`
