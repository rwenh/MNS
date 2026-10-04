#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H

#include <stdbool.h>

typedef struct GraphNode {
    int dest;
    int weight;
    struct GraphNode *next;
} GraphNode;

typedef struct {
    int num_vertices;
    GraphNode **adj_lists;
} Graph;

Graph* graph_create(int vertices);
void graph_free(Graph *g);
void graph_add_edge(Graph *g, int src,  int dest, int weight);

void graph_bfs(const Graph *g, int start_vertex);
void graph_dfs(const Graph *g, int start_vertex);
void graph_dijkstra(const Graph *g, int start_vertex);

#endif
