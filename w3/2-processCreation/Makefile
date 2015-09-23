EXE=1-fork 2-exec 3-forkexec 4-forkexecwait 5-dynamicList 6-setenv 6a-wosetenv

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
