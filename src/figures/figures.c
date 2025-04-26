#include "figures.h"

int create_cube(CUBE** cube, float size, char display_char) {
    int   flag_error = SUCCESS;

    float half_size  = size / 2.0f;

    (*cube)->vertices[0] = (Vec3){ -half_size, -half_size, -half_size }; // левая-нижняя-дальняя
    (*cube)->vertices[1] = (Vec3){  half_size, -half_size, -half_size }; // правая-нижняя-дальняя
    (*cube)->vertices[2] = (Vec3){  half_size,  half_size, -half_size }; // правая-верхняя-дальняя
    (*cube)->vertices[3] = (Vec3){ -half_size,  half_size, -half_size }; // левая-верхняя-дальняя
    (*cube)->vertices[4] = (Vec3){ -half_size, -half_size,  half_size }; // левая-нижняя-ближняя
    (*cube)->vertices[5] = (Vec3){  half_size, -half_size,  half_size }; // правая-нижняя-ближняя
    (*cube)->vertices[6] = (Vec3){  half_size,  half_size,  half_size }; // правая-верхняя-ближняя
    (*cube)->vertices[7] = (Vec3){ -half_size,  half_size,  half_size }; // левая-верхняя-ближняя

    // Задаем рёбра
    int edges[12][2] = {
	{0, 1}, {1, 2}, {2, 3}, {3, 0},
	{4, 5}, {5, 6}, {6, 7}, {7, 4},
	{0, 4}, {1, 5}, {2, 6}, {3, 7}
    };
    memcpy((*cube)->edges, edges, sizeof(edges));

    (*cube)->edge_char = display_char;

    identity_matrix(&((*cube)->transform));

    return flag_error;
}
