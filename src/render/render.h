#ifndef RENDER_H
#define RENDER_H

#include "../../include/config.h"
#include "../matrix/matrix.h"

// Структура камеры
typedef struct {
    float fov, aspect, near, far;
    float cached_f, cached_f_aspect;
    Mat4 p_matrix;
} Camera;

// Инициализация матрицы перспективы
int perspective_projection(Camera* cam);

#endif
