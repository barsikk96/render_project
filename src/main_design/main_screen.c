#include "main_screen.h"

void print_main_grid(int width, int height) {
    int centerX = width / 2;
    int centerY = height / 2;

    while(1) {
        clear();

        // Рисуем оси координат
        for(int y = 0; y < height; y++) {
            mvaddch(y, centerX, (y == centerY) ? '+' : '|');
        }
        for(int x = 0; x < width; x++) {
            mvaddch(centerY, x, (x == centerX) ? '+' : '-');
        }

        // Рисуем вспомогательную сетку
        for(int x = centerX - GRID_SPACING; x >= 0; x -= GRID_SPACING) {
            for (int y = 0; y < height; y++) {
                if(y != centerY) mvaddch(y, x, ':');
            }
        }
        for(int x = centerX + GRID_SPACING; x < width; x += GRID_SPACING) {
            for (int y = 0; y < height; y++) {
                if(y != centerY) mvaddch(y, x, ':');
            }
        }
        for(int y = centerY - GRID_SPACING; y >= 0; y -= GRID_SPACING) {
            for (int x = 0; x < width; x++) {
                if(x != centerX) mvprintw(y, x, "`");
            }
        }
	for(int y = centerY + GRID_SPACING; y < height; y += GRID_SPACING) {
            for(int x = 0; x < width; x++) {
                if(x != centerX) mvprintw(y, x, "`");
            }
        }

        refresh();
        sleep(50000);
    }
}
