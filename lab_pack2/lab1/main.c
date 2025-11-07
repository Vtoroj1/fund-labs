#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 1) {
        printf("Ошибка: аргументы задаются внутри кода. \n");
        return 1;
    }

    int n = 3;
    int base = 7;
    
    bool* res = (bool*)calloc(n, sizeof(bool));
    if (res == NULL) {
        printf ("Ошибка: не удалось выделить необходимую память. \n");
        return 1;
    }

    ErrorCode ans = check(base, res, n, 0.3, 1.0, 0.3);

    switch (ans)
    {
    case SUCCESS:
        printf("Успех. Результат:\n");
        for (int i = 0; i < n; i++) {
            printf("Число №%d - ", i + 1);
            if (res[i]) {
                printf("имеет конечное представление в системе счисления с основанием %d.\n", base);
            } else {
                printf("не имеет конечное представление в системе счисления с основанием %d.\n", base);
            }
        }
        break;
    case ERROR_WRONG_BASE:
        printf("Ошибка: введено некорректное основание системы счисления. \n");
        break;
    case ERROR_WRONG_AMOUNT_OF_NUMBERS:
        printf("Ошибка: введено некорректное количествo чисел. \n");
        break;
    case ERROR_WRONG_NUMBER:
        printf("Ошибка: введено неверное число. Числа должны находиться в диапазоне (0, 1). \n");
        break;
    default:
        break;
    }

    free(res);

    return 0;
}
