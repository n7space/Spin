#Spin integration tests, based on the README_tests.txt and the provided examples

BASE_DIR=../..
export SPIN?=${BASE_DIR}/Src/spin
EXAMPLE_MODEL_DIR=${BASE_DIR}/Examples
USER_TYPES_MODEL_DIR=${BASE_DIR}/Test/UserTypes
FLOAT_MODEL_DIR=${BASE_DIR}/Test/Float
FLOAT_DUMPING_MODEL_DIR=${FLOAT_MODEL_DIR}/Dumping
FLOAT_CHANNEL_MODEL_DIR=${FLOAT_MODEL_DIR}/Channels
FLOAT_CHANNEL_COMPLEX_TESTS_DIR=${FLOAT_CHANNEL_MODEL_DIR}/ComplexTests
TEST_DIR=Out

CC?=gcc
PAN=pan
CREATE_TEST_DIR=mkdir -p ${TEST_DIR}
DELETE_TEST_DIR=rm -r ${TEST_DIR}

EXAMPLE_TESTS= \
	test_hello \
	test_loops \
	test_loops_cycles \
	test_loops_cycles_playback \
	test_loops_cycles_avoid_progress \
	test_partial_order_reduction_enabled \
	test_partial_order_reduction_disabled \
	test_rng \
	test_ltl_generation

TYPEDEF_TESTS= \
	test_nested_typedef \
	test_typedef_for_channel \
	test_typedef_for_global_data \
	test_typedef_for_local_data

UNION_TESTS= \
	test_nested_union \
	test_union_for_channel \
	test_union_for_global_data \
	test_union_for_local_data

COMPLEX_TESTS = \
	test_message

BENCHMARK = \
	benchmark_large_message

FLOAT_TESTS = \
	test_float_literal_values \
	test_float_arithmetic_operators \
	test_float_arithmetic \
	test_float_in_struct \
	test_float_can_be_dumped \
	test_simple_floats_through_channel \
	test_ping_pong_with_floats_through_channel \
	test_channel_with_floats_enumeration \
	test_complex_structures_with_floats_in_channels \
	test_channel_complex_tests_float_basic \
	test_channel_complex_tests_float_basic_fail \
	test_channel_complex_tests_float_compare \
	test_channel_complex_tests_float_operations

.SILENT : ${EXAMPLE_TESTS} \
	${TYPEDEF_TESTS} \
	${UNION_TESTS} \
	${COMPLEX_TESTS} \
	${BENCHMARK} \
	${FLOAT_TESTS} \
	test_rng_files \
	check_examples \
	check_unions \
	check_typedefs \
	check_complex \
	benchmark \
	check_floats

.PHONY : ${EXAMPLE_TESTS} \
	${TYPEDEF_TESTS} \
	${UNION_TESTS} \
	${COMPLEX_TESTS} \
	${BENCHMARK} \
	${FLOAT_TESTS} \
	test_rng_files \
	check_examples \
	check_unions \
	check_typedefs \
	check_complex \
	benchmark \
	check_floats \
	check

check: ${EXAMPLE_TESTS} ${TYPEDEF_TESTS} ${UNION_TESTS} ${COMPLEX_TESTS} ${FLOAT_TESTS}

check_examples: ${EXAMPLE_TESTS}

check_unions: ${UNION_TESTS}

check_typedefs: ${TYPEDEF_TESTS}

check_complex: ${COMPLEX_TESTS}

check_floats: ${FLOAT_TESTS}

benchmark: ${BENCHMARK}

############################EXAMPLE TESTS######################################

#Test 1: check that you can run a simulation
test_hello:
	echo "Test 1: check that you can run a simulation"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${EXAMPLE_MODEL_DIR}/hello.pml > hello.output
	grep -q "State-vector 12 byte, depth reached 2, errors: 0" ${TEST_DIR}/hello.output
	grep -q "3 states, stored" ${TEST_DIR}/hello.output
	${DELETE_TEST_DIR}

#Test 2: a basic reachability check (safety)
test_loops:
	echo "Test 2: a basic reachability check (safety)"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/loops.pml && \
	${CC} -DNOREDUCE -o ${PAN} pan.c && \
	./${PAN} > loops.output
	grep -q "State-vector 12 byte, depth reached 11, errors: 0" ${TEST_DIR}/loops.output
	grep -q "15 states, stored" ${TEST_DIR}/loops.output
	grep -q "4 states, matched" ${TEST_DIR}/loops.output
	grep -q "19 transitions (= stored+matched)" ${TEST_DIR}/loops.output
	grep -q "0 atomic steps" ${TEST_DIR}/loops.output
	${DELETE_TEST_DIR}

