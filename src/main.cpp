#include "book.hpp"
#include "curses.hpp"
#include "library.hpp"
#include "filehandler.hpp"

#include <cstdio> // TO REMOVE
#include <curses.h>
#include <iostream> // TO REMOVE
#include <panel.h>
#include <string.h>

void newBook(WINDOW *window, BookLibrary *currLibrary);
void deleteBook(WINDOW *window, BookLibrary *currLibrary);
void mainLoop(WINDOW *windowArray[2]);
void viewLoop(WINDOW *window, std::vector<Book> *currView);

int main()
{
    WINDOW *windowArray[2];
    PANEL *panelArray[2];
    initCurses(panelArray, windowArray);

    mainLoop(windowArray);

    endCurses(panelArray, windowArray);
    return 0;
}

void newBook(WINDOW *window, BookLibrary *currLibrary)
{
    std::string bookArray[4];
    std::string authorName = "";
    std::string titlePrompt = "Enter the book title";
    std::string authorPrompt = "Enter the author last, first";
    std::string yearPrompt = "Enter the publishing year";

    bookArray[0] = dialogPrompt(window, titlePrompt);
    authorName = dialogPrompt(window, authorPrompt);
    bookArray[1] = authorName.substr(0, authorName.find(","));
    bookArray[2] = authorName.substr((authorName.find(",") + 2), authorName.length());
    bookArray[3] = dialogPrompt(window, yearPrompt);

    currLibrary->addBook(bookArray);
}

void deleteBook(WINDOW *window, BookLibrary *currLibrary)
{
    std::string bookArray[4];
    std::string authorPrompt = "Enter the author's last name";
    std::string titlePrompt = "Enter the book title";

    bookArray[0] = dialogPrompt(window, titlePrompt);
    bookArray[1] = dialogPrompt(window, authorPrompt);
    Book book(bookArray);

    currLibrary->deleteBook(book);
}

void mainLoop(WINDOW *windowArray[2])
{
    bool libraryOpenFlag = false;
    BookLibrary currLibrary;
    std::string fileName;
    std::vector<Book> currView;
    int option = 0;

    while (option != 'e'){
        printMenu(windowArray[0], libraryOpenFlag);
        update_panels();
        doupdate();
        noecho();
        option = getch();

        if (option == KEY_RESIZE)
        {
            resizeWindows(windowArray);
        }
        else if (option == 'o')
        {
            echo();
            fileName = dialogPrompt(windowArray[0], "Enter the filename");
            currLibrary = createLibrary(fileName);
            libraryOpenFlag = true;
        }
        else if (libraryOpenFlag)
        {
            switch (option) {
                case 'w':
                    writeLibrary(&currLibrary);
                    break;
                case 'c':
                    libraryOpenFlag = false;
                    break;
                case 'a':
                    echo();
                    newBook(windowArray[0], &currLibrary);
                    break;
                case 'd':
                    echo();
                    deleteBook(windowArray[0], &currLibrary);
                    break;
                case 's':
                    currView = currLibrary.sort();
                    viewLoop(windowArray[1], &currView);
                    break;
                case 'f':
                    // TODO
                    break;
            }
        }
    }
}

// viewHandler manages scrolling through a given view of the library
// takes the window [1] and the specified "view"
void viewLoop(WINDOW *window, std::vector<Book> *currView)
{
    keypad(stdscr, TRUE);// Allow mapping of arrow keys

    int lines; int cols;
    getmaxyx(window, lines, cols);
    int bookCount = (lines - 2) / 3;
    int motion = 0;
    int windowStart = 0;

    do
    {
        resetWindow(window);

        if (motion == KEY_DOWN && windowStart >= currView->size())
        {
            windowStart = currView->size() - 1;
        }
        else if (motion == KEY_DOWN)
        {
            windowStart++;
        }
        else if (motion == KEY_UP && windowStart <= 0)
        {
            windowStart = 0;
        }
        else if (motion == KEY_UP)
        {
            windowStart--;
        }

        for (int i = windowStart, screenLoc = 0; i < currView->size(); i++, screenLoc++)
        {
            printBook(window, currView->at(i), screenLoc);
        }

        update_panels();
        doupdate();

        motion = getch();
    }
    while (motion != 'q');

    keypad(stdscr, FALSE);
}
