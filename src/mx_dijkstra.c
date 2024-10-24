#include "../inc/files.h"

void mx_dijkstra(t_graph *graph, int src, int *dist, int **previous_lists, int *previous_counts) {
    bool* sptSet = malloc(graph->num_islands * sizeof(bool));

    for (int i = 0; i < graph->num_islands; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        previous_counts[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < graph->num_islands - 1; count++) {
        int u = mx_min_distance(dist, sptSet, graph->num_islands);
        sptSet[u] = true;

        t_island *current_island = graph->islands[u];
        t_bridge *bridge = current_island->bridges;

        while (bridge) {
            int v = bridge->destination->index;
            int length = bridge->length;

            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + length <= dist[v]) {
                if (dist[u] + length < dist[v]) {
                    dist[v] = dist[u] + length;
                    previous_counts[v] = 0;
                }

                previous_lists[v][previous_counts[v]++] = u;
            }

            bridge = bridge->bridges;
        }
    }
    free(sptSet);  
}

