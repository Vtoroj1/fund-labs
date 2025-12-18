#include "func.h"

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Неверное количество аргументов.\n");
        return 1;
    }

    char *inputFileName = argv[2];
    char outputFileName[256];

    switch(nameCheck(inputFileName)) {
        case ERROR_NULL_POINTER:
            printf("(Входной файл) Нулевой указатель.\n");
            break;
        case ERROR_NO_FILE_TYPE:
            printf("(Входной файл) У файла отсутсвует расширение.\n");
            break;
        case UNKNOWN_FILE_TYPE:
            printf("(Входной файл) Недопустимое расширение файла.\n");
            break;
    }
    
    char *flag = argv[1];

    if (flag[0] == '-' || flag[0] == '/') {
        if (flag[1] == 'n' && argc == 4) {
            strcpy(outputFileName, argv[3]);

            switch(nameCheck(outputFileName)) {
                case ERROR_NULL_POINTER:
                    printf("(Выходной файл) Нулевой указатель.\n");
                    break;
                case ERROR_NO_FILE_TYPE:
                    printf("(Выходной файл) У файла отсутсвует расширение.\n");
                    break;
                case UNKNOWN_FILE_TYPE:
                    printf("(Выходной файл) Недопустимое расширение файла.\n");
                    break;
            }       
            
        } else {
            if (argc == 4) {
                printf("При использовании флага без символа \"n\" имя выходного файла не требуется.\n");
                return 1;
            }

            char *slash = strrchr(inputFileName, '/');
            if (slash != NULL) {
                short int num = slash - inputFileName + 1;
                strncpy(outputFileName, inputFileName, num);
                strcat(outputFileName, "out_");
                strcat(outputFileName, slash + 1);
            } else {
                strcpy(outputFileName, "out_");
                strcat(outputFileName, inputFileName);
            }
        }

    } else {
        printf("Флаг должен начинаться с '-' или '/'.\n");
        return 1;
    }

    char* lastInName = strrchr(inputFileName, '/');
    char* lastOutName = strrchr(outputFileName, '/');

    lastInName = (lastInName != NULL) ? lastInName + 1 : inputFileName;
    lastOutName = (lastOutName != NULL) ? lastOutName + 1 : outputFileName;


    if (flag[1] == 'n' && strcmp(lastInName, lastOutName) == 0) {
        printf("Имена файлов совпадают.\n");
        return 1;
    }

    FILE *inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Не удалось открыть входной файл.\n");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    
    if (outputFile == NULL) {
        printf("Не удалось открыть выходной файл.\n");
        fclose(inputFile);
        return 1;
    }
    
    char trueFlag = (flag[1] == 'n') ? flag[2] : flag[1];

    if (!((strlen(flag) == 2) || (flag[1] == 'n' && strlen(flag) == 3))) {
        printf("Некорректный флаг.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    bool success = false;

    switch (trueFlag) {
        case 'd':
            switch (noDigit(inputFile, outputFile)) {
                case ERROR_NULL_POINTER:
                    printf("Нулевой указатель.\n");
                    break;
                case ERROR_OUTPUT_FILE_ERROR:
                    printf("Ошибка записи.\n");
                    break;
                case SUCCESS:
                    success = true;
                    break;
            }
            break;
        case 'i':
            switch (letterCount(inputFile, outputFile)) {
                case ERROR_NULL_POINTER:
                    printf("Нулевой указатель.\n");
                    break;
                case ERROR_OUTPUT_FILE_ERROR:
                    printf("Ошибка записи.\n");
                    break;
                case SUCCESS:
                    success = true;
                    break;
            }
            break;
        case 's':
            switch (otherCount(inputFile, outputFile)) {
                case ERROR_NULL_POINTER:
                    printf("Нулевой указатель.\n");
                    break;
                case ERROR_OUTPUT_FILE_ERROR:
                    printf("Ошибка записи.\n");
                    break;
                case SUCCESS:
                    success = true;
                    break;
            }
            break;
        case 'a':
            switch (letterHex(inputFile, outputFile)) {
                case ERROR_NULL_POINTER:
                    printf("Нулевой указатель.\n");
                    break;
                case ERROR_OUTPUT_FILE_ERROR:
                    printf("Ошибка записи.\n");
                    break;
                case SUCCESS:
                    success = true;
                    break;
            }
            break;
        default:
            printf("Неправильный флаг.\n");
            break;
    }

    fclose(inputFile);
    fclose(outputFile);

    if (!success) {
        return 1;
    }

    printf("Успешная запись в файл.\n");
    return 0;
}