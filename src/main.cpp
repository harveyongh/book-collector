#include "book/book.hpp"
#include "book/library.hpp"
#include "data/filehandler.hpp"
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
                break;
            case 'a':
                newBook.newBook();
                currLibrary.addBook(newBook);
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
                break;
        }
        std::cout << "Enter menu option: ";
        std::cin >> option;
        std::cout << std::endl;
    }
    // m reruns main menu with flag
    // o runs the filehandler and generates library object
    // a runs library addbook function
    // s runs library sort function, stores and prints out the new vector
    // f runs library filter func, stores and prints vector
    // c runs filehandler writelibrary and vector.clear()
    // e returns 0

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
            "s) Sort the library by author\n"
            "f) Filter the library by title or author\n"
            "c) Save and close library file\n";
    }
    cout << "e) Exit the program\n";
}
