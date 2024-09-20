#include "../curses.hpp"
#include <panel.h>
#include <string>

int main(int argc, char **argv)
{
    WINDOW *windowArray[2];
    PANEL *panelArray[2];

    initCurses(panelArray, windowArray);

    printMenu(windowArray[0], true);
    update_panels();
    doupdate();

    getch(); // pause running

    char response[32];
    std::string prompt = "This is the prompt";

    dialogPrompt(windowArray[0], prompt, response, 32);
    wmove(windowArray[1], 2, 2);
    wprintw(windowArray[1], "%s", response);

    update_panels();
    doupdate();
    getch();

    endCurses(panelArray, windowArray);

    return 0;
}
