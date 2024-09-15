#include <stdlib.h>
#include <string.h>
#include "parse_exp.h"
#include "calc.h"
#include "rendering.h"

int main() {
    int everythingIsFine = 1;
    char* expression = input_expression();
    if (expression != NULL) {
        // конвертируем наше выражение в польскую нотацию
        everythingIsFine = !sCount(expression) || !checkOpers(expression) ? 0 : 1;
        char* postfix = convert(expression, strlen(expression), &everythingIsFine);
        if (postfix != NULL && everythingIsFine) {
            rendering_graph(postfix, &everythingIsFine); // отрисовка
            free(postfix);
        } else {
            printf("n/a");
            if (postfix != NULL) {
                free(postfix);
            }
        }
    } else {
        printf("n/a");
    }
    if (expression != NULL) {
        free(expression);
    }
    return 0;
}
