#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x <= 0) {
        return 0;
    }

    int left = 1;
    int right = x;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long sq = (long long)mid * mid;

        if (sq == x) {
            return mid;
        } else if (sq < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}




