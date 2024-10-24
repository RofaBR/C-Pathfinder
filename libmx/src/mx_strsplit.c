#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;

    int word_count = mx_count_words(s, c);
    char **arr = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (arr == NULL) return NULL;

    int start = 0, end = 0, index = 0;

    while (s[start] != '\0') {
        while (s[start] == c && s[start] != '\0') start++;
        if (s[start] == '\0') break;

        end = start;
        while (s[end] != c && s[end] != '\0') end++;

        int len = end - start;
        arr[index] = mx_strnew(len);
        if (arr[index] == NULL) {
            for (int j = 0; j < index; j++) {
                mx_strdel(&arr[j]);
            }
            free(arr);
            return NULL;
        }

        mx_strncpy(arr[index], &s[start], len);
        index++;
        start = end;
    }

    arr[index] = NULL;
    return arr;
}

