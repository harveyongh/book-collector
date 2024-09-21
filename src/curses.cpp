#include "book.hpp"
#include "curses.hpp"

#include <curses.h>
#include <panel.h>
#include <string.h>

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

void endCurses(PANEL *panelArray[2], WINDOW *windowArray[2])
{
    delwin(windowArray[0]); delwin(windowArray[1]);

    endwin();
}

// Helper function creates the standard window with given attributes
WINDOW *createWindow(int lines, int cols, int y, int x)
{
    WINDOW *localWindow = newwin(lines, cols, y, x);
    box(localWindow, 0, 0);

    wrefresh(localWindow);

    return localWindow;
}

// Prints the standard menu to the given window
// SHOULD BE USED ON WINDOW [0]
void printMenu(WINDOW *menuWindow, bool libraryOpenFlag)
{
    resetWindow(menuWindow);

    mvwprintw(menuWindow, 2, 2, "Menu Options:");
    mvwprintw(menuWindow, 3, 2, "--------------------------------");
    mvwprintw(menuWindow, 4, 2, "(o)pen a library file");
    if (libraryOpenFlag)
    {
        mvwprintw(menuWindow, 5, 2, "(a)dd a book to the library");
        mvwprintw(menuWindow, 6, 2, "(d)elete a book from the library");
        mvwprintw(menuWindow, 7, 2, "(s)ort the library by author");
        mvwprintw(menuWindow, 8, 2, "(f)ilter the library");
        mvwprintw(menuWindow, 9, 2, "(w)rite library to file");
        mvwprintw(menuWindow, 10, 2, "(c)lose the library file");
        mvwprintw(menuWindow, 11, 2, "(e)xit the program");
    }
    else
    {
        mvwprintw(menuWindow, 5, 2, "(e)xit the program");
    }
}

/* dialogPrompt() takes a prompt given by the MENU to print to window
 * and a character array to hold the response
 * This function can theoretically take a char array of any size
 * but obviously some sizes will be less useful for user input */
void dialogPrompt(WINDOW *menuWindow, std::string prompt, char* response, int size)
{
    const char *charPrompt = prompt.c_str();

    resetWindow(menuWindow);

    mvwprintw(menuWindow, 5, 2, "%s", charPrompt);
    wmove(menuWindow, 6, 2);
    wgetnstr(menuWindow, response, size);
}

/* printBook() takes the window, a book, and an "offset" argument
 * this offset decides where the book's information is printed on the window
 * where each book is given 2 lines of text and a following break */
void printBook(WINDOW *window, Book book, int offset)
{
    int location = (offset * 3) + 2;
    mvwprintw(window, location, 2, "%s, %s %s", book.authorLast.c_str(),
              book.authorFirst.c_str(), book.publishYear.c_str());
    mvwprintw(window, location+1, 4, "%s", book.title.c_str());
}

void resizeWindows(WINDOW *windowArray[2])
{
    refresh(); //refresh stdscr after resize

    int lines; int cols;
    getmaxyx(stdscr, lines, cols);
    cols /= 3;

    wresize(windowArray[0], lines, cols);
    mvwin(windowArray[0], 0, 0);
    wresize(windowArray[1], lines, cols*2);
    mvwin(windowArray[1], 0, cols);

    resetAllWins(windowArray);
}

void resetWindow(WINDOW *window)
{
    wclear(window);
    box(window, 0, 0);
    wrefresh(window);
}

void resetAllWins(WINDOW *windowArray[2])
{
    resetWindow(windowArray[0]);
    resetWindow(windowArray[1]);
}
