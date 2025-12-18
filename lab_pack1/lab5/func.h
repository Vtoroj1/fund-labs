#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    SUCCESS,
    ERROR_NULL_POINTER,
    ERROR_NO_FILE_TYPE,
    UNKNOWN_FILE_TYPE,
    ERROR_OUTPUT_FILE_ERROR,
} ErrorCode;

ErrorCode nameCheck(const char *name);

ErrorCode noDigit(FILE *input, FILE *output);
ErrorCode letterCount(FILE *input, FILE *output);
ErrorCode otherCount(FILE *input, FILE *output);
ErrorCode letterHex(FILE *input, FILE *output);

#endif