#Test 3: cycle detection check (liveness)
test_loops_cycles:
	echo "Test 3: cycle detection check (liveness)"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/loops.pml && \
	${CC} -DNOREDUCE -o ${PAN} pan.c && \
	./${PAN} -a > loops.output
	grep -q "pan:1: acceptance cycle (at depth 0)" ${TEST_DIR}/loops.output
	grep -q "pan: wrote loops.pml.trail" ${TEST_DIR}/loops.output
	grep -q "State-vector 12 byte, depth reached 11, errors: 1" ${TEST_DIR}/loops.output
	grep -q "13 states, stored (15 visited)" ${TEST_DIR}/loops.output
	grep -q "2 states, matched" ${TEST_DIR}/loops.output
	grep -q "17 transitions (= visited+matched)" ${TEST_DIR}/loops.output
	grep -q "0 atomic steps" ${TEST_DIR}/loops.output
	${DELETE_TEST_DIR}

#Test 4: guided simulation check (playback the error trail found in test 3)
test_loops_cycles_playback:
	echo "Test 4: guided simulation check (playback the error trail found in test 3)"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/loops.pml && \
	${CC} -DNOREDUCE -o ${PAN} pan.c && \
	./${PAN} -a > loops.output && \
	cp ${EXAMPLE_MODEL_DIR}/loops.pml loops.pml && \
	${SPIN} -t -p loops.pml > loops_replay.output
	grep -q "<<<<<START OF CYCLE>>>>>"				  	    ${TEST_DIR}/loops_replay.output
	grep -q "1:\W*proc  0 (loop:1) loops.pml:5 (state 1)"   ${TEST_DIR}/loops_replay.output
	grep -q "2:\W*proc  0 (loop:1) loops.pml:7 (state 2)"   ${TEST_DIR}/loops_replay.output
	grep -q "3:\W*proc  0 (loop:1) loops.pml:7 (state 3)"   ${TEST_DIR}/loops_replay.output
	grep -q "4:\W*proc  0 (loop:1) loops.pml:10 (state 8)"  ${TEST_DIR}/loops_replay.output
	grep -q "5:\W*proc  0 (loop:1) loops.pml:5 (state 1)"   ${TEST_DIR}/loops_replay.output
	grep -q "6:\W*proc  0 (loop:1) loops.pml:7 (state 2)"   ${TEST_DIR}/loops_replay.output
	grep -q "7:\W*proc  0 (loop:1) loops.pml:7 (state 3)"   ${TEST_DIR}/loops_replay.output
	grep -q "8:\W*proc  0 (loop:1) loops.pml:10 (state 8)"  ${TEST_DIR}/loops_replay.output
	grep -q "9:\W*proc  0 (loop:1) loops.pml:5 (state 1)"   ${TEST_DIR}/loops_replay.output
	grep -q "10:\W*proc  0 (loop:1) loops.pml:8 (state 4)"  ${TEST_DIR}/loops_replay.output
	grep -q "11:\W*proc  0 (loop:1) loops.pml:8 (state 5)"  ${TEST_DIR}/loops_replay.output
	grep -q "spin: loops.pml:10, Error: value (-1->255 (8)) truncated in assignment" \
														    ${TEST_DIR}/loops_replay.output
	grep -q "12:\W*proc  0 (loop:1) loops.pml:10 (state 8)" ${TEST_DIR}/loops_replay.output
	grep -q "spin: trail ends after 12 steps"               ${TEST_DIR}/loops_replay.output
	grep -q "#processes: 1"                                 ${TEST_DIR}/loops_replay.output
	grep -q "12:\W*proc  0 (loop:1) loops.pml:4 (state 9)"  ${TEST_DIR}/loops_replay.output
	${DELETE_TEST_DIR}

#Test 5: try to find a cycle that avoids the progress labels (there are none)
test_loops_cycles_avoid_progress:
	echo "Test 5: try to find a cycle that avoids the progress labels (there are none)"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/loops.pml && \
	${CC} -DNP -DNOREDUCE -o ${PAN} pan.c && \
	./${PAN} -l > loops.output
	grep -q "State-vector 20 byte, depth reached 23, errors: 0" ${TEST_DIR}/loops.output
	grep -q "27 states, stored (39 visited)" ${TEST_DIR}/loops.output
	grep -q "28 states, matched" ${TEST_DIR}/loops.output
	grep -q "67 transitions (= visited+matched)" ${TEST_DIR}/loops.output
	grep -q "0 atomic steps" ${TEST_DIR}/loops.output
	grep -q "unreached in proctype loop" ${TEST_DIR}/loops.output
	grep -q "loops.pml:12, state 12, \"-end-\"" ${TEST_DIR}/loops.output
	${DELETE_TEST_DIR}

