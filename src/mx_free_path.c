#include "../inc/files.h"

static void mx_free_path(t_path *path) {
    if (path->islands != NULL) {
        free(path->islands);
    }
    path->islands = NULL;
}

void mx_free_all_paths(t_path *all_paths, int path_count) {
    for (int i = 0; i < path_count; i++) {
        mx_free_path(&all_paths[i]);
    }
}

