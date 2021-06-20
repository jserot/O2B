include ../../etc/Makefile.conf

all:
	(cd platforms/$(NIOS_PLATFORM); make omicrob)

clean:
	for i in $(PLATFORMS); do (cd platforms/$$i; make clean); done

clobber:
	for i in $(PLATFORMS); do (cd platforms/$$i; make clobber); done
