#ifndef RENDERING_H
#define RENDERING_H

#include <math.h>
#include <stdio.h>
#include "calc.h"

// Размеры поля
#define MAX_X 80
#define MAX_Y 25
// Область определения
#define D_Y_LOWER 0.0
#define D_Y_UPPER 4.0
// Область значений
#define LOWER_LIMIT -1
#define UPPER_LIMIT 1


void rendering_graph(char *postfix, int *everythingIsFine);

#endif