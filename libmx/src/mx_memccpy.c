#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *dst_ptr = (unsigned char *)dst;
    const unsigned char *src_ptr = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        dst_ptr[i] = src_ptr[i];
        if (src_ptr[i] == (unsigned char)c ) {
            return (void *)(dst_ptr + i + 1);
        }
    }
    
    return NULL;
}
