#include "book/book.hpp"
#include "book/library.hpp"
#include "data/filehandler.hpp"
#include <cstdio>
#include <iostream>
#include <string.h>

void mainMenu(bool);
int main()
{
    bool libraryOpenFlag = false;
    BookLibrary currLibrary;
    std::string fileName;
    mainMenu(libraryOpenFlag);
    char option;
    // while loop to continue prompting for input while active
    while (option != 'e'){
        Book newBook;
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
                newBook.newBook();
                currLibrary.addBook(newBook);
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
            case 'c':
                writeLibrary(&currLibrary);
                currLibrary.books.clear();
                currLibrary.name = "";
                libraryOpenFlag = false;
                break;
        }
        std::cout << "Enter menu option: ";
        std::cin >> option;
        std::cout << std::endl;
    }

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
