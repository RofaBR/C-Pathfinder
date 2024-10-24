#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub)
        return -1;

    int subLen = mx_strlen(sub);

    if (subLen == 0)
        return 0;

    int count = 0;

    while (*str != '\0') {
        if (mx_strncmp(str, sub, subLen) == 0) {
            count++;
            str += subLen;
        } else {
            str++;
        }
    }

    return count;
}


