#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char buffer[4];
    int len = 0;

    if (c < 0x80) {
        buffer[0] = (char)c;
        len = 1;
    } else if (c < 0x0800) {
        buffer[0] = (c >> 6) | 0xC0;
        buffer[1] = (c & 0x3F) | 0x80;
        len = 2;
    } else if (c < 0x010000) {
        buffer[0] = (c >> 12) | 0xE0;
        buffer[1] = ((c >> 6) & 0x3F) | 0x80;
        buffer[2] = (c & 0x3F) | 0x80;
        len = 3;
    } else if (c < 0x110000) {
        buffer[0] = (c >> 18) | 0xF0;
        buffer[1] = ((c >> 12) & 0x3F) | 0x80;
        buffer[2] = ((c >> 6) & 0x3F) | 0x80;
        buffer[3] = (c & 0x3F) | 0x80;
        len = 4;
    }

    for (int i = 0; i < len; i++) {
        mx_printchar(buffer[i]);
    }
}



