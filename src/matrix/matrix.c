#include "matrix.h"

// Инициализация единичной матрицы
int identity_matrix(Mat4* matrix) {
    int flag_error = SUCCESS;

    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {
	memset(matrix->elements, 0, sizeof(matrix->elements));
	for(size_t index = 0; 
		   index < SQ_MAT_SIZE; 
		   index++)
	    matrix->elements[index][index] = 1.0f;
    }

    return flag_error;
}

// Матрица поворота по Оси X
int rotation_x_matrix(Mat4*  matrix, 
		      int    button,
		      float* angle_x) {
    int flag_error = SUCCESS;
    
    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {
	float step = ROTATE_ANGLE * (M_PI / 180.0f);
	
	if(button == KEY_UP)
	    *angle_x += step;
	if(button == KEY_DOWN)
	    *angle_x -= step;
	
	float c = cos(*angle_x);
	float s = sin(*angle_x);

	memset(matrix->elements, 0, sizeof(matrix->elements));
	matrix->elements[0][0] =  1.0f;
	matrix->elements[1][1] =  c;
	matrix->elements[1][2] = -s;
	matrix->elements[2][1] =  s;
	matrix->elements[2][2] =  c;
	matrix->elements[3][3] =  1.0f;
    }

    return flag_error;
}

// Матрица поворота по Оси Y
int rotation_y_matrix(Mat4*  matrix, 
		      int    button,
		      float* angle_y) {
    int flag_error = SUCCESS;

    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {
	float step = ROTATE_ANGLE * (M_PI / 180.0f);
	
	if(button == KEY_LEFT)
	    *angle_y += step;
	if(button == KEY_RIGHT)
	    *angle_y -= step;
	
	float c = cos(*angle_y);
	float s = sin(*angle_y);

	memset(matrix->elements, 0, sizeof(matrix->elements));
	matrix->elements[0][0] =  c;
	matrix->elements[0][2] =  s;
	matrix->elements[1][1] =  1.0f;
	matrix->elements[2][0] =  -s;
	matrix->elements[2][2] =  c;
	matrix->elements[3][3] =  1.0f;

    }

    return flag_error;
}

// Матрица поворота по Оси Z
int rotation_z_matrix(Mat4*  matrix, 
		      int    button,
		      float* angle_z) {
    int flag_error = SUCCESS;

    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {		
	float step = ROTATE_ANGLE * (M_PI / 180.0f);
	
	if(button == 4)
	    *angle_z += step;
	if(button == 6)
	    *angle_z -= step;

	float c = cos(*angle_z);
	float s = sin(*angle_z);

	memset(matrix->elements, 0, sizeof(matrix->elements));
	matrix->elements[0][0] =  c;
	matrix->elements[0][1] = -s;
	matrix->elements[1][1] =  s;
	matrix->elements[1][2] =  c;
	matrix->elements[2][2] =  1.0f;
	matrix->elements[3][3] =  1.0f;
    }

    return flag_error;
}

// Умножение матриц
int multiply_matrices(const Mat4* A, 
		      const Mat4* B, 
		      	    Mat4* res) {
    int flag_error = SUCCESS;

    if (!(A && B))
        flag_error = ERR_ALLOCATION;
    else {
      for (size_t rows = 0; 
		  rows < SQ_MAT_SIZE; 
		  rows++) {
        for (size_t cols = 0; 
		    cols < SQ_MAT_SIZE; 
		    cols++) {
          res->elements[rows][cols] = 0;
          for (size_t index_sum = 0; 
	 	      index_sum < SQ_MAT_SIZE; 
		      index_sum++)
            res->elements[rows][cols] += A->elements[rows][index_sum] * 
		    	       		 B->elements[index_sum][cols];
        }
      }
    }
    return flag_error;
}

int mat4_mul_vec3(Mat4* matrix, 
		  Vec3* vector, 
		  Vec3* res_v) {
    int flag_error = SUCCESS;

    res_v->x = matrix->elements[0][0]*vector->x + 
	       matrix->elements[0][1]*vector->y + 
	       matrix->elements[0][2]*vector->z + 
	       matrix->elements[0][3];
    res_v->y = matrix->elements[1][0]*vector->x + 
	       matrix->elements[1][1]*vector->y + 
	       matrix->elements[1][2]*vector->z + 
	       matrix->elements[1][3];
    res_v->z = matrix->elements[2][0]*vector->x + 
	       matrix->elements[2][1]*vector->y + 
	       matrix->elements[2][2]*vector->z + 
	       matrix->elements[2][3];
    float  w = matrix->elements[3][0]*vector->x + 
	       matrix->elements[3][1]*vector->y + 
	       matrix->elements[3][2]*vector->z + 
	       matrix->elements[3][3];
    
    if(w != 0.0f) {
	res_v->x /= w;
	res_v->y /= w;
	res_v->z /= w;
    }

    return flag_error;
}
