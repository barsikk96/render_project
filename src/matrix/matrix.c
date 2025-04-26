#include "matrix.h"

void identity_matrix(Mat4*   matrix) {
    memset(matrix->elements, 0, sizeof(matrix));
    for(size_t index = 0; 
	       index < SQ_MAT_SIZE; 
	       index++) {
	matrix->elements[index][index] = 1.0f;
    }
}

int multiply_matrices(const Mat4* A, 
		      const Mat4* B, 
		      	    Mat4* res) {
    int flag_error = SUCCESS;

    if (!(A && B))
        flag_error = ERR_ALLOCATION;
    else { // Проверка успешного выделения памяти
      for (size_t rows = 0; 
		  rows < SQ_MAT_SIZE; 
		  rows++) {
        for (size_t cols = 0; 
		    cols < SQ_MAT_SIZE; 
		    cols++) {
          res->elements[rows][cols] = 0; // Обнуление перед вычислением
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
