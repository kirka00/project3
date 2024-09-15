#include "stack.h"

void push_operation(char *stack, int *top, char x) {
    stack[*top += 1] = x;
}

char pop_operation(char *stack, int *top) {
    char x = stack[*top];
    *top -= 1;
    return x;
}

void push_number(double *stack, int *top, double x) {
    stack[*top += 1] = x;
}

double pop_number(double *stack, int *top) {
    double x = stack[*top];
    *top -= 1;
    return x;
}

