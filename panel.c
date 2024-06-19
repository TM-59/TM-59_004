#include <ncurses.h>
#include <panel.h>

int main() {
    // Initialize ncurses
    initscr();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    // Create a new window for the panel
    WINDOW* win = newwin(10, 20, 5, 10);
    wbkgd(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Hello, Panel!");

    // Create a new panel for the window
    PANEL* panel = new_panel(win);

    // Update the screen to show the panel
    update_panels();
    doupdate();

    // Wait for user input
    getch();

    // Clean up and exit
    del_panel(panel);
    delwin(win);
    endwin();

    return 0;
}