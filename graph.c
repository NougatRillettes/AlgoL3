#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "set.h"
#include "list.h"

Graph* init_graph() {
	Graph *graph = malloc(sizeof(Graph));

	scanf("%d%d", &graph->vertices, &graph->edges);
	graph->adj = calloc(graph->vertices, sizeof(List *));

	for (int i = 0; i < graph->vertices; i++)
		graph->adj[i] = empty_set(graph->vertices);

	for (int i = 0; i < graph->edges; i++) {
		int begin, end;
		scanf("%d%d", &begin, &end);
		graph->adj[begin]->nelem++;
		graph->adj[begin]->elem[end] = true;
		graph->adj[end]->nelem++;
		graph->adj[end]->elem[begin] = true;
	}

	graph->edges *= 2; /* The graph is undirected */

	return graph;
}

void free_graph(Graph *graph) {
	for (int i = 0; i < graph->vertices; i++)
		free_set(graph->adj[i]);

    free(graph->adj);
    free(graph);
}

Graph *complement(Graph *graph) { /* Without self-pointing edges */
	Graph *new = malloc(sizeof(Graph));

	new->vertices = graph->vertices;
	new->edges = (graph->vertices*graph->vertices)-graph->edges-graph->vertices;
	new->adj = calloc(new->vertices, sizeof(Set *));

	for (int i = 0; i < new->vertices; i++) {
		new->adj[i] = empty_set(new->vertices);
		new->adj[i]->nelem = graph->vertices - graph->adj[i]->nelem - 1;
		for (int j = 0; j < new->vertices; j++)
			if (!graph->adj[i]->elem[j] && j != i)
				new->adj[i]->elem[j] = true;
	}
	return new;
}

void print_graph(Graph *graph) {
	printf("Vertices: %d\nEdges: %d\n", graph->vertices, graph->edges);
	for (int i = 0; i < graph->vertices; i++)
		for (int j = i+1; j < graph->vertices; j++)
			if (graph->adj[i]->elem[j])
				printf("%d %d\n", i, j);
}
