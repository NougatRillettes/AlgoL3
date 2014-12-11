#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set *empty_set(int size) {
	Set *s = malloc(sizeof(Set));
	s->size = size;
	s->nelem = 0;
	s->elem = calloc(size, sizeof(bool));
	return s;
}

void free_set(Set *s) {
	free(s->elem);
	free(s);
}

void print_set(Set *s) {
	printf("Elements: %d\n", s->nelem);
	for (int i = 0; i < s->size; i++)
		if (s->elem[i])
			printf("%d ", i);
	printf("\n");
}

Set *inter(Set *s1, Set *s2) { /* We assume s1->size equals s2->size */
	Set *ans = empty_set(s1->size);
	for (int i = 0; i < ans->size; i++)
		if (s1->elem[i] && s2->elem[i]) {
			ans->elem[i] = true;
			ans->nelem++;
		}
	return ans;
}

Set *minus(Set *s1, Set *s2) { /* Returns s1 \ s2 */
	Set *ans = empty_set(s1->size);
	for (int i = 0; i < ans->size; i++)
		if (s1->elem[i] && !s2->elem[i]) {
			ans->elem[i] = true;
			ans->nelem++;
		}
	return ans;
}
