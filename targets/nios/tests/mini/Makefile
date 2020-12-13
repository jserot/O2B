include ../../../../etc/Makefile.conf

PLATFORM=basic
PLATFORM_DIR=../../platforms/$(PLATFORM)

OMICROBC=$(BIN)/omicrob
OMICROB_OPTS=-no-shortcut-initialization

#-include ../make_opts

all: Makefile.nios build

check:
ifeq ($(QUARTUS_ROOTDIR),)
	@echo "** Please run nios2_command_shell script before invoking this makefile !"
endif

nios-makefile: Makefile.nios

Makefile.nios: check
	cp Makefile Makefile.top # Save this makefile because it will overwritten
	nios2-app-generate-makefile --app-dir . --bsp-dir $(PLATFORM_DIR)/bsp --set APP_CFLAGS_OPTIMIZATION -Os --set APP_CFLAGS_USER_FLAGS '-std=c11 -I$(INCLUDEDIR)/nios/$(PLATFORM) -I$(INCLUDEDIR)/nios' --src-files ./main.c
	mv Makefile Makefile.nios
	mv Makefile.top Makefile

main.c: main.ml
	$(OMICROBC) $(OMICROB_OPTS) -device de10lite -v -mlopt -verbose -o main.c main.ml

code: main.c

build: check code
	make -f Makefile.nios

run: check main.elf
	make -f Makefile.nios download-elf

term: check
	nios2-terminal

clean: 
	@rm -f *.cmo *.cmi
	@rm -f *.c *.byte

clobber: clean
	@rm -f *.elf *.map *.objdump 
	@rm -rf obj
	@rm -f *~ 
	@rm -f Makefile.nios
