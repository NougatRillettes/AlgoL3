#ifndef _GRAPH_H
# define _GRAPH_H

#include "list.h"
#include "set.h"

typedef struct {
	int vertices, edges;
	Set **adj;
} Graph;

Graph *init_graph(void);
void free_graph(Graph *);

Graph *complement(Graph *);
void print_graph(Graph *);

#endif
