#ifndef BOOK_H_
#define BOOK_H_
#include <string>

struct Book {
    std::string title;
    std::string authorLast;
    std::string authorFirst;
    std::string publishYear;

    Book(){};
    Book(std::string bookArray[4]);
    Book(std::string csvLine);

    void setFromArray(std::string bookArray[4]);
    void printBook();
};


#endif // BOOK_H_
