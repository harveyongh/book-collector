#include "library.hpp"
#include <algorithm>
#include <vector>

void BookLibrary::addBook(Book newBook)
{
    books.push_back(newBook);
}

void BookLibrary::deleteBook(Book delBook)
{
    auto delIter = std::find(books.begin(), books.end(), delBook);
    books.erase(delIter);
}

std::vector<Book> BookLibrary::sort(int option)
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
