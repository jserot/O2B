include ../../../etc/config.make

TARGETS := $(BIN)/omicrob

omicrob: $(TARGETS)

$(BIN)/omicrob: config.ml tools.ml platform.ml omicrob.ml
	mkdir -p $(BIN)
	$(OCAMLOPT) -w @a -safe-string -strict-formats -strict-sequence unix.cmxa $^ -o $@

config.ml: $(ETC)/config.ml
	cp $< $@

clean:
	@rm -f *.cmo *.cmi *.cmx *~  *.o

.PHONY: omicrob clean
