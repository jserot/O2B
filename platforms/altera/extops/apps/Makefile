SUBDIRS=mini ios ledshade rotdisplay sieve sieve2

clean:
	for i in $(SUBDIRS); do (cd $$i; make -f ../Makefile.templ clean); done

clobber:
	for i in $(SUBDIRS); do (cd $$i; make -f ../Makefile.templ clobber); done
