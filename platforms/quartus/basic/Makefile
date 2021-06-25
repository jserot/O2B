HW_FILE=./hw/top.qpf
SOF_FILE=./hw/output_files/top.sof
SOPC_FILE=./qsys/nios_128k_base.qsys
SOPCINFO_FILE=./qsys/nios_128k_base.sopcinfo
BSP_SETTINGS=./bsp/settings.bsp
BSP_OPTS=--set hal.sys_clk_timer none --set hal.timestamp_timer sys_timer 

.PHONY: check bsp

omicrob:
	(cd ml; make)
	(cd byterun; make)

check:
ifeq ($(QUARTUS_ROOTDIR),)
	@echo "** Please run nios2_command_shell script before invoking this makefile !"
endif

sopc-edit: check
	qsys-edit $(SOPC_FILE)

hw:  check
	@echo "Check that the DE10-Lite board is connected and the USB-Blaster connection active"
	nios2-configure-sof $(SOF_FILE)

hw-edit: check
	quartus $(HW_FILE)

bsp: check
	nios2-bsp hal bsp $(SOPCINFO_FILE) $(BSP_OPTS)

bsp-edit: check
	nios2-bsp-editor --settings $(BSP_SETTINGS)

clean:
	(cd ml; make clean)
	(cd byterun; make clean)
	(cd apps; make clean)

clobber: clean
	(cd ml; make clobber)
	(cd bsp; make clean)
	rm -f *~
