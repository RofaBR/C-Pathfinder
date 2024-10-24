#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size == 0 && ptr != NULL) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(size);
    }

    size_t current_size = malloc_usable_size(ptr);

    if (size <= current_size) {
        return ptr;
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    mx_memcpy(new_ptr, ptr, current_size);

    free(ptr);

    return new_ptr;
}

