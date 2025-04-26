#include "main_screen.h"
#include "figures.h"

int main() {
    initscr();             // инициализация ncurses
    noecho();              // не показывать нажатые клавиши
    curs_set(FALSE);       // скрыть курсор
    nodelay(stdscr, TRUE); // не ждать нажатия клавиши

    int WIDTH, HEIGHT;
    getmaxyx(stdscr, HEIGHT, WIDTH);
    
    print_main_grid(WIDTH, HEIGHT); 

    endwin();
    return 0;
}
