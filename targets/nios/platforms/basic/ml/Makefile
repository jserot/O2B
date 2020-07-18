include ../../../../../etc/Makefile.conf

#PLATFORM = $$(basename $$(dirname `pwd`))
PLATFORM=basic

#LIB_FOLDER = $(LIB)/targets/nios/$(PLATFORM)
LIB_FOLDER = $(LIB)/targets/nios

MLS = nios.ml
MLIS = nios.mli
CMOS = nios.cmo
CMIS = nios.cmi

LIB_MLS  = $(foreach ml,$(MLS),$(LIB_FOLDER)/$(ml))
LIB_MLIS = $(foreach mli,$(MLIS),$(LIB_FOLDER)/$(mli))
LIB_CMIS = $(foreach cmi,$(CMIS),$(LIB_FOLDER)/$(cmi))
LIB_CMOS = $(foreach cmo,$(CMOS),$(LIB_FOLDER)/$(cmo))

TARGETS = $(LIB_FOLDER) $(LIB_MLS) $(LIB_MLIS) $(LIB_CMIS) $(LIB_CMOS) $(LIB_FOLDER)/nios.cma

all: $(TARGETS)

$(LIB_FOLDER)/nios.cma: nios.cmo
	$(OCAMLC) -a $^ -o $@

nios.cmi: nios.mli
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

nios.cmo: nios.ml nios.cmi
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

$(LIB_FOLDER):
	mkdir -p $@

$(LIB_FOLDER)/%.ml: %.ml
	cp $< $@

$(LIB_FOLDER)/%.mli: %.mli
	cp $< $@

$(LIB_FOLDER)/%.cmi: %.cmi
	cp $< $@

$(LIB_FOLDER)/%.cmo: %.cmo
	cp $< $@

clean:
	@rm -f $(CMOS) $(CMIS)

clobber: clean
	@rm -f *~

.PHONY: clean clo
