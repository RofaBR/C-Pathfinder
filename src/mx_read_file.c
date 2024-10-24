#include "../inc/files.h"

t_graph *mx_read_file(const char *filename) {
    char *str_file = mx_file_to_str(filename);

    if (str_file == NULL) {
        mx_printerr_ms(ERR_FILE_NOT_EXIST, filename);
        exit(-1);
    }

    if (mx_strlen(str_file) == 0) {
        free(str_file);
        mx_printerr_ms(ERR_FILE_EMPTY, filename);
        exit(-1);
    }

    char **lines = mx_strsplit(str_file, '\n');
    free(str_file);
    int num_islands = mx_atoi(lines[0]);
     
    if (num_islands <= 0) {
        mx_del_strarr(&lines);
        mx_printerr_ms(ERR_INVALID_LINE, "1");
        exit(-1);
    }
    
    mx_validation(lines, num_islands);
    t_graph *graph = mx_create_graph(num_islands);
    mx_fill_graph(graph, lines);

    return graph;
}


