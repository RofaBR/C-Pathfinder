#ifndef FILES_H
#define FILES_H

#include "../libmx/inc/libmx.h"

typedef enum e_error {
    ERR_USAGE,
    ERR_FILE_NOT_EXIST,
    ERR_FILE_EMPTY,
    ERR_INVALID_LINE,
    ERR_INVALID_NUM_ISLANDS,
    ERR_DUPLICATE_BRIDGES,
    ERR_SUM_TOO_BIG
}           t_error;

typedef struct s_island t_island;
typedef struct s_bridge t_bridge;
typedef struct s_graph t_graph;
typedef struct s_path t_path;

typedef struct s_bridge {
    t_island *destination;
    int length;
    t_bridge *bridges;
}              t_bridge;

typedef struct s_island {
    int index;
    char *name;
    t_bridge *bridges;
}              t_island;

typedef struct s_graph {
    t_island **islands;      
    int num_islands; 
}              t_graph;

typedef struct s_path {
    int *islands;
    int length;
    int count;
} t_path;   

t_graph *mx_create_graph(int num_islands);
void mx_add_island_to_graph(t_graph *graph, char *name, int index);
void mx_add_bridge_to_graph (t_graph *graph, char *island1_name, char *island2_name, int length);
void mx_free_graph(t_graph *graph);
void mx_free_all_paths(t_path *all_paths, int path_count);

t_graph *mx_read_file(const char *file_content);
void mx_validation(char **lines, int num_islands);
void mx_fill_graph(t_graph *graph, char **lines);

void mx_dijkstra(t_graph *graph, int src, int *dist, int **previous_lists, int *previous_counts);
int mx_min_distance(int dist[], bool sptSet[], int num_islands);

void mx_find_all_shortest_paths(t_graph *graph);
int mx_find_island_index(t_graph *graph, char *name);
bool mx_is_valid_island_name(const char *name);
void mx_collect_all_paths(t_graph *graph, int src, int dest, int max_length, t_list **all_paths_list);
void mx_print_single_path(t_graph *graph, t_path *path);
void mx_free_list(t_list *list);
void mx_printerr_ms(t_error err, const char *s);

#endif

