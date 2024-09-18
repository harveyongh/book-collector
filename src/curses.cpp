#include "curses.hpp"
#include <curses.h>
#include <panel.h>

// TODO Functions
// 1. Init curses
// 2. Create panels/windows
// 3. Write menu to left panel
// 4. Loop print library results to right panel & accept up/down input to scroll
// 5. Destroy panels/windows and kill curses session
// 6. Resize windows

void initCurses(PANEL *panelArray[2], WINDOW *windowArray[2])
{
    initscr(); // Start curses session
    int cols; int lines;
    getmaxyx(stdscr, lines, cols);
    cols /= 3; // Get a third of the screen width

    windowArray[0] = createWindow(lines, cols, 0, 0);
    windowArray[1] = createWindow(lines, 2*cols, 0, cols);

    panelArray[0] = new_panel(windowArray[0]);
    panelArray[1] = new_panel(windowArray[1]);

    // TODO Write menu to panel [0]

    show_panel(panelArray[1]);
    update_panels();
    doupdate();
}

WINDOW *createWindow(int lines, int cols, int y, int x)
{
    WINDOW *localWindow = newwin(lines, cols, y, x);
    box(localWindow, 0, 0);

    wrefresh(localWindow);

    return localWindow;
}
