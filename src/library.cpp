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

std::vector<Book> BookLibrary::sort()
{
    // iterate to create array[length] of all book values to sort
    std::vector<std::string> sortVector;
    for (auto item: books){
        sortVector.push_back(item.authorLast);// for the moment, will only sort by name
    }
    std::sort(sortVector.begin(), sortVector.end());
    // iterate through sorted array and push the first occurrence to output vector
    std::vector<Book> sortedLibrary;
    std::string prevValue = "";
    for (auto vectorItem : sortVector){
        if (vectorItem == prevValue){
            continue;
        }
        for (auto libraryItem : books){
            if (libraryItem.authorLast == vectorItem){
                sortedLibrary.push_back(libraryItem);
            }
        }
        prevValue = vectorItem;
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
