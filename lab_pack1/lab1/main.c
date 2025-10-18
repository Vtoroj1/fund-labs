#include "functions.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Ошибка: неверное число аргументов. \n");
        return 1;
    }

    char*flag = argv[2];
    
    if (flag[0] != '-' && flag[0] != '/') {
        printf("Ошибка: неправильный ввод флага \n");
        return 1;
    }

    int chislo;

    strToInt(argv[1], &chislo);

    printf("%d\n", chislo);
}