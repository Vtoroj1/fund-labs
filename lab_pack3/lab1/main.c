#include "func.h"

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Программа не должна принимать аргументов.\n");
        return 1;
    }

    char res[33];
    int number = -13; // от -2147483647 до 2147483647

    printf("r = 1: ");

        switch (transfer(number, 1, res)) {
            case (SUCCESS):
                printf("%s\n", res);
                break;
            case(ERROR_NULL_POINTER):
                printf("Нулевой указатель.\n");
                break;        
            case(ERROR_WRONG_BASE):
                printf("Неверное основание системы счисления.\n");
                break;
        }

    printf("r = 2: ");

        switch (transfer(number, 2, res)) {
            case (SUCCESS):
                printf("%s\n", res);
                break;
            case(ERROR_NULL_POINTER):
                printf("Нулевой указатель.\n");
                break;        
            case(ERROR_WRONG_BASE):
                printf("Неверное основание системы счисления.\n");
                break;
        }

    printf("r = 3: ");
        
        switch (transfer(number, 3, res)) {
            case (SUCCESS):
                printf("%s\n", res);
                break;
            case(ERROR_NULL_POINTER):
                printf("Нулевой указатель.\n");
                break;        
            case(ERROR_WRONG_BASE):
                printf("Неверное основание системы счисления.\n");
                break;
        }

    printf("r = 4: ");
        
        switch (transfer(number, 4, res)) {
            case (SUCCESS):
                printf("%s\n", res);
                break;
            case(ERROR_NULL_POINTER):
                printf("Нулевой указатель.\n");
                break;        
            case(ERROR_WRONG_BASE):
                printf("Неверное основание системы счисления.\n");
                break;
        }

    printf("r = 5: ");
        
        switch (transfer(number, 5, res)) {
            case (SUCCESS):
                printf("%s\n", res);
                break;
            case(ERROR_NULL_POINTER):
                printf("Нулевой указатель.\n");
                break;        
            case(ERROR_WRONG_BASE):
                printf("Неверное основание системы счисления.\n");
                break;
        }

        return 0;
}
    