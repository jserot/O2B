include ../etc/Makefile.conf

all: bin lib

bin:
	$(call compile, src/bc2c)	
	$(call compile, src/omicrob)

lib:
	$(call compile, src/stdlib)
	cp -a src/byterun/prims "$(OMICROB)/include/"
	cp -a src/byterun/stdlib "$(OMICROB)/include/"
	cp -a src/byterun/vm "$(OMICROB)/include/"

clean:
	-rm -f bin/*
	-rm -f lib/*
	-rm -rf include/prims
	-rm -rf include/stdlib
	-rm -rf include/vm
	(cd src/bc2c; make clean)
	(cd src/omicrob; make clean)

.PHONY: bin lib 
