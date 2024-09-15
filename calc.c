#include "calc.h"

double calculate(char *postfix, double x, int *everythingIsFine) {
    double nums[100], num1, num2, result;
    int top = -1, isDouble = 0;
    while (*postfix != '\0' && *everythingIsFine) {
        if (*postfix == 'x') {
            push_number(nums, &top, x);
        } else if (*postfix >= '0' && *postfix <= '9') {
            double currentNum = 0;

            while (*postfix != 'x' && *postfix != ' ') {
                if (*postfix != '.' && !isDouble) {
                    currentNum = currentNum * 10 + (double)(*postfix - 48);
                    postfix++;
                } else if (*postfix == '.' && !isDouble) {
                    postfix++;
                    isDouble = 1;
                } else {
                    currentNum = currentNum + (double)(*postfix - 48) / pow(10, isDouble);
                    postfix++;
                    isDouble++;
                }
            }
            postfix--;
            isDouble = 0;
            push_number(nums, &top, currentNum);
        } else if (*postfix != ' ') {
            num1 = pop_number(nums, &top);
            num2 = pop_number(nums, &top);
            if (isnan(num1) == 0) {
                *everythingIsFine = calculate_operation(postfix, num1, num2, &result, nums, &top);
                if (*everythingIsFine == 1) {
                    push_number(nums, &top, result);
                }
            }
        }
        postfix++;
    }
    return pop_number(nums, &top);
}

int calculate_operation(char *postfix, double num1, double num2, double *result, double *nums, int *top) {
    int flag = 1;
    if (*postfix == PLUS)
    {
        *result = num2 + num1;
    }
    else if (*postfix == MINUS)
    {
        *result = num2 - num1;
    }
    else if (*postfix == MUL)
    {
        *result = num2 * num1;
    }
    else if (*postfix == DIV)
    {
        *result = num2 / num1;
    }
    else if (*postfix == SIN)
    {
        *result = sin(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == COS)
    {
        *result = cos(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == TG)
    {
        *result = tan(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == CTG)
    {
        *result = 1 / tan(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == SQRT)
    {
        *result = sqrt(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == LN)
    {
        *result = log(num1);
        push_number(nums, top, num2);
    }
    else if (*postfix == UMINUS)
    {
        *result = -num1;
        push_number(nums, top, num2);
    }
    else
    {
        flag = 0;
    }
    return flag;
}