#ifndef CONFIG_H
#define CONFIG_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

// Размер сетки
#define GRID_SPACING 5

// Размер матрицы фигуры
#define SQ_MAT_SIZE 4

// Угол поворота
#define ROTATE_ANGLE 2.0f

// Определение вектора из двух элементов
typedef struct { float x, y; }    Vec2;

// Определение вектора из трех элементов
typedef struct { float x, y, z; } Vec3;

// Коды ошибок
enum {
    // Ошибки нет, все прошло успешно
    SUCCESS 	   = 0,
    // Не удалось выделить память
    ERR_ALLOCATION = 1
};

// Типы событий
enum {
    ROTATE
};



#endif
