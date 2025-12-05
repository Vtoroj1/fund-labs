#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

typedef enum {
    SUCCESS = 0,
    ERROR_WRONG_INPUT,
    ERROR_NULL_POINTER,
    ERROR_EMPTY_LINE,
    ERROR_WRONG_CHAR,
    ERROR_OVERFLOW,
} ErrorCode;

ErrorCode check();
ErrorCode findMax(char* line, const short int base, long long* max);
ErrorCode newBase(const long long number, const short int base, char* answer, const short int size);
#endif