#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str)
        return -1;

    int counter = 0, inWord = 0;
    while (*str != '\0') {
        if (*str == c) {
            inWord = 0;
        } else {
            if (!inWord) {
                counter++;
            }
            inWord = 1;
        }
        str++;
    }

    return counter;
}