#Test 6: check partial order reduction algorithm -- first disable it
test_partial_order_reduction_disabled:
	echo "Test 6: check partial order reduction algorithm -- first disable it"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/leader0.pml && \
	${CC} -DSAFETY -DNOREDUCE -DNOCLAIM -o ${PAN} pan.c && \
	./${PAN} -c0 -n > leader0.output
	grep -q "errors: 0" ${TEST_DIR}/leader0.output
	grep -q "15779 states, stored" ${TEST_DIR}/leader0.output
	grep -q "42402 states, matched" ${TEST_DIR}/leader0.output
	grep -q "58181 transitions (= stored+matched)" ${TEST_DIR}/leader0.output
	${DELETE_TEST_DIR}

#Test 6b: now leave p.o. reduction enabled (i.e., do not disable it)
test_partial_order_reduction_enabled:
	echo "Test 6b: now leave p.o. reduction enabled (i.e., do not disable it)"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -a ${EXAMPLE_MODEL_DIR}/leader0.pml && \
	${CC} -DSAFETY -DNOCLAIM -o ${PAN} pan.c && \
	./${PAN} -c0 -n > leader0.output
	grep -q "errors: 0" ${TEST_DIR}/leader0.output
	grep -q "97 states, stored" ${TEST_DIR}/leader0.output
	grep -q "0 states, matched" ${TEST_DIR}/leader0.output
	grep -q "97 transitions (= stored+matched)" ${TEST_DIR}/leader0.output
	${DELETE_TEST_DIR}

#Test 7: check random number generator
#	The numbers in the array should tend to the ratio
#	1:2:3:4 if the random number generator works properly.
#	array index 0 remains unused (it's the pid of the init
#	process)

# Files have to be prepared in a separate rule to avoid premature shell expansion
test_rng_files:
	echo "Test 7: check random number generator"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -o6 -p -g -u10000 ${EXAMPLE_MODEL_DIR}/priorities.pml \
		> priorities.output
	grep "a\[1\] = " ${TEST_DIR}/priorities.output | tail -1 | sed "s/a\[1\] = //" | xargs \
		> ${TEST_DIR}/a1.value
	grep "a\[2\] = " ${TEST_DIR}/priorities.output | tail -1 | sed "s/a\[2\] = //" | xargs \
		> ${TEST_DIR}/a2.value
	grep "a\[3\] = " ${TEST_DIR}/priorities.output | tail -1 | sed "s/a\[3\] = //" | xargs \
		> ${TEST_DIR}/a3.value
	grep "a\[4\] = " ${TEST_DIR}/priorities.output | tail -1 | sed "s/a\[4\] = //" | xargs \
		> ${TEST_DIR}/a4.value

# Actual test, checking the generated values
test_rng: test_rng_files
	expr $(shell cat ${TEST_DIR}/a1.value) \> 240 > /dev/null && \
		expr $(shell cat ${TEST_DIR}/a1.value) \< 360 > /dev/null
	expr $(shell cat ${TEST_DIR}/a2.value) \> 490 > /dev/null && \
		expr $(shell cat ${TEST_DIR}/a2.value) \<= 710 > /dev/null
	expr $(shell cat ${TEST_DIR}/a3.value) \> 740 > /dev/null && \
		expr $(shell cat ${TEST_DIR}/a3.value) \< 1060 > /dev/null
	expr $(shell cat ${TEST_DIR}/a4.value) \> 990 > /dev/null && \
		expr $(shell cat ${TEST_DIR}/a4.value) \< 1410 > /dev/null
	${DELETE_TEST_DIR}

#Test 8: test the generation of never claims from LTL formulae:
test_ltl_generation:
	echo "Test 8: test the generation of never claims from LTL formulae"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -f "[] ( p U ( <> q ))" > ltl_generation.output
	grep -q "T0_init:" ${TEST_DIR}/ltl_generation.output
	grep -q "do" ${TEST_DIR}/ltl_generation.output
	grep -q ":: ((q)) -> goto accept_S9" ${TEST_DIR}/ltl_generation.output
	grep -q ":: (1) -> goto T0_init" ${TEST_DIR}/ltl_generation.output
	grep -q "od;" ${TEST_DIR}/ltl_generation.output
	grep -q "accept_S9:" ${TEST_DIR}/ltl_generation.output
	grep -q "do" ${TEST_DIR}/ltl_generation.output
	grep -q ":: (1) -> goto T0_init" ${TEST_DIR}/ltl_generation.output
	grep -q "od;" ${TEST_DIR}/ltl_generation.output
	${DELETE_TEST_DIR}

