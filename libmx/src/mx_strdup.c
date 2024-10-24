#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    if (!s1)
        return NULL;
    
    int length = mx_strlen(s1);
    char *dup = mx_strnew(length);

    if (!dup)
        return NULL;

    mx_strcpy(dup, s1);
    return dup;
}

