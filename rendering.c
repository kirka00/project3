#include "rendering.h"

void rendering_graph(char *postfix, int *everythingIsFine) {
    double coords[MAX_X], stepX = D_Y_UPPER * M_PI / MAX_X, stepY = 2.0 / MAX_Y;
    
    // Считаем значения
    for (int k = 0; k < MAX_X; k++) {
        coords[k] = calculate(postfix, D_Y_LOWER + k * stepX, everythingIsFine);
    }
    
    // Рисуем по высчитанным значеняим
    for (double y = LOWER_LIMIT; y <= UPPER_LIMIT; y += stepY) {
        for (int x = 0; x < MAX_X; x++) {
            printf(coords[x] <= y + stepY / 2 && coords[x] >= y - stepY / 2 ? "*" : ".");
        }
        printf("\n");
    }
}
