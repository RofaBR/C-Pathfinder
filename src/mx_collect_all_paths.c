#include "../inc/files.h"

int mx_is_duplicate_path(t_path *path, t_list *list) {
    while (list) {
        t_path *existing_path = (t_path *)list->data;

        if (existing_path->count == path->count && existing_path->length == path->length) {
            bool is_same = true;
            bool is_reverse = true;


            for (int i = 0; i < path->count; i++) {
                if (existing_path->islands[i] != path->islands[i]) {
                    is_same = false;
                }
                if (existing_path->islands[i] != path->islands[path->count - i - 1]) {
                    is_reverse = false;
                }
            }

            if (is_same || is_reverse) {
                return 1;
            }
        }

        list = list->next;
    }
    return 0;
}

static void mx_collect_paths_recursive(t_graph *graph, int src, int dest, int *visited, t_path *path, int max_length, t_list **all_paths_list) {
    visited[src] = 1;
    path->islands[path->count++] = src;

    if (src == dest && path->length <= max_length) {
        t_path *new_path = (t_path *)malloc(sizeof(t_path));
        new_path->islands = (int *)malloc(path->count * sizeof(int));
        for (int i = 0; i < path->count; i++) {
            new_path->islands[i] = path->islands[i];
        }
        new_path->length = path->length;
        new_path->count = path->count;

        if (!mx_is_duplicate_path(new_path, *all_paths_list)) {
            mx_push_front(all_paths_list, new_path);
        } else {
            free(new_path->islands);
            free(new_path);
        }
    } else {
        t_bridge *bridge = graph->islands[src]->bridges;
        while (bridge) {
            int next = bridge->destination->index;

            if (!visited[next] && path->length + bridge->length <= max_length) {
                path->length += bridge->length;
                mx_collect_paths_recursive(graph, next, dest, visited, path, max_length, all_paths_list);
                path->length -= bridge->length;
            }
            bridge = bridge->bridges;
        }
    }

    path->count--;
    visited[src] = 0; 
}

void mx_collect_all_paths(t_graph *graph, int src, int dest, int max_length, t_list **all_paths_list) {
    int visited[graph->num_islands];
    t_path current_path;
    current_path.islands = (int *)malloc(graph->num_islands * sizeof(int));
    current_path.length = 0;
    current_path.count = 0;

    for (int i = 0; i < graph->num_islands; i++) {
        visited[i] = 0;
    }

    mx_collect_paths_recursive(graph, src, dest, visited, &current_path, max_length, all_paths_list);

    free(current_path.islands);
}

