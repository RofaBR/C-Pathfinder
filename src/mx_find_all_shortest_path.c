#include "../inc/files.h"

void mx_find_all_shortest_paths(t_graph *graph) {
    int dist[graph->num_islands];
    int **previous_lists = malloc(graph->num_islands * sizeof(int*));
    int* previous_counts = malloc(graph->num_islands * sizeof(int)); 
    t_list *all_paths_list = NULL;

    for (int i = 0; i < graph->num_islands; i++) {
        previous_lists[i] = (int *)malloc(graph->num_islands * sizeof(int));
    }

    for (int i = 0; i < graph->num_islands; i++) {
        mx_dijkstra(graph, i, dist, previous_lists, previous_counts);

        for (int j = 0; j < graph->num_islands; j++) {
            if (i != j && dist[j] < INT_MAX) {
                mx_collect_all_paths(graph, i, j, dist[j], &all_paths_list);
            }
        }
    }

    for (int i = 0; i < graph->num_islands; i++) {
        for (int j = 0; j < graph->num_islands; j++) {
            if (i == j) continue;

            t_list *current = all_paths_list;
            while (current) {
                t_path *path = (t_path *)current->data;
                if (path->islands[0] == i && path->islands[path->count - 1] == j) {
                    mx_print_single_path(graph, path);
                }
                current = current->next;
            }
        }
    }

    for (int i = 0; i < graph->num_islands; i++) {
        free(previous_lists[i]);
    }
    free(previous_lists); 
    free(previous_counts);

    mx_free_list(all_paths_list);
}

