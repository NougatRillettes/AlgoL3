#include <stdlib.h>
#include "list.h"

List* add(List *l, int k) {
	List *nouv = malloc(sizeof(List));
	nouv->next = l;
	nouv->val = k;
	return nouv;
}

void free_list(List *l) {
	while (l) {
		List *tmp = l->next;
		free(l);
		l = tmp;
	}
}
