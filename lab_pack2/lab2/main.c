#include "func.h"

int main(int argc, char* argv[]) {
    if (argc != 1) {
        printf("Программа не  должна принимать аргументы.\n");
        return 1;
    }

    const char str1[] = "Hello, World!";
    const char str2[] = "Hello, Everyone!";
    const char str3[] = "Test";
    const char str4[] = "Programming";
    const char str5[] = "abcdef";
    const char str6[] = "1234567890";
    char buffer1[50] = "Initial: ";
    char buffer2[50] = "AAAAAAAAAA";
    char buffer3[50] = "Copy this text";
    char buffer4[50] = "Find/me/in/this/string";
    const char empty[] = "";
    const char numbers[] = "12345";
    const char letters[] = "abcde";

    printf("=== ТЕСТИРОВАНИЕ ФУНКЦИЙ ===\n\n");

    printf("--- Функция memchr ---\n");
    printf("str1: %s\n", str1);
    printf("Поиск 'W' в str1: %s\n", (char*)memchr(str1, 'W', 13) ? "Найдено" : "Не найдено");
    printf("Поиск 'z' в str1: %s\n", (char*)memchr(str1, 'z', 13) ? "Найдено" : "Не найдено");
    printf("Первый символ 'l': %c\n", *(char*)memchr(str1, 'l', 13));
    printf("\n");

    printf("--- Функция memcmp ---\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("Сравнение str1 и str2 (8 символов): %d\n", memcmp(str1, str2, 8));
    printf("Сравнение str1 и str2 (6 символов): %d\n", memcmp(str1, str2, 6));
    printf("Сравнение str1 и str3 (4 символов): %d\n", memcmp(str1, str3, 4));
    printf("\n");

    printf("--- Функция memcpy ---\n");
    printf("buffer2 до копирования: %s\n", buffer2);
    memcpy(buffer2, str3, 5);
    printf("buffer2 после копирования 'Test': %s\n", buffer2);
    memcpy(buffer2, "Hello", 3);
    printf("buffer2 после копирования 'Hello' (3 символа): %s\n", buffer2);
    printf("\n");

    printf("--- Функция memset ---\n");
    printf("buffer2 до memset: %s\n", buffer2);
    memset(buffer2, 'X', 8);
    printf("buffer2 после memset('X', 8): %s\n", buffer2);
    memset(buffer2, '0', 5);
    printf("buffer2 после memset('0', 5): %s\n", buffer2);
    printf("\n");

    printf("--- Функция strncat ---\n");
    printf("buffer1 до strncat: %s\n", buffer1);
    strncat(buffer1, str1, 7);
    printf("buffer1 после strncat(str1, 7): %s\n", buffer1);
    strncat(buffer1, "!!!", 2);
    printf("buffer1 после strncat('!!!', 2): %s\n", buffer1);
    printf("\n");

    printf("--- Функция strchr ---\n");
    printf("str1: %s\n", str1);
    printf("Поиск 'o' в str1: %s\n", strchr(str1, 'o') ? strchr(str1, 'o') : "Не найдено");
    printf("Поиск ',' в str1: %s\n", strchr(str1, ',') ? strchr(str1, ',') : "Не найдено");
    printf("Поиск 'z' в str1: %s\n", strchr(str1, 'z') ? "Найдено" : "Не найдено");
    printf("\n");

    printf("--- Функция strncmp ---\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str4: %s\n", str4);
    printf("Сравнение str1 и str2 (7 символов): %d\n", strncmp(str1, str2, 7));
    printf("Сравнение str1 и str2 (5 символов): %d\n", strncmp(str1, str2, 5));
    printf("Сравнение str1 и str4 (3 символа): %d\n", strncmp(str1, str4, 3));
    printf("\n");

    printf("--- Функция strncpy ---\n");
    char temp_buf[20] = "";
    printf("Пустой буфер до strncpy: %s\n", temp_buf);
    strncpy(temp_buf, str4, 8);
    temp_buf[8] = '\0';
    printf("Буфер после strncpy(str4, 8): %s\n", temp_buf);
    strncpy(temp_buf, "Short", 10);
    temp_buf[10] = '\0';
    printf("Буфер после strncpy('Short', 10): %s\n", temp_buf);
    printf("\n");

    printf("--- Функция strcspn ---\n");
    printf("str5: %s\n", str5);
    printf("str6: %s\n", str6);
    printf("Длина начального сегмента str5 без цифр из str6: %zu\n", strcspn(str5, str6));
    printf("Длина начального сегмента str6 без букв из str5: %zu\n", strcspn(str6, str5));
    printf("strcspn('Hello123', '0123456789'): %zu\n", strcspn("Hello123", "0123456789"));
    printf("\n");

    printf("--- Функция strlen ---\n");
    printf("str1: %s - длина: %zu\n", str1, strlen(str1));
    printf("str4: %s - длина: %zu\n", str4, strlen(str4));
    printf("empty: '%s' - длина: %zu\n", empty, strlen(empty));
    printf("\n");

    printf("--- Функция strpbrk ---\n");
    printf("str1: %s\n", str1);
    printf("str5: %s\n", str5);
    printf("Первый символ из str5 в str1: %s\n", strpbrk(str1, str5) ? strpbrk(str1, str5) : "Не найдено");
    printf("Первый символ из 'xyz' в str1: %s\n", strpbrk(str1, "xyz") ? "Найдено" : "Не найдено");
    printf("Первый символ из ' ,!' в str1: %s\n", strpbrk(str1, " ,!") ? strpbrk(str1, " ,!") : "Не найдено");
    printf("\n");

    printf("--- Функция strrchr ---\n");
    printf("str1: %s\n", str1);
    printf("Последнее 'l' в str1: %s\n", strrchr(str1, 'l') ? strrchr(str1, 'l') : "Не найдено");
    printf("Последнее 'o' в str1: %s\n", strrchr(str1, 'o') ? strrchr(str1, 'o') : "Не найдено");
    printf("Последнее 'z' в str1: %s\n", strrchr(str1, 'z') ? "Найдено" : "Не найдено");
    printf("\n");

    printf("--- Функция strstr ---\n");
    printf("str1: %s\n", str1);
    printf("str3: %s\n", str3);
    printf("Поиск 'World' в str1: %s\n", strstr(str1, "World") ? strstr(str1, "World") : "Не найдено");
    printf("Поиск 'Test' в str1: %s\n", strstr(str1, "Test") ? "Найдено" : "Не найдено");
    printf("Поиск 'lo' в str1: %s\n", strstr(str1, "lo") ? strstr(str1, "lo") : "Не найдено");
    printf("\n");

    printf("--- Функция strtok ---\n");
    char token_str[] = "apple,banana,cherry,date";
    char path_str[] = "/home/user/documents/file.txt";
    printf("Исходная строка: %s\n", token_str);
    
    char *token = strtok(token_str, ",");
    printf("Токен 1: %s\n", token);
    
    token = strtok(NULL, ",");
    printf("Токен 2: %s\n", token);
    
    token = strtok(NULL, ",");
    printf("Токен 3: %s\n", token);
    
    token = strtok(NULL, ",");
    printf("Токен 4: %s\n", token);
    
    token = strtok(NULL, ",");
    printf("Токен 5: %s\n", token ? token : "NULL");
    
    printf("\nРазделение пути: %s\n", path_str);
    token = strtok(path_str, "/");
    int count = 1;
    while (token != NULL) {
        printf("Часть %d: %s\n", count++, token);
        token = strtok(NULL, "/");
    }
    printf("\n");

    printf("=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===\n");
    return 0;
}