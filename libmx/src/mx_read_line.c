#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (!lineptr || fd < 0 || buf_size <= 0) {
        return -2; 
    }

    char buffer[buf_size];
    char *result = mx_strnew(0);
    ssize_t bytes_read;
    size_t total_bytes = 0;
    
    while ((bytes_read = read(fd, buffer, buf_size)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == delim) {
                *lineptr = result;
                return total_bytes;
            }

            char temp[2] = {buffer[i], '\0'};
            char *new_result = mx_strjoin(result, temp);
            free(result);
            result = new_result;
            total_bytes++;
        }
    }

    if (bytes_read == 0 && total_bytes > 0) {
        *lineptr = result;
        return total_bytes;
    }

    free(result);
    return -1;
}
