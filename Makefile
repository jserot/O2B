include etc/Makefile.conf

all: omicrob $(TARGETS)

config:
	@if [ $(ETC)/Makefile.conf -ot VERSION -o                     \
             $(ETC)/Makefile.conf -ot configure ]; then               \
          echo 'Configuration files are not up to date.' 1>&2;        \
	  echo 'Please run `./configure` (with right options).' 1>&2; \
          exit 1;                                                     \
	fi

etc/Makefile.conf:
	@echo "You must run ./configure before" 1>&2
	@exit 1

omicrob: config
	mkdir -p "$(OMICROB)/lib"
#	mkdir -p "$(OMICROB)/libexec"
	mkdir -p "$(OMICROB)/include"
	mkdir -p "$(OMICROB)/bin"
#	mkdir -p "$(OMICROB)/man/man1"
#	mkdir -p "$(OMICROB)/man/man3"
	$(call compile, src/bc2c)
	$(call compile, src/byterun)
	$(call compile, src/omicrob)
	$(call compile, src/stdlib)
#	cp lib/libcamlrun.a "$(LIBDIR)/libcamlrun.a"
#	cp -a lib/targets "$(LIBDIR)/"
	cp -a src/byterun/vm "$(OMICROB)/include/"
	cp -a src/byterun/prims "$(OMICROB)/include/"
	cp -a src/byterun/stdlib "$(OMICROB)/include/"
	for i in $(TARGETS); do cp -a src/byterun/$$i "$(OMICROB)/include/" 2> /dev/null; done

# PLATFORM-SPECIFIC TARGETS

nios: omicrob
	$(call compile, targets/nios)

clean:
	-rm -rf "$(OMICROB)/bin"
	-rm -rf "$(OMICROB)/lib"
	-rm -rf "$(OMICROB)/include"
#	-rm -rf "$(OMICROB)/libexec"
#	-rm -rf "$(OMICROB)/man"
	@rm -rf lib/targets/nios
	$(call clean, targets/nios)
	@rm -f *~ */*~ */*/*~ */*/*/*~

.PHONY: all config omicrob nios clean
