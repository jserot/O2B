include ../../../../etc/Makefile.conf

TARGETLIB=libcamlrun.a

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
	cp -r $(SRC)/byterun/stdlib .
	cp -r $(SRC)/byterun/vm .

.build/bindings.o: bindings.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv bindings.o .build/

.build/%.o: stdlib/%.c $(HEADERS)
	mkdir -p .build/
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv $*.o .build/

.build/%.o: simul/%.c $(HEADERS)
	$(OCAMLC) -c -ccopt -Wall -ccopt -D__OCAML__ $<
	mv $*.o .build/

clean:
	@rm -Rf .build/ $(TARGETLIB)
	@rm -f *~ 

.PHONY: clean srcs
