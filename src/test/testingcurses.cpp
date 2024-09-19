#include "../curses.hpp"
#include <panel.h>

int main(int argc, char **argv)
{
    WINDOW *windowArray[2];
    PANEL *panelArray[2];

    initCurses(panelArray, windowArray);

    printMenu(windowArray[0], true);
    update_panels();
    doupdate();

    getch(); // pause running

    endCurses(panelArray, windowArray);

    return 0;
}
