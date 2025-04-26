#ifndef MATRIX_H
#define MATRIX_H

#include <string.h>
#include "../constants/constants.h"

// Определение структуры квадратной матрицы
typedef struct {
    float elements[SQ_MAT_SIZE][SQ_MAT_SIZE]; 
} Mat4;

void identity_matrix(Mat4* matrix);

int  multiply_matrices(const Mat4* A, 
		       const Mat4* B, 
		       	     Mat4* res);

#endif
