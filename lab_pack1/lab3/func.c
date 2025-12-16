#include "func.h"

unsigned int intAbs(int x)
{
    return (x > 0) ? x : -x;
}

double doubleAbs(double x)
{
    return (x > 0) ? x : -x;
}

bool isEqual(const double epsilon, const double a, const double b)
{
    return doubleAbs(a - b) < epsilon;
}

ErrorCode strToInt(const char* first, const int base, int* res) {
    if (first  == NULL || res == NULL) {
        return ERROR_NULL_POINTER;
    }

    int result = 0;
    const char* current = first;

    short int sign = 1;
    if (*first == '-') {
        sign = -1;
        current++;
    }
    if (*current == '\0') {
        return ERROR_NO_DIGITS_AFTER_MINUS;
    }

    while (*current) {
        char c = *current;
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

        current++;
    }

    *res = result * sign;

    return SUCCESS;
}

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

ErrorCode equation(const double epsilon, const double a, const double b, const double c, double* res1, double* res2) { //q
    if (res1 == NULL || res2 == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (isEqual(epsilon, a, 0.0)) {
        if (isEqual(epsilon, b, 0.0)) {
            if (isEqual(epsilon, c, 0.0)) {
                return INF_ROOTS;
            }
            return NO_ROOTS;
        }
        *res1 = -c / b;
        return NOT_A_SQUARE_EQUATION;
    }

    double d = b * b - 4 * a * c;

    if (isEqual(epsilon, d, 0.0)) {
        *res1 = -b / (2 * a);
        *res2 = *res1;
        return SUCCESS;
    } else if (d > 0) {
        *res1 = (-b + sqrt(d)) / (2 * a);
        *res2 = (-b - sqrt(d)) / (2 * a);
        return SUCCESS;
    } else {
        return NEGATIVE_DISCRIMINANT;
    }
}

ErrorCode division(const int a, const int b, short int *res) { //m
    if (res == NULL) {
        return ERROR_NULL_POINTER;
    }

    if (a == 0 || b == 0) {
        return ERROR_WRONG_ARGUMENTS;
    }

    if (intAbs(a) % intAbs(b) == 0) {
        *res = 1;
    }
    else {
        *res = 0;
    }

    return SUCCESS;
}

ErrorCode triangle(const double epsilon, const double a, const double b, const double c, short int *res) { //t
    if (a <= 0 || b <= 0 || c <= 0) {
        return ERROR_WRONG_ARGUMENTS;
    }
    if (res == NULL) {
        return ERROR_NULL_POINTER;
    }
    if ((a > sqrt(__DBL_MAX__)) || (b > sqrt(__DBL_MAX__)) || (c > sqrt(__DBL_MAX__))
    || (a * a > (__DBL_MAX__ - b * b)) || (b * b > (__DBL_MAX__ - c * c)) || (c * c > (__DBL_MAX__ - a * a))) {
        return ERROR_OVERFLOW;
    }
    if (doubleAbs(a * a + b * b - c * c) < epsilon || doubleAbs(b * b + c * c - a * a) < epsilon || doubleAbs(c * c + a * a - b * b) < epsilon) {
        *res = 1;
    } else {
        *res = 0;
    }

    return SUCCESS;
}