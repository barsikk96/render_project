#ifndef HANDLERS_H
#define HANDLERS_H

#include "../../include/config.h"
#include "../matrix/matrix.h"

// Определение типа функции обработки события
typedef int (*HandlerFunc)(Mat4*, int, float*);

// Определение кейса для обработчика событий
typedef struct {
    int  event_type;
    int button;
    HandlerFunc handler;
} CaseHandler;

// Определение "класса" событий
CaseHandler events[] = {
    {ROTATE, KEY_UP,    rotation_x_matrix}, 
    {ROTATE, KEY_DOWN,  rotation_x_matrix}, 
    {ROTATE, KEY_LEFT,  rotation_y_matrix}, 
    {ROTATE, KEY_RIGHT, rotation_y_matrix}
};

// Обработка событий с трансформацией матрицы
int handleCases(int    event_type, 
                int    button,
                Mat4*  t_matrix,
                float* angle);

#endif
