#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int size = 0;
    t_list *current = list;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

