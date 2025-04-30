#ifndef MATRIX_H
#define MATRIX_H

#include "../../include/config.h"

// Определение структуры квадратной матрицы
typedef struct {
    float elements[SQ_MAT_SIZE][SQ_MAT_SIZE]; 
} Mat4;

// Инициализация единичной матрицы
int identity_matrix(Mat4* matrix);

// Матрица поворота по Оси X
int rotation_x_matrix(Mat4*  matrix, 
                      int    button,
                      float* angle_x);

// Матрица поворота по Оси Y
int rotation_y_matrix(Mat4*  matrix, 
                      int    button,
                      float* angle_y);

// Матрица поворота по Оси Z
int rotation_z_matrix(Mat4*  matrix, 
                      int    button,
                      float* angle_z);

// Умножение матриц
int multiply_matrices(const Mat4* A, 
		      const Mat4* B, 
		       	    Mat4* res);

// Умножение квадратной матрицы на вектор из трех элементов
int mat4_mul_vec3(Mat4* matrix,
		  Vec3* vector,
		  Vec3* res_v);

#endif
