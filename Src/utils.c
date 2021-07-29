#include "utils.h"
#include "spin.h"

int is_typedef(const unsigned short type) {
    return (type == STRUCT) || (type == UNION_STRUCT);
}
