PLATFORMS=basic extended

all:
	for i in $(PLATFORMS); do (cd platforms/$$i; make omicrob); done

clean:
	for i in $(PLATFORMS); do (cd platforms/$$i; make clean); done

clobber:
	for i in $(PLATFORMS); do (cd platforms/$$i; make clobber); done
