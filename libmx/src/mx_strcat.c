#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int lenS1 = mx_strlen(s1);
    int lenS2 = mx_strlen(s2);
    for (int i = 0; i < lenS2; i++){
        s1[lenS1 + i] = s2[i];
    }
    s1[lenS1 + lenS2] = '\0';
    return s1;
}

