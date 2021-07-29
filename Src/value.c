#include "value.h"

int
isLeftValueLargerOrEqual(const Value a, const Value b)
{
	if ((a.kind == VALUE_INT) && (b.kind == VALUE_INT)) {
		return a.value.intValue >= b.value.intValue;
	}
	return getFloat(a) >= getFloat(b);
}

int
isLeftValueLarger(const Value a, const Value b)
{
	if ((a.kind == VALUE_INT) && (b.kind == VALUE_INT)) {
		return a.value.intValue > b.value.intValue;
	}
	return getFloat(a) > getFloat(b);
}

int
areValuesEqual(const Value a, const Value b)
{
	if (a.kind != b.kind)
		return 0;
	if (a.kind == VALUE_INT)
		return a.value.intValue == b.value.intValue;
	return a.value.floatValue == b.value.floatValue;
}

int
isValueEqual(const Value a, const int b) {

	if (a.kind == VALUE_INT)
		return a.value.intValue == b;
	return getInt(a) == b;
}

Value
intValue(const int value)
{
	Value result;
	result.kind = VALUE_INT;
	result.value.intValue = value;
	return result;
}

Value
floatValue(const float value)
{
	Value result;
	result.kind = VALUE_FLOAT;
	result.value.floatValue = value;
	return result;
}

float
getFloat(const Value value)
{
	switch (value.kind) {
		case VALUE_FLOAT:
			return value.value.floatValue;
		case VALUE_INT:
			return (float)value.value.intValue;
	}
	return 0.0f;
}

int
getInt(const Value value)
{
	switch (value.kind) {
		case VALUE_FLOAT:
			return (int)value.value.floatValue;
		case VALUE_INT:
			return value.value.intValue;
	}
	return 0;
}

int
isAnyFloat(const Value a, const Value b)
{
	return (a.kind == VALUE_FLOAT || b.kind == VALUE_FLOAT);
}
