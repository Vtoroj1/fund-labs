#include "func.h"

#if defined(__linux__)

    #define AMOUNT_OF_ERRORS 5
    static const char *const LINUX_ERRORS[] = {
        "Success",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call"
    };
    
    #define ERRORS_ARRAY LINUX_ERRORS

#elif defined(__APPLE__)

    #define AMOUNT_OF_ERRORS 5
    static const char *const MACOS_ERRORS[] = {
        "Success",
        "Not permitted",
        "No such file",
        "No process",
        "Interrupted"
    };
    
    #define ERRORS_ARRAY MACOS_ERRORS

#else

    #define AMOUNT_OF_ERRORS 1 
    static const char *const UNKNOWN_ERRORS[] = {
        "Unknown error"
    };

    #define ERRORS_ARRAY UNKNOWN_ERRORS

#endif

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