#include "func.h"

int check_brackets(const char *str) {

    if (str == NULL) {
        return -1;
    }

    size_t len = strlen(str);

    if (len == 0) {
        return 0;
    }

    char *stack = (char *)malloc(len * sizeof(char));

    if (stack == NULL) {
        return -1;
    }

    int top = -1;
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        char cur = str[i];
        
        if (cur == '(' || cur == '[' || cur == '{' || cur == '<') {
            stack[++top] = cur;
        } else if (cur == ')' || cur == ']' || cur == '}' || cur == '>') {
            if (top == -1) {
                free(stack);
                return 1;
            }
            
            char last = stack[top--];
            if (!((last == '(' && cur == ')') ||
                  (last == '[' && cur == ']') ||
                  (last == '{' && cur == '}') ||
                  (last == '<' && cur == '>'))) {
                free(stack);
                return 1;
            }
        }
    }
    
    int res = (top == -1) ? 0 : 1;
    free(stack);
    return res;
}