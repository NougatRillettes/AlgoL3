#ifndef _SET_H
# define _SET_H

#include <stdbool.h>

typedef struct Set {
	int size, nelem;
	bool *elem;
} Set;

void free_set(Set *);
Set *empty_set(int); /* Size of the set */
Set *inter(Set *, Set *);

void print_set(Set *);

#endif
