include etc/config.make

all: omicrob

config:
	@if [ $(ETC)/config.make -ot VERSION -o                     \
             $(ETC)/config.make -ot configure ]; then               \
          echo 'Configuration files are not up to date.' 1>&2;        \
	  echo 'Please run `./configure` (with right options).' 1>&2; \
          exit 1;                                                     \
	fi

etc/config.make:
	@echo "You must run ./configure before" 1>&2
	@exit 1


omicrob:
	(cd omicrob; make)

test: omicrob
	(cd platforms/quartus/basic; make omicrob)
	(cd platforms/quartus/basic/apps/mini; make code && make sim)
	(cd platforms/quartus/basic/apps/mini; make platform-makefile && make build)

clean:
	(cd omicrob; make clean)
	(cd platforms; make clean)
	@rm -f *~ */*~ */*/*~ */*/*/*~

.PHONY: all config omicrob clean
