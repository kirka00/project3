#include "rendering.h"

void rendering_graph(char *postfix, int *everythingIsFine) {
    double coords[MAX_X];
    for (int k = 0; double x = D_Y_LOWER; x < D_Y_UPPER * M_PI; x += D_Y_UPPER * M_PI / MAX_X, k++) {
        coords[k] = calculate(postfix, x, everythingIsFine);
    }

    for (double y = LOWER_LIMIT; y <= UPPER_LIMIT; y += 2.0 / MAX_Y) {
        for (int x = 0; x < MAX_X; x++) {
            printf("%c", (coords[x] <= y + 1.0 / MAX_Y && coords[x] >= y - 1.0 / MAX_Y) ? '*' : '.');
        }
        printf("\n");
    }
}
