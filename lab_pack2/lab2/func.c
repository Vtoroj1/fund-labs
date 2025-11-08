#include "func.h"

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, накоторую указывает аргумент str.
//Возвращает указатель на найденный символ / NULL.
void *memchr(const void *str, int c, size_t n)  { //a

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

//Сравнивает первые n байтов str1 и str2.
//Возвращает 1 при str1 > str2 / 0 при str1 == str2 / -1 при str1 < str2 / 2 при NULL указателях.
int memcmp(const void *str1, const void *str2, size_t n) { //b

    if (str1 == NULL || str2 == NULL) {
        return 2;
    }

    const unsigned char *current1 = (const unsigned char *)str1;
    const unsigned char *current2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {

        if (*current1 < *current2) {
            return -1;
        } else if (*current1 > *current2) {
            return 1;
        }

        current1++;
        current2++;
    }

    return 0;
}

//Копирует n символов из src в dest.
//Возвращает первый символ строки, куда копировали.
void *memcpy(void *dest, const void *src, size_t n) { //c

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    unsigned char *destination = (unsigned char *)dest;
    const unsigned char *source = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        *destination = *source;
        destination++;
        source++;
    }

    return dest;
}

//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
//Возвращает первый символ преобразованной строки.
void *memset(void *str, int c, size_t n) { //d

    if (str == NULL) {
        return NULL;
    }

    unsigned char *current = (unsigned char *)str;
    unsigned char object = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {

        *current = object;

        current++;
    }

    return str;
}

//Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
//Возвращает указатель на первый символ добавленного участка.
char *strncat(char *dest, const char *src, size_t n) { //e

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    unsigned char *destination = (unsigned char *)dest;
    const unsigned char *source = (const unsigned char *)src;

    while (*destination != '\0') {
        destination++;
    };

    while (n != 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        n--;
    }

    *destination = '\0';

    return dest;
}

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
//Возвращает указатель на найденный символ / NULL.
char *strchr(const char *str, int c) { //f

    if (str == NULL) {
        return NULL;
    }

    const unsigned char *current = (const unsigned char *)str;
    unsigned char object = (unsigned char)c;

    while (*current != '\0') {

        if (*current == object) {
            return (char *)current;
        }

        current++;
    }

    if (object == '\0') {
        return (char *)current;
    }

    return NULL;
}

//Сравнивает не более первых n байтов str1 и str2.
//Возвращает 1 при str1 > str2 / 0 при str1 == str2 / -1 при str1 < str2 / 2 при NULL указателях.
//Заканчивает после того, как встретит '\0'.
int strncmp(const char *str1, const char *str2, size_t n) { //g
    if (str1 == NULL || str2 == NULL) {
        return 2;
    }

    const unsigned char *current1 = (const unsigned char *)str1;
    const unsigned char *current2 = (const unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {

        if (*current1 < *current2) {
            return -1;
        } else if (*current1 > *current2) {
            return 1;
        }

        if (*current1 == '\0' || *current2 == '\0') {
            return 0;
        }

        current1++;
        current2++;
    }

    return 0;
}

//Копирует до n символов из строки, на которую указывает src, в dest.
//Возвращает первый символ строки, куда копировали.
//Заканчивает после того, как встретит '\0'.
char *strncpy(char *dest, const char *src, size_t n) { //h

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    unsigned char *destination = (unsigned char *)dest;
    const unsigned char *source = (const unsigned char *)src;
    size_t i;

    for (i = 0; i < n && *source != '\0'; i++) {
        *destination = *source;
        destination++;
        source++;
    }

    for (; i < n; i++) {
        *destination = '\0';
        destination++;
    }

    return dest;
}

//Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
size_t strcspn(const char *str1, const char *str2) { //i

    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    const unsigned char *current1 = (const unsigned char *)str1;
    size_t len = 0;

    while (*current1 != '\0') {

        for (const unsigned char *current2 = (const unsigned char *)str2; *current2 != '\0'; current2++) {

            if (*current1 == *current2) {
                return len;
            }

        }

        current1++;
        len++;
    }

    return len;
}


//Вычисляет длину строки str, не включая завершающий нулевой символ.
//Заканчивает после того, как встретит '\0'.
size_t strlen(const char *str) { //k

    if (str == NULL) {
        return 0;
    }

    size_t len = 0;
    const unsigned char *current = (const unsigned char *)str;

    while (*current != '\0') {
        len++;
        current++;
    }

    return len;
}

//Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
//Возвращает указатель на найденный символ.
char *strpbrk(const char *str1, const char *str2) { //l

    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    const unsigned char *current1 = (const unsigned char *)str1;

    while (*current1 != '\0') {

        for (const unsigned char *current2 = (const unsigned char *)str2; *current2 != '\0'; current2++) {

            if (*current1 == *current2) {
                return (char *)current1;
            }

        }

        current1++;
    }

    return NULL;
}

//Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
//Возвращает указатель на найденный символ / NULL.
char *strrchr(const char *str, int c) { //m

    if (str == NULL) {
        return NULL;
    }

    const unsigned char *current = (const unsigned char *)str;
    unsigned char object = (unsigned char)c;
    const char *last = NULL;

    while (*current != '\0') {

        if (*current == object) {
            last = current;
        }

        current++;
    }

    return (char *)last;
}

//Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
//Возвращает указатель на начало найденного фрагмента / NULL.
char *strstr(const char *haystack, const char *needle) { //n

    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    const unsigned char *stack = (const unsigned char *)haystack;

    for (; *stack != '\0'; stack++) {
        const unsigned char *first = (const unsigned char *)needle;
        const unsigned char *stack2 = stack;

        while (*first != '\0' && *stack2 != '\0' && *first == *stack2) {
            first++;
            stack2++;
        }

        if (*first == '\0') {
            return (char *)stack;
        }

    }

    return NULL;
}

//Разбивает строку str на ряд токенов, разделенных delim.
//Если str != NULL, начинается поиск в новой строке.
//Если str == NULL, продолжается поиск в предыдущей строке.
char *strtok(char *str, const char *delim) { //o

    static char *last = NULL;
    char *begin;

    if (str != NULL) {
        last = str;
    } else if (last == NULL) {
        return NULL;
    }

    char *l = last;

    while (*l != '\0') {
        int f = 0;
        const char *d = delim;

        while (*d != '\0') {

            if (*l == *d) {
                f = 1;
                break;
            }

            d++;
        }

        if (f) {
            l++;
        } else {
            break;
        }
    }

    if (*l == '\0') {
        last = NULL;
        return NULL;
    }

    begin = l;

    while (*l != '\0') {
        int ndel = 0;
        const char *d = delim;

        while (*d != '\0') {
            if (*l == *d) {
                ndel = 1;
                break;
            }

            d++;
        }

        if (ndel) {
            break;
        }
        l++;
    }

    if (*l != '\0') {
        *l = '\0';
        last = l + 1;
    } else {
        last = NULL;
    }

    return begin;
}