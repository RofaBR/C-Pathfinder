#include "../inc/files.h"

void mx_free_graph(t_graph *graph) {
    
    for (int i = 0; i < graph->num_islands; i++) {
        t_island *island = graph->islands[i];
        if (graph->islands[i]) {
            free(island->name);

            t_bridge *bridge = island->bridges;
            while (bridge) {
                t_bridge *temp = bridge;
                bridge = bridge->bridges;
                free(temp);
            }

            free(island);
        }
    }
    free(graph->islands);
    free(graph);
}

