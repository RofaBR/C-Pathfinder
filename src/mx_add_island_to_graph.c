#include "../inc/files.h"

void mx_add_island_to_graph(t_graph *graph, char *name, int index) {
    t_island * new_island = (t_island *)malloc(sizeof(t_island));
    new_island->index = index;
    new_island->name = mx_strdup(name);
    new_island->bridges = NULL;

    graph->islands[index] = new_island;
}

