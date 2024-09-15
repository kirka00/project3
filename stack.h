#ifndef STACK_H
#define STACK_H

void push_operation(char *stack, int *top, char x);
char pop_operation(char *stack, int *top);
void push_number(double *stack, int *top, double x);
double pop_number(double *stack, int *top);

#endif