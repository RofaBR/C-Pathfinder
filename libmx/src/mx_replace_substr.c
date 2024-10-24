#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;

    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);

    int count = mx_count_substr(str, sub);

    if (count == 0)
        return mx_strdup(str);

    int new_len = mx_strlen(str) + count * (replace_len - sub_len);
    char *result = mx_strnew(new_len);

    const char *temp = str;
    char *res_ptr = result;

    while(*temp) {
        const char *found = mx_strstr(temp, sub);

        if (found) {
            mx_strncpy(res_ptr, temp, found - temp);
            res_ptr += found - temp;

            mx_strcpy(res_ptr, replace);
            res_ptr += replace_len;

            temp = found + sub_len;

        } else {
            mx_strcpy(res_ptr, temp);
            break;
        }
    }
    return result;
}
