#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (!str)
        return NULL;

    int start = 0;
    int end = mx_strlen(str) - 1;

    while (mx_isspace(str[start]))
        start++;

    while (end >= start && mx_isspace(str[end]))
        end--;

    if (start > end)
        return mx_strnew(0);

    int trimmed_length = end - start + 1;

    char *trimmed_str = mx_strnew(trimmed_length);
    if (!trimmed_str)
        return NULL;

    mx_strncpy(trimmed_str, &str[start], trimmed_length);
    
    return trimmed_str;
}


