/***** spin: utils.h *****/

/*
 * This file is part of the public release of Spin. It is subject to the
 * terms in the LICENSE file that is included in this source directory.
 * Tool documentation is available at http://spinroot.com
 */

#ifndef SEEN_UTILS_H
#define SEEN_UTILS_H

typedef struct Lextok Lextok;

int is_typedef(const unsigned short type);
unsigned short getType(const Lextok *const token);

#endif
