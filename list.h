#ifndef _LIST_H
# define _LIST_H

typedef struct List {
	int val;
	struct List *next;
} List;

List *add(List *, int);
void clear(List *);

#endif
