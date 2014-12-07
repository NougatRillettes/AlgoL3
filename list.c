#include <stdlib.h>
#include "list.h"

List* add(List *l, int k) {
	List *nouv = malloc(sizeof(List));
	nouv->next = l;
	nouv->val = k;
	return nouv;
}

void clear(List *l) {
	while (l != NULL) {
		List *tmp = l->next;
		free(l);
		l = tmp;
	}
}
