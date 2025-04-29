#ifndef FIGURES_H
#define FIGURES_H

#include "../../include/config.h"
#include "../matrix/matrix.h"

typedef struct {
    Mat4  tranform_m;
    float angle_x;
    float angle_y;
    float angle_z;
} TRANSFORM;

// Определение структуры куба
typedef struct {
    Vec3       vertices[8];
    int        edges[12][2];
    char       edge_char;
    TRANSFORM* transform_zone;
} CUBE;



int create_cube(CUBE** cube, 
		float  size, 
		char   display_char);

#endif
