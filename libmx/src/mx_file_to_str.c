#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file) 
        return NULL;
    
    int fd = open(file, O_RDONLY);
    if (fd < 0) 
        return NULL;

    char buffer[1024];
    int total_size = 0;
    int bytes_read;
    char *result = NULL;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        char *new_str = (char *)malloc(total_size + bytes_read + 1);
        if (!new_str) {
            if (result)
                free(result);
            close(fd);
            return NULL;
        }

        if (result) {
            for (int i = 0; i < total_size; i++)
                new_str[i] = result[i];
            free(result);
        }

        for (int i = 0; i < bytes_read; i++) {
            new_str[total_size + i] = buffer[i];
        }
        total_size += bytes_read;
        new_str[total_size] = '\0';

        result = new_str;
    }

    close(fd);

    if (bytes_read < 0) { 
        if (result)
            free(result);
        return NULL;
    }

    if (total_size == 0) { 
        result = (char *)malloc(1);
        if (result)
            result[0] = '\0';
    }

    return result;
}


