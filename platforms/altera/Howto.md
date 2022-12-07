# Rebuild and test a new platform

1. Edit the SOPC description
- under `QSys` add IPs, etc.. (from platform root dir : `make sopc-edit`)
- regenerate the HDL files (`.vhd` or `.v`) (this will also regenerate `./qsys/platform/{qsys,sopcinfo}`)

2. Rebuild the HW
- if the SOPC interface has been modified (connexions to external devices such as SDRAM, ...), edit
  the HW top-level file (`hw/top.vhd` or `hw/top.v`)
- from platform root dir : `make hw-build` (this will generate `./hw/output_files/top.sof`)

3. Reload the HW on the target board
- from platform root dir : `make hw` 

4. Rebuild the BSP files
- from platform root dir : `make bsp-files` (this will required because the `.sopcinfo` file has
  been updated)

5. Rebuild the `omicrob` support (required after cloning or if the new platform introduces new ext
  fns, in C or as custom components)
- from platform root dir : `make omicrob` 

6. Rebuild and launch the softare
- from `./apps/<xxx>` : `make_makefiles; make build`
- from `./apps/<xxx>` : `make run`
