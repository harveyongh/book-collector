#include "library.hpp"
#include "book.hpp"
#include <algorithm>
#include <vector>

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

std::vector<Book> BookLibrary::sort(std::string option)
{
    int length = books.size();
    // iterate to create array[length] of all book values to sort
    std::string sortArray[length];
    int i = 0;
    for (auto item: books){
        sortArray[i] = item.authorLast;// for the moment, will only sort by name
        i++;
    }
    std::sort(sortArray, sortArray + length);
    // iterate through sorted array and push the first occurrence to output vector
    std::vector<Book> sortedLibrary;
    for (auto arrayItem : sortArray){
        for (auto libraryItem : books){
            if (libraryItem.authorLast == arrayItem){
                sortedLibrary.push_back(libraryItem);
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
