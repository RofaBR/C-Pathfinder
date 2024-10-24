#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *res = mx_strnew(1);
        res[0] = '0';
        return res;
    }

    int len = 0;
    unsigned long tmp = nbr;
    while (tmp > 0) {
        tmp /= 16;
        len++;
    }

    char *res = mx_strnew(len+1);

    char *hex_digits = "0123456789abcdef";
    while (nbr > 0) {
        res[--len] = hex_digits[nbr % 16];
        nbr /= 16;
    }

    return res;
}

