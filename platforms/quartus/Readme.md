## DESCRIPTION

This directory contains several predefined _platforms_ for the Quartus-supported hardware.

A _platform_ is a combination of 
- a board (device type + peripherals)
- a system configuration (Nios CPU type and configuration, memory, interfaces, custom components/instructions, ...)
- a _board support package_ (BSP)

The board description ("hardware") is in subdirectory `hw`. 
The system configuration ("SoPC") is in subdirectory `qsys`. 
The BSP description is in subdirectory `bsp`.
The source code of custom components or instructions, when present, is is subdirectory `rtl`.

The interface to the OMicroB framework is located in subdirectories `ml`, `prims` and `simul`.

The system configuration of a platform includes a unique "system ID" which can be edited using the
`qsys` tools. This system ID can be retrieved and checked by an application uploaded on the hosted
Nios CPU to ensure that it is running on a compatible system (this will prevent, for example,
applications needing to read a given peripheral to be run on a system configuration not including
this peripheral).  Pre-defined platforms have a system ID ranging from 0x100 to 0x1FF. This system
ID is specified in the `platform-desc.txt` file given with each provided platform.

## USING PLATFORMS

To use the provided platforms, edit them or build new ones, the Intel *Quartus* suite of tools must be installed with
- the `nios2eds` tool chain 
- support for the target FPGA device

The platforms provided here 
- have been developed with [Quartus Prime v 15.1 Lite Edition](https://fpgasoftware.intel.com/15.1/?edition=lite&platform=linux) under LinuxMint 4.15.0.
- target a [DE10-Lite](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=1021)
  board, equiped with a Max10 M50DAF484 FPGA. 

### Configuring hardware

To configure the hardware

1. connect the board and check that the corresponding device (USB-Blaster) is recognized and
   registered

2. go the platform top directory, open a terminal and run the `nios2_command_shell` script (located
   in `<altera>/nios2eds` directory, where `<altera>` is the root of the Intel/Altera software
   installation)

3. type : `make hw` 

Configuring the HW can also be carried out using the _Quartus_ tool. For this :

1. launch `Quartus` (either from the application menu or by typing `make hw-edit` in the opened
   terminal)
2. open the `Programmer` tab
3. check that the USB-Blaster device is detected 
4. Click  `Auto Detect` to scan the JTAG chain
5. Click `Change File` and enter `hw/output_files/top.sof`
6. Program the device by clicking on `Start` button

#### Troubleshooting 

Some problems have been reported when configuring hardware using the USB-Blaster interface under
Linux. The symptoms are :
- no response from the `nios2-configure-sof` command (issued when typing `make hw-conf`)
- when clicking the `Auto Detect` from  the Quartus `Programmer` tab, a popup window saying `Unable to scan device
chain`.

To diagnose / fix the problem
1. open a terminal
2. type `<altera>/quartus/bin/jtagconfig` (where `<altera>` is, again the root of the Intel/Altera software
   installation)
   The answer should be : `USB-Blaster [id]` followed by a device ID
   In case of problem, the command will hang for a while and finally display `Unable to read device
   chain - JTAG chain broken`
3. re-issue the same command as root, typing `sudo <altera>/quartus/bin/jtagconfig` 
   If the problem disappear, you have to fix the permissions on some device files, as detailed
   [here](https://www-acc.gsi.de/wiki/Timing/QuartusInstallUbuntu1404).
4. if the problem persists, try this
   - `sudo killall jtagd`
   - ``sudo <altera>/quartus/bin/jtagconfig` 
5. Some extra links that may help to fix the problem :
   - [https://ecen3350.rocks/static/usb-blaster.pdf]
   - [https://ubuntuforums.org/showthread.php?t=1441742]

### Editing the Nios2 configuration

This is done using the `QSys` tool.

1. From the platform top directory, type `make sopc-edit` (alternatively, launch `Quartus`, run
   `QSys` from the `Tools` menu and open the `.qsys` file located in the `qsys` subdirectory)
3. Edit the system configuration
4. Click on `Generate HDL` 

This will generate a description of the SoPC in the `.sopcinfo` file and of the corresponding
hardwire files in the `qsys/<sopc_name>` subdirectory.

### Editing the hardware configuration

1. Either type `make hw-edit` or launch `Quartus` and open project `hw/top.qpf`
2. Adjust the file containing the SoPC configuration (it should be `../qsys/<sopc_name>/synthesis/<name>.qip`)
3. Edit file `top.v` to instanciate the correct NIOS model (line 72 : `nios_128k_base u0 (...)` ...
   ... and wire the peripherals as wanted
4. Save the project and compile it ("Play" button)

### Editing and (re)building the BSP (Board Support Package)

If the Nios2 configuration has been changed, the BSP must be rebuilt :

- From the platform top directory, type `make bsp`

The BSP can also be edited (by selecting specific drivers to reduce memory footprint for ex.) :

- From the platform top directory, type `make bsp-edit`