##############################TYPEDEF TESTS####################################

#Test nested typedef
test_nested_typedef:
	echo "Test nested typedef"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/NestedTypedef.pml > NestedTypedef.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/NestedTypedef.pml > NestedTypedef.sim.output
	grep -q "State-vector 28 byte, depth reached 10, errors: 0" ${TEST_DIR}/NestedTypedef.output
	grep -q "11 states, stored" ${TEST_DIR}/NestedTypedef.output
	grep -q "0 states, matched" ${TEST_DIR}/NestedTypedef.output
	grep -q "11 transitions (= stored+matched)" ${TEST_DIR}/NestedTypedef.output
	grep -q "0 atomic steps" ${TEST_DIR}/NestedTypedef.output
	grep -q "Data c1 is 100 and 200" ${TEST_DIR}/NestedTypedef.sim.output
	grep -q "Data c2 is 10 and 20" ${TEST_DIR}/NestedTypedef.sim.output
	${DELETE_TEST_DIR}

#Test typedef used in channel
test_typedef_for_channel:
	echo "Test typedef used in channel"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/TypedefForChannel.pml > TypedefForChannel.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/TypedefForChannel.pml > TypedefForChannel.sim.output
	grep -q "State-vector 52 byte, depth reached 10, errors: 0" ${TEST_DIR}/TypedefForChannel.output
	grep -q "9 states, stored" ${TEST_DIR}/TypedefForChannel.output
	grep -q "0 states, matched" ${TEST_DIR}/TypedefForChannel.output
	grep -q "9 transitions (= stored+matched)" ${TEST_DIR}/TypedefForChannel.output
	grep -q "0 atomic steps" ${TEST_DIR}/TypedefForChannel.output
	grep -q "Data is 1969 and 1337" ${TEST_DIR}/TypedefForChannel.sim.output
	grep -q "Data is 10 and 50" ${TEST_DIR}/TypedefForChannel.sim.output
	${DELETE_TEST_DIR}

#Test typedef used for global data
test_typedef_for_global_data:
	echo "Test typedef used for global data"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/TypedefForGlobalData.pml > TypedefForGlobalData.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/TypedefForGlobalData.pml > TypedefForGlobalData.sim.output
	grep -q "State-vector 20 byte, depth reached 6, errors: 0" ${TEST_DIR}/TypedefForGlobalData.output
	grep -q "7 states, stored" ${TEST_DIR}/TypedefForGlobalData.output
	grep -q "0 states, matched" ${TEST_DIR}/TypedefForGlobalData.output
	grep -q "7 transitions (= stored+matched)" ${TEST_DIR}/TypedefForGlobalData.output
	grep -q "0 atomic steps" ${TEST_DIR}/TypedefForGlobalData.output
	grep -q "Data is 12 and 17" ${TEST_DIR}/TypedefForGlobalData.sim.output
	${DELETE_TEST_DIR}

#Test typedef used for local data
test_typedef_for_local_data:
	echo "Test typedef used for local data"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/TypedefForLocalData.pml > TypedefForLocalData.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/TypedefForLocalData.pml > TypedefForLocalData.sim.output
	grep -q "State-vector 20 byte, depth reached 2, errors: 0" ${TEST_DIR}/TypedefForLocalData.output
	grep -q "3 states, stored" ${TEST_DIR}/TypedefForLocalData.output
	grep -q "0 states, matched" ${TEST_DIR}/TypedefForLocalData.output
	grep -q "3 transitions (= stored+matched)" ${TEST_DIR}/TypedefForLocalData.output
	grep -q "0 atomic steps" ${TEST_DIR}/TypedefForLocalData.output
	grep -q "Data is 12 and 17" ${TEST_DIR}/TypedefForLocalData.sim.output
	${DELETE_TEST_DIR}

################################UNION TESTS####################################

#Test nested union
test_nested_union:
	echo "Test nested union"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/NestedUnion.pml > NestedUnion.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/NestedUnion.pml > NestedUnion.sim.output
	grep -q "State-vector 20 byte, depth reached 13, errors: 0" ${TEST_DIR}/NestedUnion.output
	grep -q "14 states, stored" ${TEST_DIR}/NestedUnion.output
	grep -q "0 states, matched" ${TEST_DIR}/NestedUnion.output
	grep -q "14 transitions (= stored+matched)" ${TEST_DIR}/NestedUnion.output
	grep -q "0 atomic steps" ${TEST_DIR}/NestedUnion.output
	grep -q "Data c1 a is 100" ${TEST_DIR}/NestedUnion.sim.output
	grep -q "Data c1 b is 200" ${TEST_DIR}/NestedUnion.sim.output
	grep -q "Data c2 a is 10" ${TEST_DIR}/NestedUnion.sim.output
	grep -q "Data c2 b is 20" ${TEST_DIR}/NestedUnion.sim.output
	${DELETE_TEST_DIR}

