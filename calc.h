#ifndef CALC_H
#define CALC_H

#include <math.h>
#include <stdlib.h>
#include "parse_exp.h"
#include "stack.h"

double calculate(char *postfix, double x, int *everythingIsFine);
int calculate_operation(char *postfix, double num1, double num2, double *result, double *nums, int *top);

#endif