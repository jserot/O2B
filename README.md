# OCaml on Microcontroller and FPGA Boards

![OCaml](https://img.shields.io/badge/OCaml-4.07-orange?logo=OCaml&logoColor=white)


OMicroB is an OCaml virtual machine dedicated at running OCaml programs on embedded devices such as
- micro-controllers with very limited resources such as AVR Atmega32u4 microcontrollers (2.5 ko of RAM).
- micro-processors implemented as soft-cores on FPGAs (such as the Nios2 processor on Intel/Altera
  FPGAs)

This tools, steming from the works of OCaPIC (https://github.com/bvaugon/ocapic) consists of a generic virtual machine, which can be ported on various architectures.

OMicroB performs multiple static analysis passes in order to reduce the generated final executable.

## Published version

An article describing our generic virtual machine approach has been published in ERTS 2018 :

[A Generic Virtual Machine Approach for Programming Microcontrollers: the OMicroB Project (S. Varoumas, B. Vaugon, E. Chailloux)](http://hal.upmc.fr/hal-01705825/document)

## Requirements

- OPAM2 + OCaml (>= 4.07)
  (OCaml versions prior to 4.07 are not supported at the moment because of changes in the bytecode instructions and in the structure of the standard library of the language since v. 4.07)
- obytelib (on OPAM)
- ocamlclean (on OPAM)
- ocamlbuild (on OPAM)
- gcc (for simulation)
- avr-gcc, avr-libc (for AVR microcontrollers)
- avrdude (for flashing to an AVR)
- xc32 (for PIC32 microcontrollers)
- pic32prog (for fashing to a PIC32)
- QuartusII (>= 15.1) suite of tools for programming FPGAs

## Using OMicroB on a micro-controller target

OMicroB currently supports AVR and PIC32 microcontrollers. 

### Installing

The installation process requires to specify which type of microcontrollers OMicroB should be
compiled for.

For this, the name of the target architecture must be passed to the `configure` script. The
configuration script will check that you do have the right dependencies installed for the
architectures you selected.

Example 
```console
./configure -target avr && make && make install
```

### Compiling an OCaml program

In order to compile an OCaml file, run

```
omicrob <file.ml> -device $DEVICE
```

that will generate a ```<file.hex>``` executable. 
The ```omicrob -list-devices``` command lists possible values for ```$DEVICE```. 
Note that available devices vary depending on whether OMicroB is compiled for AVR or PIC32. 

(The ```omicrob -help``` command will display the various available options, such as setting the stack size, the garbage collector algorithm, etc)

### Flashing on a microcontroller

```console
omicrob -flash <file.hex> -device $DEVICE
```

### Simulator

OMicroB comes with a circuit simulator, for example running

```console
make simul
```
in the ```tests/snake-mustard``` folder will simulate an [Arduboy]([https://arduboy.com) device on your computer, running the Snake game described in this folder.

## Using OMicroB on a FPGA target

OMicroB currently supports Nios2 platforms on Intel/Altera FPGAs.

A _platform_ is a combination of 
- a board (device type + peripherals)
- a Nios2 CPU configuration (memory, interfaces, custom instructions, ...)
- a _board support package_ (BSP)

Predefined platforms are provided in the distribution.  Instructions to design and implement new
platforms are given in the directory `targets/nios/platforms`.

### Installing

In the current version, the installation process requires to specify the target platform OMicroB should be
compiled for.

For this, the name of the target platform must be passed, along with the `nios` architecture, to the `configure` script. 

Example 
```console
./configure -target nios-basic && make && make install
```

### Compiling and running program

When targeting a FPGA, the OMicroB compiler is only used to generate the main C file from the
bytecode representation of the program. This C file is then compiled using the Nios-specific C
compiler to generate an `.elf` file which is then uploaded to the Nios processor which has been
instanciated on the FPGA. The latter steps are carried out using the vendor-specific suite of tools
(Quartus2 for Nios processors running on Intel FPGAs).

See the file `targets/nios/Readme.md` for details.
