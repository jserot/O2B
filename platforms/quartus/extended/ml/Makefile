include ../../../../etc/config.make

PREFIX=platform

MLS = $(PREFIX).ml
MLIS = $(PREFIX).mli
CMOS = $(PREFIX).cmo
CMIS = $(PREFIX).cmi

TARGETS = $(CMIS) $(CMOS) $(PREFIX).cma

all: $(TARGETS)

$(PREFIX).cma: $(PREFIX).cmo
	$(OCAMLC) -a $^ -o $@

$(PREFIX).cmi: $(PREFIX).mli
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

$(PREFIX).cmo: $(PREFIX).ml $(PREFIX).cmi
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

clean:
	@rm -f $(CMOS) $(CMIS)

clobber: clean
	@rm -f *~

.PHONY: clean clobber
