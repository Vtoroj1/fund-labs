#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int abs(int x) {
    return (x > 0) ? x: -x;
}

long power(int base, int exp) {
    long res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }

    return res;
}

int fact(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) {
        if (f > INT_MAX / i || f < 0) {
            return ERROR_OVERFLOW;
        }
        f *= i;
    }
    return f;
}

ErrorCode strToInt(char* first, int base, int* res) {
    if (first  == NULL || res == NULL) {
        return ERROR_NULL_POINTER;
    }

    int result = 0;

    int sign = 1;
    if (*first == '-') {
        sign = -1;
        first++;
    }
    if (*first == '\0') {
        return ERROR_NO_DIGITS_AFTER_MINUS;
    }

    while (*first) {
        char c = *first;
        int digit = 0;

        if (isdigit(c)) {
            digit = c - '0';
        } else if (isalpha(c)){
            digit = c - 'A' + 10;
        } else {
            return ERROR_NOT_ALLOWED_SYMBOL;
        }

        if (digit >= base) {
            return ERROR_NOT_ALLOWED_SYMBOL;
        }

        if (result > ((INT_MAX - digit) / base) || result < 0) {
            return ERROR_OVERFLOW;
        }

        result = result * base + digit;

        first++;
    }

    *res = result * sign;

    return SUCCESS;
}

ErrorCode findKrat(int x) {
    if (x == 0) {
        return ERROR_ZERO_DIVISION;
    }

    if (abs(x) > 100) {
        return ERROR_NO_NUMBERS_FOUND;
    }

    for (int i = abs(x); i <= 100; i += abs(x)) {
        printf("%d ", i);
    }

    printf("\n");

    return SUCCESS;

}

ErrorCode checkPrime(int x) {
    if (x < 2) {
        return ERROR_NOT_PRIME_OR_COMPOSITE;
    }

    for (int i = 2; i < (x / 2); i++) {
        if (x % i == 0) {
            return ALTERNATIVE_SUCCESS;
        }
    }

        return SUCCESS;
}

ErrorCode intoHex(int x) {
    char sp[32];
    int k = 0;
    int cur;
    int chislo = abs(x);

    while (chislo) {
        cur = chislo % 16;
        sp[k] = (cur < 10) ? '0' + cur: 'A' + cur - 10;
        chislo /= 16;
        k++;
    }

    if (x == 0) {
        printf("0\n");
        return SUCCESS;
    }
    
    if (x < 0) {
        printf("- ");
    }

    for (int i = k - 1; i >= 0; i--) {
        printf("%c ", sp[i]);
    }

    printf("\n");
    return SUCCESS;
}

ErrorCode tablePower(int x) {
    if (x > 10 || x <= 1) {
        return ERROR_NUMBER_OUT_OF_RANGE;
    }

    for (int i = 1; i <= x; i++) {
        for(int j = 1; j <= 10; j++) {
            long num = power(j, i);
            printf("%ld ", num);
        }
        printf("\n");
    }

    return SUCCESS;
}

ErrorCode sumNat(int x, int* res) {
    if (res == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (x < 1) {
        return ERROR_NUMBER_MUST_BE_NATURAL;
    }

    int s = 0;
    for (int i = 1; i <= x; i++) {
        if (INT_MAX - i < s || s < 0) {
            return ERROR_OVERFLOW;
        }
        s += i;
    }

    *res = s;

    return SUCCESS;
}

ErrorCode findFact(int x, int* res) {
    if (res == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (x < 0) {
        return ERROR_NUMBER_CANT_BE_NEGATIVE;
    }

    *res = fact(x);

    return SUCCESS;
}