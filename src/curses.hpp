#ifndef CURSES_HPP
#define CURSES_HPP

#include <ncurses.h>
#include <panel.h>

void initCurses(PANEL *panelArray[2], WINDOW *windowArray[2]);
WINDOW *createWindow(int lines, int cols, int y, int x);
void endCurses(PANEL *panelArray[2], WINDOW *windowArray[2]);

void printMenu(WINDOW *menuWindow, bool libraryOpenFlag);

#endif // CURSES_HPP
