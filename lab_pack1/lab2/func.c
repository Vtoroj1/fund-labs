#include "func.h"

ErrorCode check() {
    char c;
    while ((c = getchar()) != '\n' && c != '\0') {
        if (c != ' ') {
            return ERROR_WRONG_INPUT;
        }
    }
    return SUCCESS;
}

ErrorCode max(const int* num, const int size, int* res) {
    if (num == NULL || res == NULL || size < 0) {
        return ERROR_WRONG_ARGUMENTS;
    }

    int max = num[0];
    for (int i = 1; i < size; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    *res = max;
    return SUCCESS;
}

ErrorCode findPrime(const int max, int* res) {
    if (max < 1 || res == NULL) {
        return ERROR_WRONG_ARGUMENTS;
    }

    res[0] = 2;

    if (max == 1) {
        return SUCCESS;
    }

    int k = 1;
    int cur = 3;
    
    while (k < max) {
        short unsigned int f = 1;
        for (int i = 0; i < k; i++) {
            if (res[i] * res[i] > cur) {
                break;
            }

            if (cur % res[i] == 0) {
                f = 0;
                break;
            }
        }

        if (f) {
            res[k] = cur;
            k++;
        }

        if (cur > INT_MAX - 2) {
            return ERROR_NO_PRIME;
        }
        cur += 2;
    }

    return SUCCESS;
}