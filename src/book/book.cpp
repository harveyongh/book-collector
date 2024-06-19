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

void Book::newBook()
{
    using std::cout;
    using std::getline;
    std::string newBookArray[4];

    std::cin.ignore();// clear existing characters in buffer
    printf("Enter book title: ");
    getline(std::cin, newBookArray[0]);
    printf("Enter author last name, first:");
    std::string authorName;
    getline(std::cin, authorName);
    newBookArray[1] = authorName.substr(0, authorName.find(","));
    newBookArray[2] = authorName.substr((authorName.find(",") + 2), authorName.length());
    printf("Enter publishing year:");
    getline(std::cin, newBookArray[3]);

    title = newBookArray[0]; authorLast = newBookArray[1];
    authorFirst = newBookArray[2]; publishYear = newBookArray[3];
}

void Book::printBook()
{
    using std::cout;
    cout << authorLast << ", " << authorFirst << std::endl;
    cout << publishYear << " " << title << std::endl;
}
