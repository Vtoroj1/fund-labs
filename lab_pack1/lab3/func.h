#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef enum {
    SUCCESS,
    NEGATIVE_DISCRIMINANT,
    NOT_A_SQUARE_EQUATION,
    NO_ROOTS,
    INF_ROOTS,
    ERROR_WRONG_INPUT,
    ERROR_INF_OR_NAN_APPEARED,
    ERROR_NULL_POINTER,
    ERROR_OVERFLOW,
    ERROR_WRONG_ARGUMENTS,
    ERROR_NOT_ALLOWED_SYMBOL,
    ERROR_NO_DIGITS_AFTER_MINUS

} ErrorCode;

ErrorCode strToInt(const char* first, const int base, int* res);
ErrorCode strToDouble(const char* first, double* res);

ErrorCode equation(const double epsilon, const double a, const double b, const double c, double* res1, double* res2);
ErrorCode division(const int a, const int b, short int* res);
ErrorCode triangle(const double epsilon, const double a, const double b, const double c, short int *res);

#endif