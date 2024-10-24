#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL)
        return 0;

    unsigned long res = 0;

    for (const char *ptr = hex; *ptr != '\0'; ptr++) {

        char c = *ptr;
        unsigned long digit = 0;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = 10 + (c - 'a');
        } else if (c >= 'A' && c <= 'F') {
            digit = 10 + (c - 'A');
        } else {
            return 0;
        }

        res = res * 16 + digit;
    }
    return res;
}

