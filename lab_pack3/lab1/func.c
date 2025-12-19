#include "func.h"

int increment(int number) {
    int one = 1;
    while (number & one) {
        number = number & ~one;
        one = one << 1;
    }

    return number | one;
}

int decrement(int number) {    
    int minus = ~0;
    while (minus != 0) {
        int temp = number & minus;
        number = number ^ minus;
        minus = temp << 1;
    }

    return number;
}

ErrorCode transfer(const int number, const int r, char *res) {
    if (r < 1 || r > 5) {
        return ERROR_WRONG_BASE;
    }

    if (res == NULL) {
        return ERROR_NULL_POINTER;
    }

    const unsigned int mask = decrement(1 << r);
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    
    if ((number | 0) == 0) {
        res[0] = '0';
        res[1] = '\0';
        return SUCCESS;
    }

    char buff[33];
    
    int is_negative = (number >> 31) & 1;
    
    unsigned int num;
    if (is_negative) {
        num = (unsigned int)(increment(~number));
    } else {
        num = (unsigned int)number;
    }

    int index = 0;
    while (num != 0) {
        unsigned int digit = num & mask;
        buff[index] = digits[digit];
        index = increment(index);
        num = num >> r;
    }
    
    int out_index = 0;
    if (is_negative) {
        res[out_index] = '-';
        out_index = increment(out_index);
    }
    
    int i = decrement(index);
    while (1) {
        res[out_index] = buff[i];
        out_index = increment(out_index);
        if (i == 0) break;
        i = decrement(i);
    }
    res[out_index] = '\0';

    return SUCCESS;
}