#ifndef _LIST_H
# define _LIST_H

typedef struct List {
	int val;
	struct List *next;
} List;

List *add(List *, int);
void free_list(List *);

#endif
