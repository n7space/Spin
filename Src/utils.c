#include "utils.h"
#include "spin.h"

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
		return 0;

	if (s->context && s->type)
		s = findloc(s);		/* it's a local var */

	if (!s)
	{	
        return token->sym->type;
	}

	if (!s->type)	/* not a local name */
		s = lookup(s->name);	/* must be a global */

	if (!s->type)
	{	
        return INT;
	}
	
	if (!s->owner)
	{	
        if (s->context
		||  strcmp(s->name, "_p") == 0
		||  strcmp(s->name, "_pid") == 0
		||  strcmp(s->name, "_priority") == 0)
		{	
            return INT;
		}         
    }

	if (is_typedef(s->type) && token->rgt && token->rgt->lft)
	{	
        return getType(token->rgt->lft);
	}
    return s->type;
}

unsigned short
getType(const Lextok *const token) {
    if (token == NULL)
        return 0;
    const unsigned short result = getTypeInternal(token); 
#ifdef DEBUG
    const char* name = token->sym != NULL ? token->sym->name : "[unnamed]";
    printf("Token %s type resolved to %d\n", name, result);
#endif
    return result;
}
