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
}

// Матрица поворота по Оси X
int rotation_x_matrix(Mat4* matrix, 
		      char  button) {
    int flag_error = SUCCESS;
    
    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {
	float angle;
	if(button == KEY_UP)
	    angle = 
	if(button == KEY_DOWN)
	    angle = //дописать угол
	float c = cos(angle);
	float s = sin(angle);
	matrix->elements = {
	    { 1, 0,  0, 0 },
	    { 0, c, -s, 0 },
	    { 0, s,  c, 0 },
	    { 0, 0 , 0, 1 }
	}
    }

    return flag_error;
}

// Матрица поворота по Оси Y
int rotation_y_matrix(Mat4* matrix, 
		      char  button) {
    int flag_error = SUCCESS;

    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {
	float angle;
	if(button == KEY_LEFT)
	    angle = //дописать угол
	if(button == KEY_RIGHT)
	    angle = //дописать угол
	float c = cos(angle);
	float s = sin(angle);
	matrix->elements = {
	    { c, 0, s, 0 },
	    { 0, 1, 0, 0 },
	    {-s, 0, c, 0 },
	    { 0, 0, 0, 1 }
	}
    }

    return flag_error;
}

// Матрица поворота по Оси Z
int rotation_z_matrix(Mat4* matrix, 
		      int   button) {
    int flag_error = SUCCESS;

    if(!matrix)
	flag_error = ERR_ALLOCATION;
    else {	
	
	float angle;
	/*
	if(button == (заглушка для клавиши обработки)
	    angle = //дописать угол
	if(button == (заглушка для клавиши обработки)
	    angle = //дописать угол
	*/
	float c = cos(angle);
	float s = sin(angle);
	matrix->elements = {
	    { c, -s, 0, 0 },
	    { s,  c, 0, 0 },
	    { 0,  0, 1, 0 },
	    { 0,  0, 0, 1 }
	}
    }

    return flag_error;
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


void handleCases(int   event_type, 
		 char  button,
		 Mat4* processed_matrix) {
    size_t size_events = sizeof(events) / 
	    		 sizeof(events[0]);
    char flag_found = 0;
    for(size_t handler; 
	       handler < size_events && !flag_found; 
	       handler++) {
	if(events[handler].event_type == event_type &&
	   events[handler].button     == button) {
	    events[handler].handler(processed_matrix, button);
	    flag_found = 1;
	}
    }
}
