#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int strToInt(char* first, int* otvet) {

    int result = 0;

    while (*first) {
        char c = *first;
        int digit = 0;
        digit = c - '0';

        result = result * 10 + digit;

        first++;
    }

    *otvet = result;

    return 0;
}