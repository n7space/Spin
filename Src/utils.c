#include "utils.h"
#include "spin.h"

static const char* STRING_NULL = "NULL";
static const char* STRING_STRUCT = "struct";
static const char* STRING_UNION_STRUCT = "union";
static const char* STRING_FLOAT = "float";
static const char* STRING_INT = "int";
static const char* STRING_SHORT = "short";
static const char* STRING_BYTE = "byte";
static const char* STRING_BIT = "bit";
static const char* STRING_UNSIGNED = "unsigned";
static const char* STRING_UNKNOWN = "unknown";

// This needs to be accessed from sym.c
extern Symbol *context;

int
is_typedef(const unsigned short type) {
    return (type == STRUCT) || (type == UNION_STRUCT);
}

static unsigned short
getTypeInternal(const Lextok *const token) {
    // This is based on the putname function, with hopefully
    // all the unncecessary stuff removed.
    Symbol *s = token->sym;

	if (!s)
	{
		if (token->constValKind == VALUE_FLOAT)
		{	return FLOAT;
		}
		else
		{	return 0;
		}
	}
	if (s->context && context && s->type)
		s = findloc(s);		/* it's a local var */

	if (!s)
	{
#ifdef DEBUG
		printf("getTypeInternal: Fallback to symbol\n");
#endif
        return token->sym->type;
	}

	if (!s->type)	/* not a local name */
		s = lookup(s->name);	/* must be a global */

	if (!s->type)
	{
#ifdef DEBUG
		printf("getTypeInternal: Fallback to default INT\n");
#endif
        return INT;
	}

	if (is_typedef(s->type) && token->rgt && token->rgt->lft)
	{
#ifdef DEBUG
		printf("getTypeInternal: Resolution via typedef\n");
#endif
        return getType(token->rgt->lft);
	}
    return s->type;
}

static inline const char*
getTypeName(const unsigned short type) {
	switch (type) {
		case UNSIGNED:
			return STRING_UNSIGNED;
		case BIT:
			return STRING_BIT;
		case BYTE:
			return STRING_BYTE;
		case SHORT:
			return STRING_SHORT;
		case INT:
			return STRING_INT;
		case FLOAT:
			return STRING_FLOAT;
		case STRUCT:
			return STRING_STRUCT;
		case UNION_STRUCT:
			return STRING_UNION_STRUCT;
	}
	return STRING_UNKNOWN;
}

unsigned short
getType(const Lextok *const token) {
    if (token == NULL)
        return 0;
    const unsigned short result = getTypeInternal(token);
#ifdef DEBUG
	printLextok(token);
    const char* name = token->sym != NULL ? token->sym->name : "[unnamed]";
    printf("getTypeInternal: Token [%s] type resolved to [%s]\n", name, getTypeName(result));
#endif
    return result;
}

static inline const char*
getLextokSymbolName(const Lextok *const token) {
	if ((token == NULL) || (token->sym == NULL))
		return STRING_NULL;
	return token->sym->name;
}

static inline void
printLextokInternal(const Lextok *const token){
	if (token == NULL)
		return;
	printf("[");
	printLextokInternal(token->lft);
	printf("]%s[", getLextokSymbolName(token));
	printLextokInternal(token->rgt);
	printf("]");
}

void
printLextok(const Lextok *const token) {
	if (token == NULL)
	{
		printf("Token NULL: N/A\n");
		return;
	}
	printf("Token %s: ", getLextokSymbolName(token));
	printLextokInternal(token);
	printf("\n");
}