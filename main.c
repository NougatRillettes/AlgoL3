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
	for (int i = 0; i < g->vertices; i++)
		clear(g->adj[i]);
        free(g->adj);
        free(g);
}

int main(int argc, const char *argv[]) {
	Graph *g = init();
	clean_exit(g);
	return 0;
}
