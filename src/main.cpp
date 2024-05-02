#include "book/book.hpp"
#include "book/library.hpp"
#include "data/filehandler.hpp"
#include <iostream>

void mainMenu(bool);
int main()
{
    bool libraryOpenFlag = false;
    mainMenu(libraryOpenFlag);
    // while loop to continue prompting for input while active
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
