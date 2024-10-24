#include "../inc/files.h"

static void add_bridge(t_island *from, t_island *to, int length) {
    t_bridge *new_bridge = (t_bridge *)malloc(sizeof(t_bridge));
    new_bridge->destination = to;
    new_bridge->length = length;
    new_bridge->bridges = from->bridges;
    from->bridges = new_bridge;
}

void mx_add_bridge_to_graph(t_graph *graph, char *island1_name, char *island2_name, int length) {
    t_island *island1 = NULL;
    t_island *island2 = NULL;

    for (int i = 0; i < graph->num_islands && (!island1 || !island2); i++) {
        if (!island1 && graph->islands[i] && mx_strcmp(graph->islands[i]->name, island1_name) == 0) {
            island1 = graph->islands[i];
        }
        if (!island2 && graph->islands[i] && mx_strcmp(graph->islands[i]->name, island2_name) == 0) {
            island2 = graph->islands[i];
        }
    }

    if (island1 && island2) {
        add_bridge(island1, island2, length);
        add_bridge(island2, island1, length);
    }
}
