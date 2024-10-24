#include "../inc/files.h"

static void print_boundary(void) {
    for (int i = 0; i < 40; i++) {
        mx_printchar('=');
    }
    mx_printchar('\n');
}

void mx_print_single_path(t_graph *graph, t_path *path) {
    print_boundary();

    mx_printstr("Path: ");
    mx_printstr(graph->islands[path->islands[0]]->name);
    mx_printstr(" -> ");
    mx_printstr(graph->islands[path->islands[path->count - 1]]->name);
    mx_printchar('\n');

    mx_printstr("Route: ");
    for (int i = 0; i < path->count; i++) {
        mx_printstr(graph->islands[path->islands[i]]->name);
        if (i < path->count - 1) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');

    mx_printstr("Distance: ");
    if (path->count == 2) {
        mx_printint(path->length);
    } else {
        int total_distance = 0;
        for (int i = 0; i < path->count - 1; i++) {
            int from = path->islands[i];
            int to = path->islands[i + 1];
            t_bridge *bridge = graph->islands[from]->bridges;

            while (bridge) {
                if (bridge->destination->index == to) {
                    mx_printint(bridge->length);
                    total_distance += bridge->length;
                    if (i < path->count - 2) {
                        mx_printstr(" + ");
                    }
                    break;
                }
                bridge = bridge->bridges;
            }
        }
        mx_printstr(" = ");
        mx_printint(total_distance);
    }
    mx_printchar('\n');

    print_boundary();
}

