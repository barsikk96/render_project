#include "io/main_screen.h"
#include "figures.h"

int main() {
    initscr();             // инициализация ncurses
    noecho();              // не показывать нажатые клавиши
    curs_set(FALSE);       // скрыть курсор
    cbreak();

    int WIDTH, HEIGHT;
    getmaxyx(stdscr, HEIGHT, WIDTH);

    CUBE* cube = malloc(sizeof(CUBE));
    create_cube(&cube, 4, '#');
    
    Camera cam;
    cam.fov    = M_PI / 2.0F;
    cam.aspect = 1.0f;
    cam.near   = 0.1f;
    cam.far    = 100.0f;
    perspective_projection(&cam);



    print_main_grid(WIDTH, HEIGHT); 

    while(1) {
	refresh();
	sleep(0.02);
    }

    destroy_cube(cube);
    
    endwin();
    return 0;
}