#Test union used in channel
test_union_for_channel:
	echo "Test union used in channel"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/UnionForChannel.pml > UnionForChannel.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/UnionForChannel.pml > UnionForChannel.sim.output
	grep -q "State-vector 40 byte, depth reached 10, errors: 0" ${TEST_DIR}/UnionForChannel.output
	grep -q "9 states, stored" ${TEST_DIR}/UnionForChannel.output
	grep -q "0 states, matched" ${TEST_DIR}/UnionForChannel.output
	grep -q "9 transitions (= stored+matched)" ${TEST_DIR}/UnionForChannel.output
	grep -q "0 atomic steps" ${TEST_DIR}/UnionForChannel.output
	grep -q "Data is 1969" ${TEST_DIR}/UnionForChannel.sim.output
	grep -q "Data is 1337" ${TEST_DIR}/UnionForChannel.sim.output
	${DELETE_TEST_DIR}

#Test union used for global data
test_union_for_global_data:
	echo "Test union used for global data"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/UnionForGlobalData.pml > UnionForGlobalData.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/UnionForGlobalData.pml > UnionForGlobalData.sim.output
	grep -q "State-vector 20 byte, depth reached 7, errors: 0" ${TEST_DIR}/UnionForGlobalData.output
	grep -q "8 states, stored" ${TEST_DIR}/UnionForGlobalData.output
	grep -q "0 states, matched" ${TEST_DIR}/UnionForGlobalData.output
	grep -q "8 transitions (= stored+matched)" ${TEST_DIR}/UnionForGlobalData.output
	grep -q "0 atomic steps" ${TEST_DIR}/UnionForGlobalData.output
	grep -q "Data is 12" ${TEST_DIR}/UnionForGlobalData.sim.output
	grep -q "Data is 17" ${TEST_DIR}/UnionForGlobalData.sim.output
	${DELETE_TEST_DIR}

#Test union used for local data
test_union_for_local_data:
	echo "Test union used for local data"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${USER_TYPES_MODEL_DIR}/UnionForLocalData.pml > UnionForLocalData.output
	cd ${TEST_DIR} && \
	${SPIN} ${USER_TYPES_MODEL_DIR}/UnionForLocalData.pml > UnionForLocalData.sim.output
	grep -q "State-vector 16 byte, depth reached 2, errors: 0" ${TEST_DIR}/UnionForLocalData.output
	grep -q "3 states, stored" ${TEST_DIR}/UnionForLocalData.output
	grep -q "0 states, matched" ${TEST_DIR}/UnionForLocalData.output
	grep -q "3 transitions (= stored+matched)" ${TEST_DIR}/UnionForLocalData.output
	grep -q "0 atomic steps" ${TEST_DIR}/UnionForLocalData.output
	grep -q "Data is 12" ${TEST_DIR}/UnionForLocalData.sim.output
	grep -q "Data is 17" ${TEST_DIR}/UnionForLocalData.sim.output
	${DELETE_TEST_DIR}

###############################COMPLEX DATA TYPES##############################

#Test complex message type which mixes typedefs and unions
#Messages are passed through channels and processed
#An assert violation is expected to be found
test_message:
	echo "Test complex message type which mixes typedefs and unions"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run -E -bfs ${USER_TYPES_MODEL_DIR}/Message.pml > Message.output	
	grep -q "pan:1: assertion violated (msgIn.payload.readNotif.status==5) (at depth 8)" ${TEST_DIR}/Message.output
	grep -q "State-vector 596 byte, depth reached 8, errors: 1" ${TEST_DIR}/Message.output
	grep -q "3048 states, stored" ${TEST_DIR}/Message.output
	grep -q "172 states, matched" ${TEST_DIR}/Message.output
	grep -q "3220 transitions (= stored+matched)" ${TEST_DIR}/Message.output
	grep -q "0 atomic steps" ${TEST_DIR}/Message.output
	${DELETE_TEST_DIR}

