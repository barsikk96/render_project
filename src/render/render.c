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

// Дописать функсию надо типа
int render_cube()
