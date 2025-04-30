#ifndef FIGURES_H
#define FIGURES_H

#include "../../include/config.h"
#include "../matrix/matrix.h"

// Определение структуры зоны трансформации
typedef struct {
    Mat4  t_matrix;
    float angle_x;
    float angle_y;
    float angle_z;
} TRANSFORM;

// Определение структуры куба
typedef struct {
    Vec3       vertices[8];
    int        edges[12][2];
    char       edge_char;
    TRANSFORM* t_zone;
} CUBE;

// Создание куба
int create_cube(CUBE** cube, 
		float  size, 
		char   display_char);

// Очистка структуры куба
void destroy_cube(CUBE* cube);

#endif
