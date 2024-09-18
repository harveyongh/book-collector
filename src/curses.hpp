#ifndef CURSES_HPP
#define CURSES_HPP

#include <ncurses.h>
#include <panel.h>

void initCurses(PANEL *panelArray, WINDOW *windowArray);
WINDOW *createWindow(int lines, int cols, int y, int x);

void printMenu(WINDOW *menuWindow);

#endif // CURSES_HPP
