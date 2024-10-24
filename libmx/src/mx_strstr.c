#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    if (*s2 == '\0') return (char *)s1;

    int s2_len = mx_strlen(s2);

    while (*s1) {
        if (mx_strlen(s1) < s2_len) break;

        if (mx_strncmp(s1, s2, s2_len) == 0) {
            return (char *)s1;
        }

        s1++;
    }

    return NULL;
}

