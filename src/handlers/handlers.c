#include "handlers.h"

// Обработка событий с трансформацией матрицы
int handleCases(int    event_type, 
                int    button,
                Mat4*  t_matrix,
                float* angle) {
    int flag_error = SUCCESS;

    if(!t_matrix || !angle)
        flag_error = ERR_ALLOCATION;
    else {
        size_t size_events = sizeof(events) / 
                             sizeof(events[0]);
        Mat4 event_matrix;
        char flag_found = 0;
        for(size_t handler; 
                   handler < size_events && !flag_found; 
                   handler++) {
            if(events[handler].event_type == event_type &&
               events[handler].button     == button) {
                events[handler].handler(&event_matrix, button, angle);
                multiply_matrices(t_matrix, &event_matrix, t_matrix);
                flag_found = 1;
            }
        }
    }
    return flag_error;
}


