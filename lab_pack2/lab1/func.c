#include "func.h"
#include <stdio.h>
#include <stdarg.h>


ErrorCode check(const int base, bool* res, const int n, ...) {
    if (base < 2) {
        return ERROR_WRONG_BASE;
    }

    if (n < 1) {
        return ERROR_WRONG_AMOUNT_OF_NUMBERS;
    }

    va_list num;
    double number;

    va_start(num, n);

    for (int i = 0; i < n; i++) {
        number = va_arg(num, double);

        if (number <= 0.0 || number >= 1.0) {
            va_end(num);
            return ERROR_WRONG_NUMBER;
        }

        long long numerator = number * 1e15;
        long long denominator = 1e15;

        if (number * 1e15 - (double)numerator > 1e-15) {
            printf("Число №%d возможно является переодической дробью. \n", i + 1);
        }

        long long n1 = numerator;
        long long n2 = denominator;

        while (n1 && n2) {
            if (n1 > n2) {
                n1 %= n2;
            } else {
                n2 %= n1;
            }
        }

        denominator /= (n1 + n2);

        short int flag = 0;

        if (denominator % 2 == 0) {
            if (base % 2 != 0) {
                res[i] = false;
                continue;
            }
        }

        for (long j = 3; j * j <= denominator; j += 2) {
            if (denominator % j == 0) {
                if (base % j != 0) {
                    flag = 1;
                    break;
                }
                while (denominator % j == 0) {
                    denominator /= j;
                }
            }
        }
        
        if (flag == 1) {
            res[i] = false;
        } else {
            res[i] = true; 
        }
    }

    va_end(num);

    return SUCCESS;
}