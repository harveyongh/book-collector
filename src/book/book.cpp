#include "book.hpp"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

Book::Book(std::string csvLine)
{
    std::string splitArray[4];
    std::string currData;

    std::stringstream ss(csvLine);
    int i = 0;
    while (std::getline(ss, currData, ',')){
        splitArray[i] = currData;
        i++;
    }

    title = splitArray[0]; authorLast = splitArray[1];
    authorFirst = splitArray[2]; publishYear = splitArray[3];
}

Book::Book(std::string bookArray[4])
{
    title = bookArray[0]; authorLast = bookArray[1];
    authorFirst = bookArray[2]; publishYear = bookArray[3];
}



void Book::printBook()
{
    using std::cout;
    cout << authorLast << ", " << authorFirst << std::endl;
    cout << publishYear << " " << title << std::endl;
}
