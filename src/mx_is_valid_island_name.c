#include "../inc/files.h"

bool mx_is_valid_island_name(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!mx_isalpha(name[i])) {
            return false;
        }
    }
    return true;
}
