## Update an existing platform

Sometimes, just rebuilding the platform in the corresponding subdir is not enough to make the test
apps making use of this platform build with the updated/added functionalities.

The simplest way to solve this problem (before the compilation mechanism is revamped) is to follow
the following steps :

- ./configure -target nios-<platform>
- make clean
- make
- cd targets/nios/plateforms/<platform>/      
- make bsp
- make hw
- make clobber
- make omicrob
- cd ../../tests/<app>
- make clean
- make nios-makefile
- make
- make run
