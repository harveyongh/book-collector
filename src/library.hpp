#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "book.hpp"
#include <vector>

struct BookLibrary{
    std::string name;// Holds name of file to write to later
    std::vector<Book> books;

    void addBook(Book newBook);
    void deleteBook(Book);
    void printLibrary();
    std::vector<Book> sort();
    std::vector<Book> filter(std::string option, std::string filterStr);
};

std::string removeThe(std::string title);

#endif // LIBRARY_H_
