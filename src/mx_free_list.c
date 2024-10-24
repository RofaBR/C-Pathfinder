#include "../inc/files.h"

void mx_free_list(t_list *list) {
    while (list) {
        t_list *temp = list;
        list = list->next;
        free(((t_path *)temp->data)->islands);
        free(temp->data);
        free(temp);
    }
}
