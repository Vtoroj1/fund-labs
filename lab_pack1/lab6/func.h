#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef enum {
    SUCCESS,
    ERROR_BAD_PRECISION_ANSWER,
    ERROR_WRONG_EPSILON,
    ERROR_NULL_POINTER,
    ERROR_WRONG_INTEGRAL_LIMITS,
    ERROR_OVERFLOW,
    ERROR_INF_OR_NAN_APPEARED,
    ERROR_WRONG_INPUT
} ErrorCode;

ErrorCode solve(double (*func)(double), double a, double b, double epsilon, double* result);

double first(double x);
double second(double x);
double third(double x);
double fourth(double x);

ErrorCode strToDouble(const char* first, double* res);

#endif