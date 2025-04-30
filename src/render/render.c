#include "render.h"

int perspective_projection(Camera* cam) {
    int flag_error = SUCCESS;
    
    if(cam == NULL)
        flag_error = ERR_ALLOCATION;
    else {
        cam->cached_f = 1.0f / tan(cam->fov / 2.0f);
        cam->cached_f_aspect = cam->cached_f / cam->aspect;
        float range = cam->near - cam->far;

        memset(cam->p_matrix.elements, 0, sizeof(cam->p_matrix.elements));
        cam->p_matrix.elements[0][0] = cam->cached_f_aspect;
        cam->p_matrix.elements[1][1] = cam->cached_f;
        
	cam->p_matrix.elements[2][2] =     (cam->far + cam->near) / (range);
        cam->p_matrix.elements[2][3] = (2 * cam->far * cam->near) / (range);
        
	cam->p_matrix.elements[3][2] = -1;
    }
    
    return flag_error;
}

void draw_line(int  x1, int y1, 
	       int  x2, int y2, 
	       char ch) {
    int dx  = abs(x1 - x0);
    int dy  = abs(y1 - y0);
    int sx  = x0 < x1 ? 1 : -1;
    int sy  = y0 < y1 ? 1 : -1;
    int err = 2 * dy - dx;

    char flag_break = 0;
    while(!flag_break) {
	if(x0 >= 0 && x0 < COLS && 
	   y0 >= 0 && y0 < LINES)
	    mvaddch(y0, x0, ch);

	if(x0 == x1 && 
	   y0 == y1)
	    flag_break = 1;

	if(err >= 0) {
	    y0 += sy;
	    err -= 2 * dx;
	}
	x0 += sx;
	err += 2 * dy;
    }
}

// Преобразование и отрисовка куба
int render_cube(const CUBE* cube, 
		      Mat4  projection, 
		      int   term_width, 
		      int   term_height) {
    int flag_error = SUCCESS;
    
    if(!cube)
	flag_error = ERR_ALLOCATION;
    else {
	const float margin = 0.2f;
	const int   border_left   = term_width  * margin;
	const int   border_right  = term_width  * (1 - margin);
	const int   border_top    = term_height * margin;
	const int   border_bottom = term_height * (1 - margin);
	const int   center_x      = term_width  / 2;
	const int   center_y      = term_height / 2;

	const float scale = fmin(
	    (border_right  - border_left) / 2.5f,
	    (border_bottom - border_top)  / 2.5f
	);

	Vec2 screen_vertices[8];
	for(size_t vert = 0, vert < 8, vert++) {
	    Vec3 v = mat4_mul_vec3(cube->t_zone.t_matrix, 
			    	   cube->vertices[vert]);
	    v = mat4_mul_vec3(projection, v);
	    
	    screen_vertices[vert].x = center_x + (int)(v.x * scale);
	    screen_vertices[vert].y = center_y + (int)(v.y * scale);
	}

	for(size_t edge; edge < 12; edge++) {
	    int v1 = cube->edges[edge][0];
	    int v2 = cube->edges[edge][1];
	    
	    if(screen_vertices[v1].z > 0 &&
	       screen_vertices[v2].z > 0)
		draw_line(
		    screen_vertices[v1].x, screen_vertices[v1].y,
		    screen_vertices[v2].x, screen_vertices[v2].y,
		    cube->edge_char);
	}
    }
}
