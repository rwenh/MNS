#include "dsa/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

Graph* graph_create(int vertices) {
    if (vertices <= 0) return NULL;
    Graph *g = malloc(sizeof(Graph));
    if (!g) return NULL;
    g->num_vertices = vertices;
    g->adj_lists = malloc(sizeof(GraphNode*) * vertices);
    if (!g->adj_lists) {
        free(g);
        return NULL;
    }
    for (int i = 0; i < vertices; i++) {
        g->adj_lists[i] = NULL;
    }
    return g;
}

void graph_free(Graph *g) {
    if (!g) return;
    for (int i = 0; i < g->num_vertices; i++) {
        GraphNode *curr = g->adj_lists[i];
        while (curr) {
            GraphNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g->adj_lists);
    free(g);
}

void graph_add_edge(Graph *g, int src, int dest, int weight) {
    if (!g || src < 0 || src >= g->num_vertices ||
        dest < 0 || dest >= g->num_vertices) return;
    GraphNode *node = malloc(sizeof(GraphNode));
    if (!node) return;
    node->dest = dest;
    node->weight = weight;
    node->next = g->adj_lists[src];
    g->adj_lists[src] = node;
}

void graph_bfs(const Graph *g, int start_vertex) {
    if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return;

    bool *visited = calloc(g->num_vertices, sizeof(bool));
    int *queue = malloc(sizeof(int) * g->num_vertices);
    if (!visited || !queue) {
        free(visited);
        free(queue);
        return;
    }

    int front = 0, rear = 0;
    visited[start_vertex] = true;
    queue[rear++] = start_vertex;

    printf("BFS starting from %d: ", start_vertex);
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        GraphNode *temp = g->adj_lists[curr];
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

static void dfs_util(const Graph *g, int v, bool *visited) {
    visited[v] = true;
    printf("%d ", v);

    GraphNode *temp = g->adj_lists[v];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs_util(g, temp->dest, visited);
        }
        temp = temp->next;
    }
}

void graph_dfs(const Graph *g, int start_vertex) {
    if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return;

    bool *visited = calloc(g->num_vertices, sizeof(bool));
    if (!visited) return;

    printf("DFS starting from %d: ", start_vertex);
    dfs_util(g, start_vertex, visited);
    printf("\n");
    free(visited);
}

void graph_dijkstra(const Graph *g, int start_vertex) {
    if (!g || start_vertex < 0 || start_vertex >= g->num_vertices) return;

    int *dist = malloc(sizeof(int) * g->num_vertices);
    bool *spt_set = calloc(g->num_vertices, sizeof(bool));
    if (!dist || !spt_set) {
        free(dist);
        free(spt_set);
        return;
    }

    for (int i = 0; i < g->num_vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[start_vertex] = 0;

    for (int count = 0; count < g->num_vertices - 1; count++) {
        int min = INT_MAX, min_index = -1;
        for (int v = 0; v < g->num_vertices; v++) {
            if (!spt_set[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        if (min_index == -1) break;
        spt_set[min_index] = true;

        GraphNode *temp = g->adj_lists[min_index];
        while (temp) {
            int v = temp->dest;
            if (!spt_set[v] && dist[min_index] != INT_MAX &&
                dist[min_index] + temp->weight < dist[v]) {
                dist[v] = dist[min_index] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Dijkstra Shortest Distances from node %d:\n", start_vertex);
    for (int i = 0; i < g->num_vertices; i++) {
        if (dist[i] == INT_MAX) {
            printf("Node %d : INF\n", i);
        } else {
            printf("Node %d : %d\n", i, dist[i]);
        }
    }

    free(dist);
    free(spt_set);
}
