#include "main_screen.h"

void print_main_grid(int term_width, int term_height) {

    const double margin = 0.2;
    int border_left = term_width * margin;
    int border_right = term_width * (1 - margin);
    int border_top = term_height * margin;
    int border_bottom = term_height * (1 - margin);

    int center_x = term_width / 2;
    int center_y = term_height / 2;

    for (int x = border_left; x <= border_right; x++) {
        mvaddch(border_top, x, '-');      
        mvaddch(border_bottom, x, '-');   
    }
    for (int y = border_top; y <= border_bottom; y++) {
        mvaddch(y, border_left, '|');     
        mvaddch(y, border_right, '|');    
    }
    
    mvaddch(border_top, border_left, '+');
    mvaddch(border_top, border_right, '+');
    mvaddch(border_bottom, border_left, '+');
    mvaddch(border_bottom, border_right, '+');

    for (int x = border_left + 1; x < border_right; x++) {
        if (x != center_x) {
            mvaddch(center_y, x, '-');
        } else {
            mvaddch(center_y, x, '+');  
        }
    }

    for (int y = border_top + 1; y < border_bottom; y++) {
        if (y != center_y) {
            mvaddch(y, center_x, '|');
        } else {
            mvaddch(y, center_x, '+');  
        }
    }

    for (int x = center_x - GRID_SPACING; x > border_left; x -= GRID_SPACING) {
        for (int y = border_top + 1; y < border_bottom; y++) {
            if (y != center_y) mvaddch(y, x, ':');
        }
    }
    for (int x = center_x + GRID_SPACING; x < border_right; x += GRID_SPACING) {
        for (int y = border_top + 1; y < border_bottom; y++) {
            if (y != center_y) mvaddch(y, x, ':');
        }
    }

    for (int y = center_y - GRID_SPACING; y > border_top; y -= GRID_SPACING) {
        for (int x = border_left + 1; x < border_right; x++) {
            if (x != center_x) mvaddch(y, x, '`');
        }
    }
    for (int y = center_y + GRID_SPACING; y < border_bottom; y += GRID_SPACING) {
        for (int x = border_left + 1; x < border_right; x++) {
            if (x != center_x) mvaddch(y, x, '`');
        }
    }
}
