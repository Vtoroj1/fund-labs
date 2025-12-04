#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum {
    SUCCESS = 0,
    ERROR_WRONG_ARGUMENTS,
    ERROR_NO_PRIME,
    ERROR_WRONG_INPUT
} ErrorCode;

ErrorCode check();
ErrorCode max(const int* num, const int size, int* res);
ErrorCode findPrime(const int max, int* res);

#endif