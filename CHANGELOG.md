# v 0.5 (Dec 7, 2022)

- require OCaml 4.07.1 (because of changes in OCaml 4.14 stdlib)
- added IOs (button, switch, leds, ssds) to platform `dram`)

# v 0.4 (Jun 29, 2022)

- rebased on latest version of OMicroB (supporting OCaml 4.14.0)

# v 0.3 (Jan 31, 2022)

- added platform altera/dram, giving access to the external 64Mb DRAM on the DE10-Lite board
- quartus >= 17.1 is now required

# v 0.2 (Jun 24, 2021)
- revamped directory structure and compilation flow (the `omicrob` directory now only holds the
  platform-independant sources and applications have been moved under their associated platform
  directory). 
- selecting the target platform is no longer part of the `configure` step.

# v 0.1 (Jul 2020)
- first public version

