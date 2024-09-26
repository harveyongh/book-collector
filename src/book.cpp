#include "book.hpp"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

Book::Book(std::string csvLine)
{
    std::string currData;
    std::stringstream ss(csvLine);
    std::string bookArray[4];

    for (int i = 0; i < 4; i++)
    {
        std::getline(ss, currData, ',');
        bookArray[i] = currData;
    }
    setFromArray(bookArray);
}

Book::Book(std::string bookArray[4])
{
    setFromArray(bookArray);
}

void Book::printBook()
{
    using std::cout;
    cout << authorLast << ", " << authorFirst << std::endl;
    cout << publishYear << " " << title << std::endl;
}

void Book::setFromArray(std::string bookArray[4])
{
    title = bookArray[0];
    authorLast = bookArray[1];
    authorFirst = bookArray[2];
    publishYear = bookArray[3];
}

std::string Book::longAuthor()
{
    return authorLast + ", " + authorFirst;
}
