#include "func.h"

int main(int argc, char* argv[]) {
    if (argc != 1) {
        printf("Программа не  должна принимать аргументы.\n");
        return 1;
    }

    char string[1024];

    printf("Введите строку для проверки\n");

    if (fgets(string, sizeof(string), stdin) != NULL) {
        size_t len = strlen(string);

        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }

        int res = check_brackets(string);
        switch (res)
        {
        case (0):
            printf("Строка корректно сбалансирована по скобкам\n");
            break;
        case (1):
            printf("Строка некорректно сбалансирована по скобкам\n");
            break;
        case (-1):
            printf("Некорректные данные или ошибка выделения памяти\n");
            break;
        }
    }
    
    return 0;
}
