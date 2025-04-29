#ifndef CONSTANTS_H
#define CONSTANTS_H

// Размер сетки
#define GRID_SPACING 5
// Размер матрицы фигуры
#define SQ_MAT_SIZE 4



// Угол поворота
#define ROTATE_ANGLE 2.0f

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <math.h>

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
}



#endif
