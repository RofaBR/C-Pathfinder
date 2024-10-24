#include "../inc/files.h"

static void free_islands(char **islands, int island_count) {
    for (int i = 0; i < island_count; i++) {
        free(islands[i]);
    }
}

static void mx_printerr_clean(t_error err, const char *msg, char **parts, char **island2_and_length, char **lines) {
    if (parts != NULL) 
        mx_del_strarr(&parts);
    
    if (island2_and_length != NULL) 
        mx_del_strarr(&island2_and_length);
    
    if (lines != NULL) 
        mx_del_strarr(&lines);
    
    mx_printerr_ms(err, msg);
    if (msg != NULL) 
        free((char *)msg);
    exit(-1);
}

static bool mx_add_unique_island(char **islands, int *island_count, char *island_name) {
    for (int i = 0; i < *island_count; i++) {
        if (mx_strcmp(islands[i], island_name) == 0) {
            return false;
        }
    }
    islands[(*island_count)++] = mx_strdup(island_name);
    return true;
}

void mx_validation(char **lines, int num_islands) {
    int island_counter = 0;
    char *islands[2 * num_islands];

    for (int i = 1; lines[i] != NULL; i++) {
        if (mx_count_substr(lines[i], "-") != 1 || mx_count_substr(lines[i], ",") != 1) {
            free_islands(islands, island_counter);
            mx_printerr_clean(ERR_INVALID_LINE, mx_itoa(i + 1), NULL, NULL, lines);
        }

        char **parts = mx_strsplit(lines[i], '-');
        char *island1 = parts[0];
        char *island2_length = parts[1];

        char **island2_and_length = mx_strsplit(island2_length, ',');
        char *island2 = island2_and_length[0];
        char *bridge_length_str = island2_and_length[1];

        if (!mx_is_valid_island_name(island1) || !mx_is_valid_island_name(island2)) {
            free_islands(islands, island_counter);
            mx_printerr_clean(ERR_INVALID_LINE, mx_itoa(i + 1), parts, island2_and_length, lines);
        }

        if (mx_strcmp(island1, island2) == 0) {
            free_islands(islands, island_counter);
            mx_printerr_clean(ERR_INVALID_LINE, mx_itoa(i + 1), parts, island2_and_length, lines);
        }

        int bridge_length = mx_atoi(bridge_length_str);
        if (bridge_length <= 0) {
            free_islands(islands, island_counter);
            mx_printerr_clean(ERR_INVALID_LINE, mx_itoa(i + 1), parts, island2_and_length, lines);
        }

        mx_add_unique_island(islands, &island_counter, island1);
        mx_add_unique_island(islands, &island_counter, island2);

        mx_del_strarr(&parts);
        mx_del_strarr(&island2_and_length);
    }

    if (island_counter != num_islands) {
        free_islands(islands, island_counter);
        mx_del_strarr(&lines);
        mx_printerr_ms(ERR_INVALID_NUM_ISLANDS, NULL);
        exit(-1);
    }

    free_islands(islands, island_counter);
}
