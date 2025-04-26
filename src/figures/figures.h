#ifndef FIGURES_H
#define FIGURES_H

#include <string.h>
#include "../../constants/constants.h"
#include "../matrix/matrix.h"

// Определение структуры куба
typedef struct {
    Vec3 vertices[8];
    int edges[12][2];
    char edge_char;
    Mat4 transform;
} CUBE;


int create_cube(CUBE** cube, float size, char display_char);

#endif
