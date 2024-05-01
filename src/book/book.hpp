#ifndef BOOK_H_
#define BOOK_H_
#include <string>

struct Book {
    std::string title;
    std::string authorLast;
    std::string authorFirst;
    std::string publishYear;

    Book parseBook(std::string csvLine);
    Book newBook();

    Book arrayToBook(std::string valueArray[4]);
};


#endif // BOOK_H_