################################BENCHMARK######################################
#Benchmark large message 
#[THIS TEST IS NOT TO BE RUN ON CI AS NOT TO USE UP VALUABLE RESOURCES]
#The message is similar to the one in test_message, but arfificially bloated
#to increase memory consumption
#Messages are passed through channels and processed
#An assert violation is expected to be found
benchmark_large_message:
	echo "Benchmark large message"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run -E -bfs ${USER_TYPES_MODEL_DIR}/LargeMessage.pml > LargeMessage.output	
	grep -q "pan:1: assertion violated (msgIn.payload.readNotif.status==5) (at depth 25)" ${TEST_DIR}/LargeMessage.output
	grep -q "State-vector 832 byte, depth reached 25, errors: 1" ${TEST_DIR}/LargeMessage.output
	grep -q "4742086 states, stored" ${TEST_DIR}/LargeMessage.output
	grep -q "1519620 states, matched" ${TEST_DIR}/LargeMessage.output
	grep -q "6261706 transitions (= stored+matched)" ${TEST_DIR}/LargeMessage.output
	grep -q "0 atomic steps" ${TEST_DIR}/LargeMessage.output
	${DELETE_TEST_DIR}


#################################FLOAT#########################################

#Test float literal values
test_float_literal_values:
	echo "Test float literal values"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_MODEL_DIR}/FloatLiteralValues.pml > FloatLiteralValues.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_MODEL_DIR}/FloatLiteralValues.pml > FloatLiteralValues.sim.output
	grep -q "State-vector 40 byte, depth reached 2, errors: 0" ${TEST_DIR}/FloatLiteralValues.output
	grep -q "3 states, stored" ${TEST_DIR}/FloatLiteralValues.output
	grep -q "0 states, matched" ${TEST_DIR}/FloatLiteralValues.output
	grep -q "3 transitions (= stored+matched)" ${TEST_DIR}/FloatLiteralValues.output
	grep -q "0 atomic steps" ${TEST_DIR}/FloatLiteralValues.output
	grep -q "123 as float = 123.000000" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "43. = 43.000000" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "56.1 = 56.099998" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "56.13 = 56.130001" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "5.2e+1 = 52.000000" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "5.3e+10 = 52999999488.000000" ${TEST_DIR}/FloatLiteralValues.sim.output	
	grep -q "520e-1 = 52.000000" ${TEST_DIR}/FloatLiteralValues.sim.output
	grep -q "3.0e+1/10 + 12.0 - 0.01 = 14.990000" ${TEST_DIR}/FloatLiteralValues.sim.output
	grep -q "3.0e+1 / 10 = 3.000000" ${TEST_DIR}/FloatLiteralValues.sim.output	
	${DELETE_TEST_DIR}

#Test float operators
test_float_arithmetic_operators:
	echo "Test float arithmetic operators"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_MODEL_DIR}/FloatArithmeticOperators.pml > FloatArithmeticOperators.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_MODEL_DIR}/FloatArithmeticOperators.pml > FloatArithmeticOperators.sim.output
	grep -q "State-vector 24 byte, depth reached 2, errors: 0" ${TEST_DIR}/FloatArithmeticOperators.output
	grep -q "Negated 14.250000 == -14.250000" ${TEST_DIR}/FloatArithmeticOperators.sim.output	
	${DELETE_TEST_DIR}

#Test float arithmetic
test_float_arithmetic:
	echo "Test float arithmetic"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_MODEL_DIR}/FloatArithmetic.pml > FloatArithmetic.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_MODEL_DIR}/FloatArithmetic.pml > FloatArithmetic.sim.output
	grep -q "State-vector 44 byte, depth reached 2, errors: 0" ${TEST_DIR}/FloatArithmetic.output
	grep -q "3 states, stored" ${TEST_DIR}/FloatArithmetic.output
	grep -q "0 states, matched" ${TEST_DIR}/FloatArithmetic.output
	grep -q "3 transitions (= stored+matched)" ${TEST_DIR}/FloatArithmetic.output
	grep -q "0 atomic steps" ${TEST_DIR}/FloatArithmetic.output
	grep -q "(+)28.00" ${TEST_DIR}/FloatArithmetic.sim.output	
	grep -q "(-)-4.00" ${TEST_DIR}/FloatArithmetic.sim.output	
	grep -q "(*)192.00" ${TEST_DIR}/FloatArithmetic.sim.output	
	grep -q "(/)0.75" ${TEST_DIR}/FloatArithmetic.sim.output	
	${DELETE_TEST_DIR}

#Test float in struct
test_float_in_struct:
	echo "Test float in struct"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_MODEL_DIR}/FloatInStruct.pml > FloatInStruct.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_MODEL_DIR}/FloatInStruct.pml > FloatInStruct.sim.output
	grep -q "State-vector 28 byte, depth reached 105, errors: 0" ${TEST_DIR}/FloatInStruct.output
	grep -q "106 states, stored" ${TEST_DIR}/FloatInStruct.output
	grep -q "0 states, matched" ${TEST_DIR}/FloatInStruct.output
	grep -q "106 transitions (= stored+matched)" ${TEST_DIR}/FloatInStruct.output
	grep -q "0 atomic steps" ${TEST_DIR}/FloatInStruct.output
	grep -q "Data is 101 and 10.10" ${TEST_DIR}/FloatInStruct.sim.output		
	${DELETE_TEST_DIR}

