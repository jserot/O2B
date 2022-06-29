include ../../../../etc/config.make

TARGETLIB=libcamlrun.a

OCAML_COPTS=-ccopt -Wall -ccopt -Wno-unused-result -ccopt -D__OCAML__

HEADERS := $(wildcard */*.h)

OBJECTS :=              \
  _build/bindings.o     \
  _build/random.o       \
  _build/trace.o        \
  _build/gc.o           \
  _build/format.o       \
  _build/sf-regs.o 
#  _build/shared.o       \
#  _build/simul.o

all: srcs $(TARGETLIB)

$(TARGETLIB): $(OBJECTS)
	@rm -f $@
	cp $(OCAMLWHERE)/libcamlrun.a $@
	ar rs $@ $(OBJECTS)

srcs: 
	mkdir -p _build/
	cat $(SRC)/byterun/prims/indep-prims.h ./platform.h > _build/prims.h
	cat $(SRC)/byterun/prims/indep-bindings.c ./platform-bindings.c > _build/bindings.c
	cat $(SRC)/byterun/simul/platform-indep-sf-regs.c ./simul.c > _build/sf-regs.c
	cat $(SRC)/byterun/simul/platform-indep-sf-regs.h ./simul.h > _build/sf-regs.h
	cp -r $(SRC)/byterun/stdlib _build
	cp -r $(SRC)/byterun/vm _build

_build/bindings.o: _build/bindings.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $@ $<
	mv bindings.o _build

_build/random.o: _build/stdlib/random.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $<
	mv random.o _build

_build/trace.o: _build/stdlib/trace.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $<
	mv trace.o _build

_build/gc.o: _build/stdlib/gc.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $<
	mv gc.o _build

_build/format.o: _build/stdlib/format.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $<
	mv format.o _build

_build/sf-regs.o: _build/sf-regs.c $(HEADERS)
	$(OCAMLC) -c $(OCAML_COPTS) $<
	mv sf-regs.o _build

clean:
	@rm -Rf _build/ $(TARGETLIB)
	@rm -rf stdlib
	@rm -rf vm
	@rm -f *~ 

.PHONY: clean srcs

