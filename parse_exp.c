#include "parse_exp.h"

char *input_expression() {
    char *input = malloc(sizeof(char) * SIZE);
    if (fgets(input, SIZE, stdin) == NULL) {
        free(input);
    }
    if (input != NULL)
    {
        // Удаляем символ новой строки, если он есть
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
    return input;
}

// приоритет операций
int priority_of_operations(char operation) {
    int flag = 0;
    switch (operation) {
        case SIN:
        case COS: 
        case TG:
        case CTG:
        case SQRT:
        case LN:
        case UMINUS:
            flag = 3;
            break;
        case MUL:
        case DIV:
            flag = 2;
            break;
        case PLUS:
        case MINUS:
            flag = 1;
            break;
    }
    return flag;
}

// проверка на оператор
int this_operation(char ch) { 
    return ch == PLUS || ch == MINUS || ch == MUL || ch == DIV; 
}

// проверка на функцию
int this_function(const char *input, int i, int len) {
    int answer = 0;
    if (i + 2 < len) {
        if (strncmp(&input[i], "sin", 3) == 0) answer = sinF;
        if (strncmp(&input[i], "cos", 3) == 0) answer =  cosF;
        if (strncmp(&input[i], "tan", 3) == 0) answer = tanF;
        if (strncmp(&input[i], "ctg", 3) == 0) answer = ctgF;
    }
    if (i + 3 < len && strncmp(&input[i], "sqrt", 4) == 0) answer = sqrtF;
    if (i + 1 < len && strncmp(&input[i], "ln", 2) == 0) answer = lnF;
    if (input[i] == '~') answer = unaryMinusF;
    return answer;
}

// польская нотация
char *convert(char *input, int len, int *everythingIsFine) {
    char *result = malloc((len * 2) * sizeof(char)), stack[50];
    int top = -1, j, i, flag = 0;
    for (i = 0, j = 0; i < len && *(everythingIsFine); i++) {
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == 'x') {
            while ((input[i] >= '0' && (int)input[i] <= '9') || input[i] == '.' || (input[i] == 'x')) {
                result[j++] = input[i];
                flag = 1;
                i++;
            }
            i--;
        } else if (input[i] == '(') {
            push_operation(stack, &top, input[i]);
        } else if (input[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                result[j++] = pop_operation(stack, &top);
                result[j++] = ' ';
            }
            if (top > -1 && stack[top] != '(')
                *(everythingIsFine) = 0;
            else
                top--;
        } else if (this_operation(input[i]) || this_function(input, i, len)) {
            int func = this_function(input, i, len);
            while (!func && top > -1 && priority_of_operations(stack[top]) >= priority_of_operations(input[i])) {
                result[j++] = pop_operation(stack, &top);
                result[j++] = ' ';
            }
            push_operations(func, stack, &top, input, &i);
        } else
            *(everythingIsFine) = 0;
        if (flag) {
            result[j++] = ' ';
            flag = 0;
        }
    }
    while (top > -1) {
        result[j++] = pop_operation(stack, &top);
        result[j++] = ' ';
    }
    result[j] = '\0';
    return result;
}

// отправка операторов в стек
void push_operations(int func, char stack[SIZE], int *top, char *input, int *i) {
    if (func == 0)
    {
        push_operation(stack, top, input[*i]);
    }
    else if (func == sinF)
    {
        push_operation(stack, top, SIN);
        *i += 2;
    }
    else if (func == cosF)
    {
        push_operation(stack, top, COS);
        *i += 2;
    }
    else if (func == tanF)
    {
        push_operation(stack, top, TG);
        *i += 2;
    }
    else if (func == ctgF)
    {
        push_operation(stack, top, CTG);
        *i += 2;
    }
    else if (func == sqrtF)
    {
        push_operation(stack, top, SQRT);
        *i += 3;
    }
    else if (func == lnF)
    {
        push_operation(stack, top, LN);
        *i += 1;
    }
    else if (func == unaryMinusF)
    {
        push_operation(stack, top, UMINUS);
    }
}

int sCount(char *str) {
    int l_k = 0, r_k = 0, flag = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            l_k++;
        } else if (str[i] == ')') {
            r_k++;
            if (str[i + 1] == '(') {
                flag = 0;
            }
        }
    }
    return flag && l_k == r_k;
}

int checkOpers(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (this_operation(str[i]) == 1 || str[i] == '~') {
            if (this_operation(str[i + 1]) == 1 || str[i + 1] == '~') {
                return 0;
            }
        }
    }
    return 1;
}
