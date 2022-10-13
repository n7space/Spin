.PHONY: all test-verifier

all: test-verifier

test-verifier:
	$(SPIN) -a system.pml
	gcc -o pan pan.c
	./pan -a -n | tee verifier.stdout
	grep -q "errors: 1" verifier.stdout
	${SPIN} -t -r -s system.pml | tee trace.stdout
	grep -q "3.1415" trace.stdout
