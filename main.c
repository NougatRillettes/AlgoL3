#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"

Graph* init() {
	Graph *g = malloc(sizeof(Graph));
	scanf("%d%d", &g->vertices, &g->edges);
	g->adj = calloc(g->vertices, sizeof(List *));
	for (int i = 0; i < g->vertices; i++)
		g->adj[i] = NULL;
	for (int i = 0; i < g->edges; i++) {
		int b, e;
		scanf("%d%d", &b, &e);
		g->adj[b] = add(g->adj[b], e);
	}
	return g;
}

void clean_exit(Graph *g) {
	for (int i = 0; i < g->vertices; g++)
		clear(g->adj[i]);
	free(g);
}

int main(int argc, const char *argv[]) {
	Graph *g = init();
	clean_exit(g);
	return 0;
}

/* Test code, which doesn't segfault */
/*
int main(void) { 
	Graph *g = malloc(sizeof(Graph));
	int k;
	scanf("%d", &k);
	g->vertices = k;
	g->adj = calloc(g->vertices, sizeof(List *));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < (i+1)*k; j++)
			g->adj[i] = add(g->adj[i], j);
	for (int i = 0; i < k; i++) {
		List *l = g->adj[i];
		while (l) {
			printf("%d ", l->val);
			l = l->next;
		}
		printf("\n");
	}
	for (int i = 0; i < k; i++)
		clear(g->adj[i]);
	free(g);
	return 0;
}
*/
