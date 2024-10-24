#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *dst_ptr = (unsigned char *)dst;
    const unsigned char *src_ptr = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        dst_ptr[i] = src_ptr[i];
    }

    return dst;
}
