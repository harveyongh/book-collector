#include "book.hpp"
#include "curses.hpp"
#include "library.hpp"
#include "filehandler.hpp"

#include <cstdio> // TO REMOVE
#include <curses.h>
#include <iostream> // TO REMOVE
#include <panel.h>
#include <string.h>

Book newBook(WINDOW *window);
void mainLoop(WINDOW *windowArray[2]);

int main()
{
    WINDOW *windowArray[2];
    PANEL *panelArray[2];
    initCurses(panelArray, windowArray);

    mainLoop(windowArray);

    endCurses(panelArray, windowArray);
    return 0;
}

Book newBook(WINDOW *window)
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

    return Book(bookArray);
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
                    // TODO
                    break;
                case 'd':
                    // TODO
                    break;
                case 's':
                    // TODO
                    break;
                case 'f':
                    // TODO
                    break;
            }
        }
    }
}
