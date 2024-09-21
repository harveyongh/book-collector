#include "../curses.hpp"
#include <curses.h>
#include <panel.h>
#include <string>

void updateHelper();

int main(int argc, char **argv)
{
    WINDOW *windowArray[2];
    PANEL *panelArray[2];

    initCurses(panelArray, windowArray);

    printMenu(windowArray[0], true);
    updateHelper();
    getch(); // pause running

    std::string bookArray[4] = {"testbook", "testlast", "testfirst", "1999"};
    Book book(bookArray);
    printBook(windowArray[1], book, 0);
    updateHelper();
    getch();

    printBook(windowArray[1], book, 1);
    updateHelper();
    getch();

    getch();

    endCurses(panelArray, windowArray);

    return 0;
}

void updateHelper()
{
    update_panels();
    doupdate();
}
