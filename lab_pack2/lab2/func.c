#include "func.h"

void *memchr(const void *str, int c, size_t n)
{
    if (str == NULL) {
        return NULL;
    }

    const unsigned char *current = (const unsigned char *)str;

    unsigned char object = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {

        if (*current == object) {
            return (void *)current;
        }

        current++;
    }

    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n)
{
    if (str1 == NULL || str2 == NULL) {
        return 2;
    }

    const unsigned char *current1 = (const unsigned char *)str1;
    const unsigned char *current2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {

        if (*current1 < *current2) {
            return -1;
        }
        else if (*current1 > *current2) {
            return 1;
        }

        current1++;
        current2++;
    }

    return 0;
}