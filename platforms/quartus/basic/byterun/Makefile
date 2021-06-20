include ../../../../etc/Makefile.conf

TARGETLIB=libcamlrun.a

GENERATED_SRCS=prims.h bindings.c

HEADERS := $(wildcard */*.h)

OBJECTS :=              \
  .build/bindings.o     \
  .build/random.o       \
  .build/trace.o        \
  .build/gc.o           \
  .build/format.o       \
  .build/sf-regs.o 
#  .build/shared.o       \
#  .build/simul.o

all: srcs $(TARGETLIB)

$(TARGETLIB): $(OBJECTS)
	@rm -f $@
	cp $(OCAMLWHERE)/libcamlrun.a $@
	ar rs $@ $(OBJECTS)

srcs: 
	cat $(SRC)/byterun/prims/indep-prims.h ./prims/prims.h > prims.h
	cat $(SRC)/byterun/prims/indep-bindings.c ./prims/bindings.c > bindings.c
	cat $(SRC)/byterun/simul/platform-indep-sf-regs.c ./simul/sf-regs.c > sf-regs.c
	cat $(SRC)/byterun/simul/platform-indep-sf-regs.h ./simul/sf-regs.c > sf-regs.h
	cp -r $(SRC)/byterun/stdlib .
	cp -r $(SRC)/byterun/vm .

.build/bindings.o: bindings.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv bindings.o .build/

.build/random.o: stdlib/random.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv random.o .build/

.build/trace.o: stdlib/trace.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv trace.o .build/

.build/gc.o: stdlib/gc.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv gc.o .build/

.build/format.o: stdlib/format.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv format.o .build/

.build/sf-regs.o: sf-regs.c $(HEADERS)
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv sf-regs.o .build/

clean:
	@rm -Rf .build/ $(TARGETLIB)
	@rm -rf stdlib
	@rm -rf vm
	@rm -f $(GENERATED_SRCS) 
	@rm -f *~ 

.PHONY: clean srcs

