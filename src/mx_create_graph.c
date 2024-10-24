#include "../inc/files.h"

t_graph *mx_create_graph(int num_islands) {
    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    graph->num_islands = num_islands;
    graph->islands = (t_island **)malloc(num_islands * sizeof(t_island *));

    for (int i = 0; i < num_islands; i++) {
        graph->islands[i] = NULL;
    }

    return graph;
}

