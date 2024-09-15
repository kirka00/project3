#include "rendering.h"

void rendering_graph(char *postfix, int *everythingIsFine) {
    int k = 0;
    double coords[MAX_X];
    // Считаем значения
    for (double x = D_Y_LOWER; x < D_Y_UPPER * M_PI; x += D_Y_UPPER * M_PI / MAX_X) {
        coords[k++] = calculate(postfix, x, everythingIsFine);
    }
    // Рисуем по высчитанным значеняим
    for (double y = LOWER_LIMIT; y <= UPPER_LIMIT; y += (2.0 / MAX_Y)) {
        for (int x = 0; x < MAX_X; x++) {
            if (coords[x] <= y + ((2.0 / MAX_Y) / 2.0) && coords[x] >= y - ((2.0 / MAX_Y) / 2.0)) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
