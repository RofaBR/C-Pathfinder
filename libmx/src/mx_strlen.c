#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int length = 0;
    while (*s != '\0') {
        length++, s++;
    }
    return length;
}