#Test float dumping 
test_float_can_be_dumped:
	echo "Test float dumping"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_DUMPING_MODEL_DIR}/FloatsCanBeDumped.pml > FloatsCanBeDumped.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_DUMPING_MODEL_DIR}/FloatsCanBeDumped.pml > FloatsCanBeDumped.sim.output
	grep -q "pan:1: invalid end state (at depth 39)" ${TEST_DIR}/FloatsCanBeDumped.output
	grep -q "State-vector 172 byte, depth reached 40, errors: 1" ${TEST_DIR}/FloatsCanBeDumped.output
	grep -q "timeout" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "#processes: 1" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "float_var = 4.830000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "byte_var = 6" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "int_var = 234565" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "float_array\[0\] = 3.140000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "float_array\[1\] = 2.700000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].bit_field = 0" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].byte_field = 9" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].int_field = 3432" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].float_field = 5.560000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[0\].inner_int = 21" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[0\].floats.inner_float_array\[0\] = 0.250000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[0\].floats.inner_float_array\[1\] = 1.500000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[0\].floats.inner_float_array\[2\] = 1.750000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[1\].inner_int = 22" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[0\].inner_float_struct_array\[1\].floats.inner_float_array\[1\] = 2.500000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].bit_field = 1" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].byte_field = 12" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].int_field = 3435" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].float_field = 8.559999" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].inner_float_struct_array\[1\].inner_int = 25" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "item_array\[1\].inner_float_struct_array\[1\].floats.inner_float_array\[1\] = 5.500000" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "queue 2 (struct_channel): \[22,1.250000,2.500000,2.750000\]\[24,3.250000,4.500000,4.750000\]" ${TEST_DIR}/FloatsCanBeDumped.sim.output
	grep -q "FloatsCanBeDumped.pml:79 (state 53)" ${TEST_DIR}/FloatsCanBeDumped.sim.output		
	${DELETE_TEST_DIR}

#Test simple floats through channel 
test_simple_floats_through_channel:
	echo "Test simple floats through channel"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_CHANNEL_MODEL_DIR}/SimpleFloatThroughChannel.pml > SimpleFloatThroughChannel.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_CHANNEL_MODEL_DIR}/SimpleFloatThroughChannel.pml > SimpleFloatThroughChannel.sim.output
	grep -q "errors: 0" ${TEST_DIR}/SimpleFloatThroughChannel.output
	grep -q "first value = 2.700000" ${TEST_DIR}/SimpleFloatThroughChannel.sim.output
	grep -q "second value = 3.140000" ${TEST_DIR}/SimpleFloatThroughChannel.sim.output
	grep -q "2 processes created" ${TEST_DIR}/SimpleFloatThroughChannel.sim.output
	${DELETE_TEST_DIR}

#Test ping pong with floats through channel 
test_ping_pong_with_floats_through_channel:
	echo "Test ping pong with floats through channel"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_CHANNEL_MODEL_DIR}/PingPong.pml > PingPong.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_CHANNEL_MODEL_DIR}/PingPong.pml > PingPong.sim.output
	grep -q "errors: 0" ${TEST_DIR}/PingPong.output
	grep -q "Got pong = 3.141500" ${TEST_DIR}/PingPong.sim.output
	grep -q "2 processes created" ${TEST_DIR}/PingPong.sim.output
	${DELETE_TEST_DIR}

#Test channel with floats enumeration 
test_channel_with_floats_enumeration:
	echo "Test channel with floats enumeration"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run ${FLOAT_CHANNEL_MODEL_DIR}/ChannelsWithFloatsCanBeEnumerated.pml > ChannelsWithFloatsCanBeEnumerated.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_CHANNEL_MODEL_DIR}/ChannelsWithFloatsCanBeEnumerated.pml > ChannelsWithFloatsCanBeEnumerated.sim.output
	grep -q ", errors: 0" ${TEST_DIR}/ChannelsWithFloatsCanBeEnumerated.output
	grep -q "3.140000" ${TEST_DIR}/ChannelsWithFloatsCanBeEnumerated.sim.output
	grep -q "2.700000" ${TEST_DIR}/ChannelsWithFloatsCanBeEnumerated.sim.output
	grep -q "2 processes created" ${TEST_DIR}/ChannelsWithFloatsCanBeEnumerated.sim.output
	${DELETE_TEST_DIR}

