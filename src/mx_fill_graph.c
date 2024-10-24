#include "../inc/files.h"

void mx_fill_graph(t_graph *graph, char **lines) {
    int island_counter = 0;
    long total_length = 0;

    for (int i = 1; lines[i] != NULL; i++) {
        char **parts = mx_strsplit(lines[i], '-');
        char *island1 = parts[0];
        char *island2_length = parts[1];
        char **island2_and_length = mx_strsplit(island2_length, ',');
        char *island2 = island2_and_length[0];
        int length = mx_atoi(island2_and_length[1]);

        if (mx_find_island_index(graph, island1) == -1) {
            mx_add_island_to_graph(graph, island1, island_counter++);
        }

        if (mx_find_island_index(graph, island2) == -1) {
            mx_add_island_to_graph(graph, island2, island_counter++);
        }

        int island1_index = mx_find_island_index(graph, island1);
        int island2_index = mx_find_island_index(graph, island2);

        if (island1_index != -1 && island2_index != -1) {
            t_island *island1_ptr = graph->islands[island1_index];

            bool duplicate_found = false;
            for (t_bridge *current = island1_ptr->bridges; current; current = current->bridges) {
                if (mx_strcmp(current->destination->name, island2) == 0) {
                    duplicate_found = true;
                    break;
                }
            }

            if (duplicate_found) {
                mx_del_strarr(&parts);
                mx_del_strarr(&island2_and_length);
                mx_del_strarr(&lines);
                mx_free_graph(graph);
                mx_printerr_ms(ERR_DUPLICATE_BRIDGES, NULL);
                exit(-1);
            }

            total_length += length;
            if (total_length > INT_MAX) {
                mx_del_strarr(&parts);
                mx_del_strarr(&island2_and_length);
                mx_del_strarr(&lines);
                mx_free_graph(graph);
                mx_printerr_ms(ERR_SUM_TOO_BIG, NULL);
                exit(-1);
            }
            mx_add_bridge_to_graph(graph, island1, island2, length);
        }

        mx_del_strarr(&parts);
        mx_del_strarr(&island2_and_length);
    }

    mx_del_strarr(&lines);
}


