#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "set.h"

void backtrack(Graph *graph, Set *cur, Set *cands, Set *rem, Set *ans) {
	if (cands->nelem == 0) {
		if (cur->nelem > ans->nelem) {
			ans->nelem = cur->nelem;
			for (int i = 0; i < graph->vertices; i++)
				ans->elem[i] = cur->elem[i];
		}
		return;
	}
	for (int i = 0; i < graph->vertices; i++)
		if (cands->elem[i]) {
			Set *new_cands = inter(cands, graph->adj[i]);
			Set *new_rem = inter(rem, graph->adj[i]);
			cur->elem[i] = true;
			cur->nelem++;

			backtrack(graph, cur, new_cands, new_rem, ans);

			cur->elem[i] = false;
			cur->nelem--;
			free_set(new_cands);
			free_set(new_rem);
			cands->elem[i] = false;
			cands->nelem--;
		}
}

Set *max_clique(Graph *graph) {
	Set *ans = empty_set(graph->vertices);
	Set *cur = empty_set(graph->vertices);
	Set *cands = empty_set(graph->vertices);
	Set *rem = empty_set(graph->vertices);

	cands->nelem = rem->nelem = graph->vertices;
	for (int i = 0; i < graph->vertices; i++)
		cands->elem[i] = rem->elem[i] = true;

	backtrack(graph, cur, cands, rem, ans);

	free_set(cur);
	free_set(cands);
	free_set(rem);

	return ans;
}

int main(int argc, const char *argv[]) {
	Graph *g = init_graph();
	Graph *comp = complement(g);
	Set *clique = max_clique(comp);

	print_graph(g);
	print_graph(comp);

	for (int i = 0; i < clique->size; i++)
		clique->elem[i] = !clique->elem[i];
	print_set(clique);

	free_set(clique);
	free_graph(comp);
	free_graph(g);

	return 0;
}
