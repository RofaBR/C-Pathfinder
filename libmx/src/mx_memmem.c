#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big == NULL || little == NULL || big_len < little_len || little_len == 0) {
        return NULL;
    }

    const unsigned char *big_ptr = (const unsigned char *)big;
    const unsigned char *little_ptr = (const unsigned char *)little;

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (big_ptr[i] == little_ptr[0]) {
            size_t j;
            for (j = 0; j < little_len; j++) {
                if (big_ptr[i + j] != little_ptr[j]) {
                    break;
                }
            }

            if (j == little_len) {
                return (void *)&big_ptr[i];
            }
        }
    }
    
    return NULL;
}

