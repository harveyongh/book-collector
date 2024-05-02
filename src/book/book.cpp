#include "book.hpp"
#include <iostream>
#include <sstream>
#include <string>

void Book::parseBook(std::string csvLine)
{
    Book parsedBook;
    std::string workingString = csvLine;
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
    //parsedBook.arrayToBook(splitArray);
}

void Book::newBook()
{
    using std::cout;
    using std::cin;
    std::string newBookArray[4];

    cout << "Enter book title: ";
    cin >> newBookArray[0];
    cout << "Enter author last, first name: ";
    std::string author;
    cin >> author;
    newBookArray[1] = author.substr(0, author.find(","));
    newBookArray[2] = author.substr((author.find(",") + 1), author.length());
    cout << "Enter publishing year: ";
    cin >> newBookArray[3];

    title = newBookArray[0]; authorLast = newBookArray[1];
    authorFirst = newBookArray[2]; publishYear = newBookArray[3];
}

void Book::printBook()
{
    using std::cout;
    cout << authorLast << ", " << authorFirst << std::endl;
    cout << publishYear << " " << title << std::endl;
}
