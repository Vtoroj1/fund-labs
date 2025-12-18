#include "func.h"

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        printf("Неверное количество аргументов.\n");
        return 1;
    }

    double epsilon;
    
    switch (strToDouble(argv[1], &epsilon)) {
        case ERROR_WRONG_INPUT:
            printf("Неверный ввод значения эпсилон.\n");
            return 1;
        case ERROR_INF_OR_NAN_APPEARED:
            printf("inf/nan не являются вещественными числами.\n");
            return 1;
        case ERROR_NULL_POINTER:
            printf("Нулевой указатель.\n");
            return 1;
        default:
            break;
    }

    if (epsilon < 0) {
        printf("Значение эпсилон не может быть отрицательным.\n");
        return 1;
    }

    short int integral;

    printf("Выберите интеграл: \n");
    printf("1\n");
    printf("2\n");
    printf("3\n");
    printf("4\n");

    if (scanf("%hd", &integral) != 1 || integral < 1 || integral > 4) {
        printf("Ошибка ввода: проверьте правильность ввода номера выбранного интеграла. \n");
        return 1;
    }

    double answer;
    ErrorCode status;

    switch (integral) {
        case 1:
            status = solve(first, 0, 1, epsilon, &answer);
            break;
        case 2:
            status = solve(second, 0, 1, epsilon, &answer);
            break;
        case 3:
            status = solve(third, 0, 1 - 1e-16, epsilon, &answer);
            break;
        case 4:
            status = solve(fourth, 0, 1, epsilon, &answer);
            break;
    }

    switch (status) {
        case SUCCESS:
            printf("Ответ: %f \n", answer);
            break;
        case ERROR_WRONG_EPSILON:
            printf("Неверное значение эпсилон.\n");
            return 1;
        case ERROR_NULL_POINTER:
            printf("Нулевой указатель.\n");
            return 1;
        case ERROR_WRONG_INTEGRAL_LIMITS:
            printf("Пределы интегрирования заданы неверно.\n");
            return 1;
        case ERROR_OVERFLOW:
            printf("Переполнение ячейки памяти.\n");
            return 1;
        case ERROR_BAD_PRECISION_ANSWER:
            printf("Не удалось узнать значение интеграла заданной точности. Ближайшее значение: %f \n", answer);
            break;
    }

    return 0;
}