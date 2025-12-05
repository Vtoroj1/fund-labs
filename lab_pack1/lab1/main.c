#include "func.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Ошибка: неверное число аргументов. \n");
        return 1;
    }

    char* flag = argv[2];
    
    if (flag[0] != '-' && flag[0] != '/') {
        printf("Ошибка: неправильный ввод флага \n");
        return 1;
    }
    
    int num;
    switch (strToInt(argv[1], 10, &num))
    {
    case ERROR_NULL_POINTER:
        printf("Неподходящий указатель\n");
        return 1;

    case ERROR_NO_DIGITS_AFTER_MINUS:
        printf("После минуса нет цифр\n");
        return 1;
    
    case ERROR_NOT_ALLOWED_SYMBOL:
        printf("Недопустимый символ в числе\n");
        return 1;
    
    case ERROR_OVERFLOW:
        printf("Переполнение ячейки памяти\n");
        return 1;

    default:
        break;
    }

    switch (flag[1])
    {
        case 'h':
            switch(findKrat(num))
            {
                case ERROR_ZERO_DIVISION:
                    printf("Деление на ноль\n");
                    break;
                
                case ERROR_NO_NUMBERS_FOUND:
                    printf("Чисел от 1 до 100, кратных %d нет\n", num);
                    break;
                
                default:
                    break;
            }
            break;
        
        case 'p':
            switch(checkPrime(num))
            {
                case ERROR_NOT_PRIME_OR_COMPOSITE:
                    printf("%d - не является простым или составным числом\n", num);
                    break;
                
                case ALTERNATIVE_SUCCESS:
                    printf("%d - составное число\n", num);
                    break;
                
                case SUCCESS:
                    printf("%d - простое число\n", num);
                    break;
            }
            break;
        
        case 's':
            intoHex(num);
            break;
        
        case 'e':
            switch(tablePower(num))
            {
                case ERROR_NUMBER_OUT_OF_RANGE:
                    printf("Число должно находиться в промежутке между 1 и 10\n");
                    break;

                default:
                    break;
            }
            break;
        
        case 'a':
            long int sum;
            switch(sumNat(num, &sum))
            {
                case ERROR_NULL_POINTER:
                    printf("Неподходящий указатель\n");
                    return 1;
                
                case ERROR_NUMBER_MUST_BE_NATURAL:
                    printf("Число должно быть натуральным\n");
                    return 1;
                
                case ERROR_OVERFLOW:
                    printf("Переполнение ячейки памяти\n");
                    return 1;
                
                case SUCCESS:
                    printf("%ld\n", sum);
                    break;
            }
            break;
        
        case 'f':
            long long int factor;
            switch(findFact(num, &factor))
            {
                case ERROR_NULL_POINTER:
                    printf("Неподходящий указатель\n");
                    return 1;
                
                case ERROR_NUMBER_CANT_BE_NEGATIVE:
                    printf("Число должно быть неотрицательным\n");
                    return 1;

                case ERROR_OVERFLOW:
                    printf("Переполнение ячейки памяти\n");
                    return 1;
                
                case SUCCESS:
                printf("%lld\n", factor);
                break;
            }
            break;
        
        default:
            printf("Неверный ввод флага\n");
            return 1;
            break;
    }

    return 0;
}