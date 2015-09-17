EXE=hello

all: ${EXE}

clean:
	rm -rf ${EXE}
test: ${EXE}
	for i in $(EXE) ; \
	do\
		./$$i; \
		echo '--------'; \
	done
	rm -rf ${EXE}
