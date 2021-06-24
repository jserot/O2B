include ../../../../etc/config.make

PREFIX=platform

MLS = $(PREFIX).ml
MLIS = $(PREFIX).mli
CMOS = $(PREFIX).cmo
CMIS = $(PREFIX).cmi

# LIB_MLS  = $(foreach ml,$(MLS),$(LIB_FOLDER)/$(ml))
# LIB_MLIS = $(foreach mli,$(MLIS),$(LIB_FOLDER)/$(mli))
# LIB_CMIS = $(foreach cmi,$(CMIS),$(LIB_FOLDER)/$(cmi))
# LIB_CMOS = $(foreach cmo,$(CMOS),$(LIB_FOLDER)/$(cmo))

#TARGETS = $(LIB_FOLDER) $(LIB_MLS) $(LIB_MLIS) $(LIB_CMIS) $(LIB_CMOS) $(LIB_FOLDER)/$(PREFIX).cma
TARGETS = $(CMIS) $(CMOS) $(PREFIX).cma

all: $(TARGETS)

#$(LIB_FOLDER)/$(PREFIX).cma: $(PREFIX).cmo
$(PREFIX).cma: $(PREFIX).cmo
	$(OCAMLC) -a $^ -o $@

$(PREFIX).cmi: $(PREFIX).mli
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

$(PREFIX).cmo: $(PREFIX).ml $(PREFIX).cmi
	CAMLLIB=$(LIB) $(OCAMLC) -c -w @a $< -o $@

# $(LIB_FOLDER):
# 	mkdir -p $@

# $(LIB_FOLDER)/%.ml: %.ml
# 	cp $< $@

# $(LIB_FOLDER)/%.mli: %.mli
# 	cp $< $@

# $(LIB_FOLDER)/%.cmi: %.cmi
# 	cp $< $@

# $(LIB_FOLDER)/%.cmo: %.cmo
# 	cp $< $@

clean:
	@rm -f $(CMOS) $(CMIS)

clobber: clean
	@rm -f *~

.PHONY: clean clobber
