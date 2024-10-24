#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int len = (number <= 0) ? 1 : 0;
    int tmp = number;

    while (tmp != 0) {
        len++;
        tmp /= 10;
    }

    char *str = mx_strnew(len);
    if (!str) return NULL;

    if (number == 0) {
        str[0] = '0';
        return str;
    }

    int is_negative = (number < 0);
    unsigned int n = (is_negative) ? -number : number;

    str[len - 1] = '\0';
    
    while (n != 0) {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }

    if (is_negative)
        str[0] = '-';

    return str;
}

