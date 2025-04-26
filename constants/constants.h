#ifndef CONSTANTS_H
#define CONSTANTS_H

#define GRID_SPACING 10
#define SQ_MAT_SIZE 4

#include <stdio.h>

typedef struct { float x, y, z; } Vec3;

// Коды ошибок
enum {
    // Ошибки нет, все прошло успешно
    SUCCESS 	   = 0,
    // Не удалось выделить память
    ERR_ALLOCATION = 1
};

#endif
