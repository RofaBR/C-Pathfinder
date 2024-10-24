#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    if (b == NULL) {
        return NULL;
    }
    unsigned char *ptr = (unsigned char *)b;
    for (size_t i = 0; i < len; i++) {
        ptr[i] = (unsigned char)c;
    }
    return b;
}

