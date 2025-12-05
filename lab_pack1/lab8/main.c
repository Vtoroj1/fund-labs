#include "func.h"


 int main(int argc, char* argv[]) {
    short int base;
    printf("Введите основание системы счисления: ");

    if (scanf("%hd", &base) != 1 || base < 2 || base > 36) {
        printf("Неверное основание системы счисления.\n");
        return 1;
    }

    if (check()) {
        printf("Неверный ввод.\n");
        return 1;
    }

    printf("Введите числа. Введите \"Stop\" для заверешения. \n");

    const short int size = 1024;
    char buffer[size];
    long long max = 0;
    short unsigned int f = 0;

    while (1) {
        if (fgets(buffer, size, stdin) == NULL) {
            printf("Неверный ввод строки.\n");
            return 1;
        }

        if (!strcmp(buffer, "Stop\n") || !strcmp(buffer, "Stop")) {
            if (!f) {
                printf("Нет введенных чисел\n");
                return 1;
            }
            break;
        }

        f = 1;

        switch (findMax(buffer, base, &max)) {
            case SUCCESS:
                break;
            
            case ERROR_NULL_POINTER:
                printf("Неподходящий указатель\n");
                return 1;
            
            case ERROR_EMPTY_LINE:
                printf("Пустая строка\n");
                return 1;
            
            case ERROR_WRONG_INPUT:
                printf("Неправильный ввод\n");
                return 1;
            
            case ERROR_OVERFLOW:
                printf("Переполнение ячейки памяти\n");
                return 1;
        }
    }

    int bases[] = {base, 9, 18, 27, 36};
    char number[size];

    for (int i = 0; i < 5; i++) {
        switch (newBase(max, bases[i], number, size)) {
            case SUCCESS:
                break;
            
            case ERROR_NULL_POINTER:
                printf("Неподходящий указатель\n");
                return 1;
            
            case ERROR_WRONG_INPUT:
                printf("Неправильный ввод\n");
                return 1;
            
            case ERROR_OVERFLOW:
                printf("Переполнение ячейки памяти\n");
                return 1;
        }
        
        printf("В основании %d: %s\n", bases[i], number);
    }

    return 0;
}