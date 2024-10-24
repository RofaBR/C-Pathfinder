#include "../inc/files.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr_ms(ERR_USAGE, NULL);
        exit(-1);
    }

    t_graph *graph = mx_read_file(argv[1]);
    mx_find_all_shortest_paths(graph);
    mx_free_graph(graph);

    return 0;
}

