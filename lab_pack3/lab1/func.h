#ifndef FUNC_H
#define FUNC_H

#include <string.h>
#include <stdio.h>

typedef enum {
    SUCCESS,
    ERROR_WRONG_BASE,
    ERROR_NULL_POINTER,
} ErrorCode;

ErrorCode transfer(const int number, const int r, char *res);

#endif