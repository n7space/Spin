#Spin integration tests, based on the README_tests.txt and the provided examples
BASE_DIR=../..
SPIN?=${BASE_DIR}/Src/spin
MODEL_DIR=${BASE_DIR}/Examples
TEST_DIR=Out

CC?=gcc
PAN=pan
CREATE_TEST_DIR=mkdir -p ${TEST_DIR}
DELETE_TEST_DIR=rm -r ${TEST_DIR}

.PHONY : check \
	test_hello \
	test_loops

check: test_hello \
	test_loops

#test 1	check that you can run a simulation
test_hello:
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${MODEL_DIR}/hello.pml > hello.output
	grep -q "State-vector 12 byte, depth reached 2, errors: 0" ${TEST_DIR}/hello.output
	grep -q "3 states, stored" ${TEST_DIR}/hello.output
	${DELETE_TEST_DIR}

#test 2	a basic reachability check (safety)
test_loops:
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${MODEL_DIR}/loops.pml && \
	${CC} -DNOREDUCE -o ${PAN} pan.c && \
	./${PAN} > loops.output
	grep -q "State-vector 12 byte, depth reached 11, errors: 0" ${TEST_DIR}/loops.output
	grep -q "15 states, stored" ${TEST_DIR}/loops.output
	grep -q "4 states, matched" ${TEST_DIR}/loops.output
	grep -q "19 transitions (= stored+matched)" ${TEST_DIR}/loops.output
	grep -q "0 atomic steps" ${TEST_DIR}/loops.output
	${DELETE_TEST_DIR}

