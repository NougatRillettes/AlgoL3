#ifndef _GRAPH_H
# define _GRAPH_H

#include "list.h"

typedef struct {
	int vertices, edges;
	List **adj;
} Graph;

#endif
