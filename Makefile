SUBDIRS = w1

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
