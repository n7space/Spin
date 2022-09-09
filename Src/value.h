/***** spin: value.h *****/

/*
 * This file is part of the public release of Spin. It is subject to the
 * terms in the LICENSE file that is included in this source directory.
 * Tool documentation is available at http://spinroot.com
 */

#ifndef SEEN_VALUE_H
#define SEEN_VALUE_H

/* Types of primitives held in Value type - test_loops fails if in other sequence - TODO - verify why */
typedef enum {VALUE_INT, VALUE_FLOAT} ValueKind;

/* Variant type */
typedef struct {
	ValueKind kind; /* Type of the primitive*/
	union {
		int intValue; /* Integer primitive value */
		float floatValue; /* Float primitive value */
	} value;
} Value;

int isValueEqual(const Value a, const int b);
int areValuesEqual(const Value a, const Value b);
int isLeftValueLargerOrEqual(const Value a, const Value b);
int isLeftValueLarger(const Value a, const Value b);
Value intValue(const int value);
Value floatValue(const float value);
float getFloat(const Value value);
int getInt(const Value value);
int isAnyFloat(const Value a, const Value b);

#endif
