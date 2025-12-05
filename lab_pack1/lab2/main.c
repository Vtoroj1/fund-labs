#include "func.h"

int main(int argc, char *argv[]){
    if (argc != 1) {
        printf("Программа не должна принимать аргументов\n");
        return 1;
    }

    long long N;
    printf("Введите N - количество запросов:\n");
    if (scanf("%lld", &N) != 1 || N <= 0 || N > INT_MAX){
        printf("Неправильный ввод\n");
        return 1;
    }
    if (check()) {
        printf("Были введены лишние данные\n");
        return 1;
    }
    
    int num = (int)N;

    int *nums = (int*)malloc(num * sizeof(int));
    if (nums == NULL) {
        printf("Не удалось выделить память\n");
        return 1;
    }
    
    printf("Введите порядковые номера:\n");

    for (int i = 0; i < num; i++){
        if (scanf("%d", &nums[i]) != 1 || nums[i] <= 0){
            printf("Неправильный ввод\n");
            free(nums);
            return 1;
        }

        if (check()) {
            printf("Были введены лишние данные\n");
            return 1;
        }
    }
    
    int max_number;
    if (max(nums, num, &max_number)) {
        free(nums);
        printf("Неверно введённые данные\n");
        return 1;
    }

    int* prime_numbers = (int*)calloc(max_number, sizeof(int));

    if (findPrime(max_number, prime_numbers)) {
        free(prime_numbers);
        free(nums);
        printf("Не удалось найти простые числа\n");
        return 1;
    }

    printf("Результат:\n");
    for (int i = 0; i < num; i++) {
        printf("%d \n", prime_numbers[nums[i] - 1]);
    }

    free(prime_numbers);
    free(nums);
    
    return 0;
}