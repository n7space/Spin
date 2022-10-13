.PHONY: all test-simulator test-verifier

all: test-simulator test-verifier

test-simulator:
	$(SPIN) system.pml | tee simulator.stdout
	grep -q "state finished" simulator.stdout

test-verifier:
	$(SPIN) -a system.pml
	gcc -o pan pan.c
	./pan -a -n | tee verifier.stdout
	grep -q "errors: 0" verifier.stdout
