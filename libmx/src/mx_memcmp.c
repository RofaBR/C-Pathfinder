#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *s1_ptr = s1;
    const unsigned char *s2_ptr = s2;
    
    for (size_t i = 0; i < n; i++) {
        if (s1_ptr[i] != s2_ptr[i]) {
            return s1_ptr[i] - s2_ptr[i];
        }
    }
    return 0;
}
