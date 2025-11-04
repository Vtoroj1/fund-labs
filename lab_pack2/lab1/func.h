#ifndef FUNC_H
#define FUNC_H

#include <stdbool.h>

typedef enum {
    SUCCESS = 0,
    ERROR_WRONG_BASE,
    ERROR_WRONG_AMOUNT_OF_NUMBERS,
    ERROR_WRONG_NUMBER


} ErrorCode;

ErrorCode check(const int base, bool* res, const int n, ...);

#endif
