include ../../etc/Makefile.conf

PLATFORM_DIR=../../platforms/quartus/basic

OMICROBC=$(BIN)/omicrob
OMICROB_OPTS=-no-shortcut-initialization

#-include ../make_opts

code: main.c

main.c: main.ml
	$(OMICROBC) $(OMICROB_OPTS) -platform_dir $(PLATFORM_DIR) -v -mlopt -verbose -o main.c main.ml

sim:
	./main.byte

all: Makefile.platform build

check:
ifeq ($(QUARTUS_ROOTDIR),)
	@echo "** Please run nios2_command_shell script before invoking this makefile !"
endif

platform-makefile: Makefile.platform

Makefile.platform: check
	cp Makefile Makefile.top # Save this makefile because it will overwritten
	nios2-app-generate-makefile --app-dir . --bsp-dir $(PLATFORM_DIR)/bsp --set APP_CFLAGS_OPTIMIZATION -Os --set APP_CFLAGS_USER_FLAGS '-std=c11 -I$(INCLUDEDIR) -I$(PLATFORM_DIR)/lib -I$(PLATFORM_DIR)/byterun' --src-files ./main.c
	mv Makefile Makefile.platform
	mv Makefile.top Makefile

build: check main.c
	make -f Makefile.platform

run: check main.elf
	make -f Makefile.platform download-elf && nios2-terminal

term: check
	nios2-terminal

clean: 
	@rm -f *.cmo *.cmi
	@rm -f *.c *.byte
	@rm -f *.elf *.map *.objdump 
	@rm -rf obj
	@rm -f *~ 
	@rm -f Makefile.platform
