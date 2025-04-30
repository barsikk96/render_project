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

// Отрисовка линий
void draw_line(int  x1, int y1,
	       int  x2, int y2,
	       char ch);

// Преобразование и отрисовка куба
int render_cube(const CUBE* cube,
		      Mat4  projection,
		      int   term_width,
		      int   term_height);

#endif
