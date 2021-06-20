include etc/Makefile.conf

all: omicrob

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


omicrob:
	(cd omicrob; make)

test: omicrob
	(cd platforms/quartus/basic; make omicrob)
	(cd apps/mini; make code && make sim)
	(cd apps/mini; make platform-makefile && make build)

clean:
	(cd omicrob; make clean)
	(cd platforms; make clean)
	(cd apps; make clean)
	@rm -f *~ */*~ */*/*~ */*/*/*~

.PHONY: all config omicrob nios clean
