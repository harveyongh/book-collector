#ifndef BOOK_H_
#define BOOK_H_
#include <string>

struct Book {
    std::string title;
    std::string authorLast;
    std::string authorFirst;
    std::string publishYear;

    void parseBook(std::string csvLine);
    void printBook();
    void newBook();

    void arrayToBook(std::string valueArray[4]){
        title = valueArray[0];
        authorLast = valueArray[1];
        authorFirst = valueArray[2];
        publishYear = valueArray[3];
    }
};


#endif // BOOK_H_
