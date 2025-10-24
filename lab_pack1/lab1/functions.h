#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef enum {
    SUCCESS = 0,
    ALTERNATIVE_SUCCESS,
    ERROR_NULL_POINTER,
    ERROR_NO_DIGITS_AFTER_MINUS,
    ERROR_NOT_ALLOWED_SYMBOL,
    ERROR_OVERFLOW,
    ERROR_ZERO_DIVISION,
    ERROR_NO_NUMBERS_FOUND,
    ERROR_NOT_PRIME_OR_COMPOSITE,
    ERROR_NUMBER_OUT_OF_RANGE,
    ERROR_NUMBER_MUST_BE_NATURAL,
    ERROR_NUMBER_CANT_BE_NEGATIVE
} ErrorCode;

ErrorCode strToInt(char* first, int base, int* otvet);

ErrorCode findKrat(int x);
ErrorCode checkPrime(int x);
ErrorCode intoHex(int x);
ErrorCode tablePower(int x);
ErrorCode sumNat(int x, int* res);
ErrorCode findFact(int x, int* res);

#endif