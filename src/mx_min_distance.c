#include "../inc/files.h"

int mx_min_distance(int dist[], bool sptSet[], int num_islands) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < num_islands; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

