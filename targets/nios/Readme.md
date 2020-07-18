Implementation of OMicroB on the Nios2 soft-core processor to be run on Intel FPGAs.

Jul 2020, J. Sérot (jocelyn.serot@uca.fr)

To build / run an application

1. Choose or write a specific platform (see `platforms/Readme.md`)

2. Go to `OMicroB` building directory (`cd ../..`) and run

   - `./configure -prefix <install_dir> -target nios-<platform>` 
   
3. (Re)build and (re)install `OMicroB` :

   - `make clean`
   - `make`
   - `make install` 

4. Go to the platform directory and upload the hardware configuration :

   - `cd targets/nios/platforms/<platform>` 
   - `make hw` 

5. Go to the application directory, build and upload the software

   - `cd targets/nios/tests/<app>` 
   - `make build` 
   - `make run`

When changing the application, steps 1-4 only need to be re-taken if the platform is different. 
The name of the required platform  for a given application is given at the top of `<app>/Makefile`.
