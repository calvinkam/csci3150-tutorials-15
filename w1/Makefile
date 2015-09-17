SUBDIRS = 1-helloworld 2-pointer 3-arraypointer 4-argv

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
