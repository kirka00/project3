#ifndef PARSE_EXP_H
#define PARSE_EXP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define SIZE 100
#define SIN 's'
#define sinF 1
#define COS 'c'
#define cosF 2
#define TG 't'
#define tanF 3
#define CTG 'g'
#define ctgF 4
#define SQRT 'q'
#define sqrtF 5
#define LN 'l'
#define lnF 6
#define PLUS '+'
#define MINUS '-'
#define MUL '*'
#define DIV '/'
#define unaryMinusF 7
#define UMINUS '~'

char *input_expression();
int priority_of_operations(char operation);
int this_operation(char ch);
char *convert(char *input, int len, int *everythingIsFine);
int this_function(const char *input, int i, int len);
void push_operations(int func, char stack[50], int *top, char *input, int *i);
int sCount(char *str);
int checkOpers(char *str);

#endif