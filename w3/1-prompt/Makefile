EXE=1-fgets 2-token 3-getcwd 4-chdir 5-debug

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
