#include "library.hpp"
#include "book.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

void BookLibrary::addBook(Book newBook)
{
    books.push_back(newBook);
}

void BookLibrary::deleteBook(Book delBook)
{
    //auto delIter = std::find(books.begin(), books.end(), delBook);
    int delLoc = 0;
    for (auto item : books){
        if (item.title == delBook.title && item.authorLast == delBook.authorLast){
            break;
        }
        delLoc++;
    }
    books.erase(books.begin() + delLoc);
}

std::string removeThe(std::string title)
{
    if (title.find("the ") == 0 || title.find("The ") == 0)
    {
        title.erase(0, 4);
    }

    return title;
}

std::vector<Book> BookLibrary::sort()
{
    std::vector<std::string> sortedTitles;
    std::vector<Book> sortedLibrary;

    for (Book book : books)
    {
        std::string fullTitle = book.longAuthor() + ", " + removeThe(book.title);
        sortedTitles.push_back(fullTitle);
    }
    std::sort(sortedTitles.begin(), sortedTitles.end());

    for (std::string fullTitle : sortedTitles)
    {
        int delimPos = fullTitle.find(", ");
        std::string authorLast = fullTitle.substr(0, delimPos);
        fullTitle.erase(0, delimPos+2);
        delimPos = fullTitle.find(", ");
        std::string authorFirst = fullTitle.substr(0, delimPos);
        fullTitle.erase(0, delimPos+2);
        std::string title = fullTitle;

        for (Book book : books)
        {
            if (book.authorLast.compare(authorLast) == 0
                && book.authorFirst.compare(authorFirst) == 0
                && book.title.find(title) != std::string::npos)
            {
                sortedLibrary.push_back(book);
            }
        }
    }

    return sortedLibrary;
}

std::vector<Book> BookLibrary::filter(std::string option, std::string filterStr)
{
    if (option == "name"){
        std::vector<Book> authorVector;
        for (auto item : books){
            if (item.authorLast == filterStr){
                authorVector.push_back(item);
            }
        }
        return authorVector;
    } else if (option == "title"){
        std::vector<Book> titleVector;
        for (auto item : books){
            if (item.title.find(filterStr) != std::string::npos){
                titleVector.push_back(item);
            }
        }
        return titleVector;
    }
    return books;
}

void BookLibrary::printLibrary()
{
    for (auto book : books){
        book.printBook();
        std::cout << std::endl;
    }
}
