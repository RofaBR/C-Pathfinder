#include "../inc/libmx.h"

#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str)
        return NULL;

    char *trimmed = mx_strtrim(str);
    if (!trimmed)
        return NULL;

    int len = 0;
    bool in_word = false;
    for (int i = 0; trimmed[i] != '\0'; i++) {
        if (!mx_isspace(trimmed[i])) {
            len++;
            in_word = true;
        } else if (in_word) {
            len++;
            in_word = false;
        }
    }

    char *result = mx_strnew(len);
    if (!result) {
        free(trimmed);
        return NULL;
    }

    int j = 0;
    in_word = false;
    for (int i = 0; trimmed[i] != '\0'; i++) {
        if (!mx_isspace(trimmed[i])) {
            result[j++] = trimmed[i];
            in_word = true;
        } else if (in_word) {
            result[j++] = ' ';
            in_word = false;
        }
    }

    free(trimmed);
    return result;
}


