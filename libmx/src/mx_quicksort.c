#include "../inc/libmx.h"

void mx_swap_str(char **s1, char **s2) {
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;

    int swap_count = 0;

    if (left < right) {
        int pivot_index = (left + right) / 2;
        int pivot_length = mx_strlen(arr[pivot_index]);
        int i = left;
        int j = right;

        while (i <= j) {
            while (mx_strlen(arr[i]) < pivot_length) i++;
            while (mx_strlen(arr[j]) > pivot_length) j--;

            if (i <= j) {
                if (mx_strlen(arr[i]) == mx_strlen(arr[j])) {
                    if (mx_strcmp(arr[i], arr[j]) > 0) {
                        mx_swap_str(&arr[i], &arr[j]);
                        swap_count++;
                    }
                } 
                else {
                    mx_swap_str(&arr[i], &arr[j]);
                    swap_count++;
                }
                i++, j--;
            }
        }

        swap_count += mx_quicksort(arr, left, j);
        swap_count += mx_quicksort(arr, i, right);
    }

    return swap_count;
}

