#include "tests.h"

int main() {
    CUBE* cube = malloc(sizeof(CUBE));
    create_cube(&cube, 4, '#');
    destroy_cube(cube);

    return 0;
}
