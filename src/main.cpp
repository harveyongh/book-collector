#include "book.hpp"
#include "curses.hpp"
#include "library.hpp"
#include "filehandler.hpp"

#include <cstdio> // TO REMOVE
#include <iostream> // TO REMOVE
#include <string.h>

Book newBook(WINDOW *window);
void mainMenu(bool);
void mainLoop();

int main()
{
    mainLoop();

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

void mainLoop()
{
    bool libraryOpenFlag = false;
    BookLibrary currLibrary;
    std::string fileName;
    char option = ' ';

    mainMenu(libraryOpenFlag);

    while (option != 'e'){
        Book blankBook;
        Book deleteBook;
        BookLibrary queryLibrary;
        std::string filterOpt = "name"; std::string filter;

        switch (option) {
            case 'm':
                mainMenu(libraryOpenFlag);
                break;
            case 'o':
                std::cout << "Please enter filename: ";
                std::cin >> fileName;
                currLibrary = createLibrary(fileName);
                libraryOpenFlag = true;
                break;
            case 'a':
                blankBook = newBook();
                currLibrary.addBook(blankBook);
                break;
            case 'd':
                std::cin.ignore();// Ignore prev input for getline()
                std::cout << "Please enter book title: ";
                getline(std::cin, deleteBook.title);
                std::cout << "Please enter author last name: ";
                getline(std::cin, deleteBook.authorLast);
                currLibrary.deleteBook(deleteBook);
                break;
            case 's':
                queryLibrary.books = currLibrary.sort("");
                queryLibrary.printLibrary();
                break;
            case 'f':
                std::cout << "Please enter filter option, name/title: ";
                std::cin >> filterOpt;
                std::cout << "Please enter filter: ";
                std::cin >> filter;
                queryLibrary.books = currLibrary.filter(filterOpt, filter);
                queryLibrary.printLibrary();
                break;
            case 'w':
                writeLibrary(&currLibrary);
                break;
            case 'c':
                currLibrary.books.clear();
                currLibrary.name = "";
                libraryOpenFlag = false;
                break;
        }
        std::cout << "Enter menu option: ";
        std::cin >> option;
        std::cout << std::endl;
    }
}
