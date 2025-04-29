#ifndef MATRIX_H
#define MATRIX_H

#include <string.h>
#include "../../include/config.h"

// Определение структуры квадратной матрицы
typedef struct {
    float elements[SQ_MAT_SIZE][SQ_MAT_SIZE]; 
} Mat4;

typedef int (*HandlerFunc)(Mat4*, char);

typedef struct {
    int  event_type;
    char button;
    HandlerFunc handler;
} CaseHandler;

CaseHandler events[] = {
    {ROTATE, KEY_UP,    rotation_x_matrix}, 
    {ROTATE, KEY_DOWN,  rotation_x_matrix}, 
    {ROTATE, KEY_LEFT,  rotation_y_matrix}, 
    {ROTATE, KEY_RIGHT, rotation_y_matrix}
};

void identity_matrix(Mat4* matrix);

int  multiply_matrices(const Mat4* A, 
		       const Mat4* B, 
		       	     Mat4* res);

//ДОПИСАТЬ ВСЕ ФУНКЦИИ ИЗ СИ ФАЙЛА

#endif
