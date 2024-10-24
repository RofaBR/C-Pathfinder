#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    if (!s1 || !s2 || n <= 0)
        return 0;
    
    while (n-- > 0) {
        if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0') {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
