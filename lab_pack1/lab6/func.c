#include "func.h"

ErrorCode strToDouble(const char* first, double* res) {
    if (first == NULL || res == NULL) {
        return ERROR_NULL_POINTER;
    }
    
    char* remain;
    *res = strtod(first, &remain);

    if (*remain != '\0' || remain == first) {
        return ERROR_WRONG_INPUT;
    }
    
    if (isinf(*res) || isnan(*res)) {
        return ERROR_INF_OR_NAN_APPEARED;
    }

    return SUCCESS;
}

ErrorCode solve(double (*func)(double), double a, double b, double epsilon, double* result) {
    if (epsilon < 0) {
        return ERROR_WRONG_EPSILON;
    }

    if (func == NULL || result == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (a > b) {
        return ERROR_WRONG_INTEGRAL_LIMITS;
    }

    if (a == b) {
        *result = 0;
        return SUCCESS;
    }

    if (__DBL_MAX__ - func(b) < func(a)) {
        return ERROR_OVERFLOW;
    }

    double cur, prev = -INFINITY;

    int step = 1;

    unsigned int maxIters = 1e5;
    unsigned int iters = 0;

    while (iters < maxIters) {
        iters++;
        double h = (b - a) / step;
        double cur = ((func(a) + func(b)) / 2);

        for (int i = 1; i < step; i++) {
            double x = a + i * h;

            if (__DBL_MAX__ - cur < h * func(x)) {
                *result = prev;
                return ERROR_BAD_PRECISION_ANSWER;
            }

            cur += func(x);
        }

        cur *= h;

        if (fabs(prev - cur) < epsilon) {
            *result = cur;
            return SUCCESS;
        }

        prev = cur;

        if (__INT_MAX__ / 2 < step) {
            *result = prev;
            return ERROR_BAD_PRECISION_ANSWER;
        }

        step *= 2;
    }

    *result = prev;

    return ERROR_BAD_PRECISION_ANSWER;
}

double first(double x) {
    double y = log(1.0 + x) / x;
    if (isnan(y)) {
        return 0;
    }
    if (isinf(y)) {
        return (y > 0) ? 1e300 : 1e-300;
    }
    return y;
}

double second(double x) {
    double y = exp(-(x * x) / 2);
    if (isnan(y)) {
        return 0;
    }
    if (isinf(y)) {
        return (y > 0) ? 1e300 : 1e-300;
    }
    return y;
}

double third(double x) {
    double y = -log(1.0 - x);
    if (isnan(y)) {
        return 0;
    }
    if (isinf(y)) {
        return (y > 0) ? 1e300 : -1e300;
    }
    return y;
}

double fourth(double x) {
    double y = exp(x * log(x));
    if (isnan(y)) {
        return 0;
    }
    if (isinf(y)) {
        return (y > 0) ? 1e300 : 1e-300;
    }
    return y;
}