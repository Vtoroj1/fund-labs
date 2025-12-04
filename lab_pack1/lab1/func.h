#ifndef FUNC_H
#define FUNC_H

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

ErrorCode strToInt(const char* first, const int base, int* otvet);

ErrorCode findKrat(const int x);
ErrorCode checkPrime(const int x);
ErrorCode intoHex(const int x);
ErrorCode tablePower(const int x);
ErrorCode sumNat(const int x, long int* res);
ErrorCode findFact(const int x, long long int* res);

#endif