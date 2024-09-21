#ifndef CURSES_HPP
#define CURSES_HPP

#include "book.hpp"

#include <ncurses.h>
#include <panel.h>
#include <string>

void initCurses(PANEL *panelArray[2], WINDOW *windowArray[2]);
WINDOW *createWindow(int lines, int cols, int y, int x);
void endCurses(PANEL *panelArray[2], WINDOW *windowArray[2]);

void printMenu(WINDOW *menuWindow, bool libraryOpenFlag);
void dialogPrompt(WINDOW *menuWindow, std::string prompt, char *response, int size);
void printBook(WINDOW *window, Book book, int offset);

void resizeWindows(WINDOW *windowArray[2]);
void resetWindow(WINDOW *window);
void resetAllWins(WINDOW *windowArray[2]);

#endif // CURSES_HPP
