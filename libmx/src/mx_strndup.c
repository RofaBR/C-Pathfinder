#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) 
        return NULL;

    int str_len = mx_strlen(s1);
    int len_to_copy = (n < (size_t)str_len) ? n : str_len;

    char *dup_str = mx_strnew(len_to_copy);
    if (dup_str == NULL)
        return NULL;

    return mx_strncpy(dup_str, s1, len_to_copy);
}