#Test complex structures with floats in channels
test_complex_structures_with_floats_in_channels:
	echo "Test complex structures with floats in channels"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	${SPIN} -run -a ${FLOAT_CHANNEL_MODEL_DIR}/ComplexFloatMessage.pml > ComplexFloatMessage.output
	cd ${TEST_DIR} && \
	${SPIN} ${FLOAT_CHANNEL_MODEL_DIR}/ComplexFloatMessage.pml > ComplexFloatMessage.sim.output
	grep -q ", errors: 0" ${TEST_DIR}/ComplexFloatMessage.output
	grep -q "Receiver: index=11, value=0.250000" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "Final message received!" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "queue 1 (queue): \[11,0.250000\]\[11,0.300000\]" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "queue 2 (dqueue): \[0.100000,0.200000,0.300000,0.400000,0.500000,0.600000,0.700000,0.800000,0.900000,0.750000,0,0.000000,52\]\[0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0,5.250000,0\]\[0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,45,0.000000,0\]" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "finalValue = 0.250000" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "finalIndex = 11" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "ComplexFloatMessage.pml:80 (state 25)" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "ComplexFloatMessage.pml:51 (state 25) <valid end state>" ${TEST_DIR}/ComplexFloatMessage.sim.output
	grep -q "ComplexFloatMessage.pml:91 (state 3) <valid end state>" ${TEST_DIR}/ComplexFloatMessage.sim.output
	${DELETE_TEST_DIR}

test_channel_complex_tests_float_basic:
	echo "Test channel complex tests using floats - test-float-basic"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	cp -r ${FLOAT_CHANNEL_COMPLEX_TESTS_DIR}/test-float-basic/*	./
	echo "	test simulator"
	cd ${TEST_DIR} && \
	$(SPIN) system.pml > simulator.stdout
	grep -q "state finished" ${TEST_DIR}/simulator.stdout
	echo "	test verifier"
	cd ${TEST_DIR} && \
	$(SPIN) -a system.pml
	cd ${TEST_DIR} && \
	gcc -o pan pan.c
	cd ${TEST_DIR} && \
	./pan -a -n > verifier.stdout
	grep -q "errors: 0" ${TEST_DIR}/verifier.stdout
	${DELETE_TEST_DIR}

test_channel_complex_tests_float_basic_fail:
	echo "Test channel complex tests using floats - test-float-basic-fail"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	cp -r ${FLOAT_CHANNEL_COMPLEX_TESTS_DIR}/test-float-basic-fail/*	./
	cd ${TEST_DIR} && \
	$(SPIN) -a system.pml
	cd ${TEST_DIR} && \
	gcc -o pan pan.c
	cd ${TEST_DIR} && \
	./pan -a -n > verifier.stdout
	grep -q "errors: 1" ${TEST_DIR}/verifier.stdout
	cd ${TEST_DIR} && \
	${SPIN} -t -r -s system.pml > trace.stdout
	grep -q "3.1415" ${TEST_DIR}/trace.stdout
	${DELETE_TEST_DIR}

test_channel_complex_tests_float_compare:
	echo "Test channel complex tests using floats - test-float-compare"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	cp -r ${FLOAT_CHANNEL_COMPLEX_TESTS_DIR}/test-float-compare/*	./
	echo "	test simulator"
	cd ${TEST_DIR} && \
	$(SPIN) system.pml > simulator.stdout
	grep -q "state finished" ${TEST_DIR}/simulator.stdout
	echo "	test verifier"
	cd ${TEST_DIR} && \
	$(SPIN) -a system.pml
	cd ${TEST_DIR} && \
	gcc -o pan pan.c
	cd ${TEST_DIR} && \
	./pan -a -n > verifier.stdout
	grep -q "errors: 0" ${TEST_DIR}/verifier.stdout
	${DELETE_TEST_DIR}

test_channel_complex_tests_float_operations:
	echo "Test channel complex tests using floats - test-float-operations"
	${CREATE_TEST_DIR}
	cd ${TEST_DIR} && \
	cp -r ${FLOAT_CHANNEL_COMPLEX_TESTS_DIR}/test-float-operations/*	./
	echo "	test simulator"
	cd ${TEST_DIR} && \
	$(SPIN) system.pml > simulator.stdout
	grep -q "state finished" ${TEST_DIR}/simulator.stdout
	echo "	test verifier"
	cd ${TEST_DIR} && \
	$(SPIN) -a system.pml
	cd ${TEST_DIR} && \
	gcc -o pan pan.c
	cd ${TEST_DIR} && \
	./pan -a -n > verifier.stdout
	grep -q "errors: 0" ${TEST_DIR}/verifier.stdout
	${DELETE_TEST_DIR}
