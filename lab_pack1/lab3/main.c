#include "func.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Неверное количество аргументов.\n");
        return 1;
    }

    char* flag = argv[1];
    if (flag[0] != '-' && flag[0] != '/') {
        printf("Флаг должен начинаться с '-' или '/'.\n");
        return 1;
    }
    
    if (flag[1] == 'q' || flag[1] == 't') {
        if (argc != 6) {
            printf("Требуется 4 числа для работы.\n");
            return 1;
        }

        double epsilon, a, b, c, temp;

        switch (strToDouble(argv[2], &epsilon)) {
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

        switch (strToDouble(argv[3], &a)) {
            case ERROR_WRONG_INPUT:
                printf("Неверный ввод значения первого коэффициента.\n");
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
        switch (strToDouble(argv[4], &b)) {
            case ERROR_WRONG_INPUT:
                printf("Неверный ввод значения второго коэффициента.\n");
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
        switch (strToDouble(argv[5], &c)) {
            case ERROR_WRONG_INPUT:
                printf("Неверный ввод значения третьего коэффициента.\n");
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
        
        if (flag[1] == 'q') {
            double variants[6][3] = {};
            short int k = 0;
            double res1, res2;
            for (short int i = 0; i < 2; i++) {
                for (short int j = 0; j < 3; j++) {
                    bool f = 0;
                    for (int q = 0; q < k; q++) {
                        if ((variants[q][0] - a < epsilon) & (variants[q][1] - b < epsilon) & (variants[q][2] - c < epsilon)) {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 1) {
                        continue;
                    }
                    variants[k][0] = a;
                    variants[k][1] = b;
                    variants[k][2] = c;
                    k++;

                    printf("\nСлучай a = %f, b = %f, c = %f.\n", a, b, c);
                    switch (equation(epsilon, a, b, c, &res1, &res2)) {
                        case SUCCESS:
                            printf("Два решения - %f и %f.\n", res1, res2);
                            break;
                        case INF_ROOTS:
                            printf("Бесконечно много решений.\n");
                            break;
                        case NO_ROOTS:
                            printf("Нет решений.\n");
                            break;
                        case NOT_A_SQUARE_EQUATION:
                            printf("Уравнение не является квадратным. Решение одно - %f.\n", res1);
                            break;
                        case NEGATIVE_DISCRIMINANT:
                            printf("Дискриминант отрицательный, у уравнения нет действительных корней.\n");
                            break;
                        case ERROR_NULL_POINTER:
                            printf("Нулевой указатель.\n");
                            return 1;
                        default:
                            break;
                    }
                    temp = a;
                    a = b;
                    b = c;
                    c = temp;
                }
                temp = c;
                c = b;
                b = temp;
            }

        } else {
            short int ans;
            switch (triangle(epsilon, a, b, c, &ans)) {
                case SUCCESS:
                    if (ans) {
                        printf("Числа могут являться длинами сторон прямоугольного треугольника.\n");
                    } else {
                        printf("Числа не могут являться длинами сторон прямоугольного треугольника.\n");
                    }
                    break;
                case ERROR_WRONG_ARGUMENTS:
                    printf("Длины сторон треугольника должны быть положительными числами.\n");
                    break;
                case ERROR_NULL_POINTER:
                    printf("Нулевой указатель.\n");
                    return 1;
                case ERROR_OVERFLOW:
                    printf("Переполнение ячейки памяти.\n");
                    return 1;
                default:
                    break;
            }
        }

    } else if (flag[1] == 'm') {
        if (argc != 4) {
            printf("Требуется 2 числа для работы.\n");
            return 1;
        }
        int x;
        int y;
        switch (strToInt(argv[2], 10, &x))
        {
            case ERROR_NO_DIGITS_AFTER_MINUS:
                printf("После минуса нет цифр.\n");
                return 1;
            case ERROR_NOT_ALLOWED_SYMBOL:
                printf("Недопустимый символ в числе.\n");
                return 1;
            case ERROR_OVERFLOW:
                printf("Переполнение ячейки памяти.\n");
                return 1;
            case ERROR_NULL_POINTER:
                printf("Нулевой указатель.\n");
                return 1;
            default:
                break;
        }
        switch (strToInt(argv[3], 10, &y))
        {
            case ERROR_NO_DIGITS_AFTER_MINUS:
                printf("После минуса нет цифр.\n");
                return 1;
            case ERROR_NOT_ALLOWED_SYMBOL:
                printf("Недопустимый символ в числе.\n");
                return 1;
            case ERROR_OVERFLOW:
                printf("Переполнение ячейки памяти.\n");
                return 1;
            case ERROR_NULL_POINTER:
                printf("Нулевой указатель.\n");
                return 1;
            default:
                break;
        }

        short int res;

        switch (division(x, y, &res)) {
            case SUCCESS:
                if (res) {
                    printf("Первое число кратно второму.\n");
                } else {
                    printf("Первое число не кратно второму.\n");
                }
                break;
            case ERROR_WRONG_ARGUMENTS:
                printf("Числа должны быть ненулевыми.\n");
                return 1;
            case ERROR_NULL_POINTER:
                printf("Нулевой указатель.\n");
                return 1;
            default:
                break;
        }

        return 0;

    } else {
        printf("Неправильный флаг.\n");
        return 1;
    }

    return 0;
}