#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    if (!str) return 0;

    int i = 0;
    int sign = 1;
    int result = 0;

    while (mx_isspace(str[i])) i++;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    if (!mx_isdigit(str[i])) {
        return 0;
    }

    // Обробка цифр
    while (mx_isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    if (str[i] != '\0' && !mx_isspace(str[i])) {
        return 0; 
    }

    return result * sign;
}

