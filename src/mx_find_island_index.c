#include "../inc/files.h"

int mx_find_island_index(t_graph *graph, char *name) {
    for (int i = 0; i < graph->num_islands; i++) {
        if (graph->islands[i] && mx_strcmp(graph->islands[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}
