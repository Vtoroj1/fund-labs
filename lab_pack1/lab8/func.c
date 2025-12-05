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

ErrorCode findMax(char* line, const short int base, long long* max) {
    if (line == NULL || max == NULL) {
        return ERROR_NULL_POINTER;
    }

    long long ans = 0;
    const char* cur = line;

    while (*cur == ' ' || *cur == '\t') {
        cur++;
    }

    if (*cur == '\0' || *cur == '\n') {
            return ERROR_EMPTY_LINE;
    }

    short int sign = 1;
    if (*cur == '-') {
        sign = -1;
        cur++;
        if (*cur == '\0' || *cur == '\n' || *cur == ' ' || *cur == '\t') {
            return ERROR_EMPTY_LINE;
        }
    }

    while (*cur != '\n' && *cur != '\0') {
        char c = *cur;
        short int digit = 0;

        if (isdigit(c)) {
            digit = c - '0';
        } else if (isalpha(c)) {
            digit = c - 'A' + 10;
        } else {
            return ERROR_WRONG_INPUT;
        }

        if (digit >= base) {
            return ERROR_WRONG_INPUT;
        }

        if (ans > ((LLONG_MAX - digit) / base) || ans < 0) {
            return ERROR_OVERFLOW;
        }
        ans = ans * base + digit;
        cur++;
    }

    ans *= sign;

    if (llabs(ans) > llabs(*max)) {
        *max = ans;
    }

    return SUCCESS;
}

ErrorCode newBase(const long long number, const short int base, char* ans, const short int size) {
    if (ans == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (base < 0 || base > 36) {
        return ERROR_WRONG_INPUT;
    }

    long long del = (number < 0) ? -number : number;
    short int index = 0;

    if (del == 0) {
        ans[index++] = '0';
        ans[index] = '\0';
        return SUCCESS;
    }

    while (del > 0 && index < size) {
        short int digit = del % base;
        del /= base;

        ans[index++] = (digit > 9) ? 'A' + digit - 10 : '0' + digit;
    }

    if (del > 0) {
        return ERROR_OVERFLOW;
    }

    if (number < 0) {
        ans[index++] = '-';
    }

    for (int i = 0; i < index / 2; i++) {
        char c = ans[i];
        ans[i] = ans[index - 1 - i];
        ans[index - 1 - i] = c;
    }

    ans[index] = '\0';

    return SUCCESS;
}