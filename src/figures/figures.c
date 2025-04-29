#include "figures.h"

int create_cube(CUBE** cube, 
		float  size, 
		char   display_char) {
    int flag_error = SUCCESS;
    
    if(!cube) 
    	flag_error = ERR_ALLOCATION;
    else {
	(*cube)->t_zone = malloc(sizeof(TRANSFORM));
    	if (!(*cube)->t_zone) {
            free(*cube);
            flag_error = ERR_ALLOCATION;
        } else {
	    float half_size  = size / 2.0f;
	    
	    // левая-нижняя-дальняя
	    (*cube)->vertices[0] = (Vec3){ -half_size, 
	    			           -half_size, 
	    			           -half_size }; 
	    // правая-нижняя-дальняя
	    (*cube)->vertices[1] = (Vec3){  half_size, 
	    	                       	   -half_size, 
	    			           -half_size }; 
	    // правая-верхняя-дальняя
	    (*cube)->vertices[2] = (Vec3){  half_size,  
	    	   		            half_size, 
	    			           -half_size }; 
	    // левая-верхняя-дальняя
	    (*cube)->vertices[3] = (Vec3){ -half_size,  
	    	 			    half_size, 
	    			           -half_size }; 
	    // левая-нижняя-ближняя
	    (*cube)->vertices[4] = (Vec3){ -half_size, 
	    			           -half_size,  
	    			       	    half_size }; 
	    // правая-нижняя-ближняя
	    (*cube)->vertices[5] = (Vec3){  half_size, 
	    			       	   -half_size,  
	    			            half_size }; 
	    // правая-верхняя-ближняя
	    (*cube)->vertices[6] = (Vec3){  half_size,  
	    	 			    half_size,  
	    				    half_size }; 
	    // левая-верхняя-ближняя
	    (*cube)->vertices[7] = (Vec3){ -half_size,  
	    				    half_size,  
	    				    half_size }; 

	    // Задаем рёбра
	    int edges[12][2] = {
	        {0, 1}, {1, 2}, {2, 3}, {3, 0},
	        {4, 5}, {5, 6}, {6, 7}, {7, 4},
	        {0, 4}, {1, 5}, {2, 6}, {3, 7}
	    };
	    memcpy((*cube)->edges, edges, sizeof(edges));

	    (*cube)->edge_char = display_char;

	    identity_matrix(&(*cube)->t_zone->t_matrix);
        }
    }
    return flag_error;
}

// Очищение структур куба
void destroy_cube(CUBE* cube) {
    if (cube) {
        free(cube->t_zone);  
        free(cube); 
    }
}
