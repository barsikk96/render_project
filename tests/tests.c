#include "tests.h"

int main() {
    CUBE* cube = malloc(sizeof(CUBE));
    create_cube(&cube, 4, '#');
    free(cube);

    return 0;
}
