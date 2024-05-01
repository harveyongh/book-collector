#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "book.hpp"
#include <vector>

struct BookLibrary{
    std::string name;// Holds name of file to write to later
    std::vector<Book> books;

    void setName(std::string newName);
    void addBook(Book newBook);
    void deleteBook(Book);
    std::vector<Book> sort(int option);
    std::vector<Book> filter(int option, std::string filterStr);
};

#endif // LIBRARY_H_
