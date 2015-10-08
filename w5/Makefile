SUBDIRS = 1-structure 2-jobsCtrl

all:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir; \
	done
clean:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir clean; \
	done
test:
	for dir in $(SUBDIRS) ; \
	do\
		make -C $$dir test; \
	done
