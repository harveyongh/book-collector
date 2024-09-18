#include "book.hpp"
#include "curses.hpp"
#include "library.hpp"
#include "filehandler.hpp"
#include <cstdio>
#include <iostream>
#include <string.h>

Book newBook();
void mainMenu(bool);
void mainLoop();

int main()
{
    mainLoop();

    return 0;
}

void mainMenu(bool flag)
{
    using std::cout;
    cout << "Book Collector Main Menu:\n"
        "m) Show main menu\n"
        "o) Open a library file\n";
    if (flag){
        cout << "a) Add a book to the library\n"
            "d) Delete a book from the library\n"
            "s) Sort the library by author\n"
            "f) Filter the library by title or author\n"
            "c) Save and close library file\n";
    }
    cout << "e) Exit the program\n";
}

Book newBook()
{
    using std::cout;
    using std::getline;
    std::string newBookArray[4];

    std::cin.ignore();// clear existing characters in buffer
    printf("Enter book title: ");
    getline(std::cin, newBookArray[0]);
    printf("Enter author last name, first:");
    std::string authorName;
    getline(std::cin, authorName);
    newBookArray[1] = authorName.substr(0, authorName.find(","));
    newBookArray[2] = authorName.substr((authorName.find(",") + 2), authorName.length());
    printf("Enter publishing year:");
    getline(std::cin, newBookArray[3]);

    return Book(newBookArray);
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
