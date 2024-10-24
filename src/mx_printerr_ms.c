#include "../inc/files.h"

void mx_printerr_ms(t_error err, const char *s) {
    switch (err) {
    case ERR_USAGE:
        mx_printerr("usage: ./pathfinder [filename]\n");
        break;

    case ERR_FILE_NOT_EXIST:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" does not exist\n");
        break;

    case ERR_FILE_EMPTY:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" is empty\n");
        break;

    case ERR_INVALID_LINE:
        mx_printerr("error: line ");
        mx_printerr(s);
        mx_printerr(" is not valid\n");
        break;

    case ERR_INVALID_NUM_ISLANDS:
        mx_printerr("error: invalid number of islands\n");
        break;

    case ERR_DUPLICATE_BRIDGES:
        mx_printerr("error: duplicate bridges\n");
        break;

    case ERR_SUM_TOO_BIG:
        mx_printerr("error: sum of bridges lengths is too big\n");
        break;
    }
}

