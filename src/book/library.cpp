#include "library.hpp"
#include <algorithm>

void BookLibrary::addBook(Book newBook)
{
    books.push_back(newBook);
}

void BookLibrary::deleteBook(Book delBook)
{
    auto delIter = std::find(books.begin(), books.end(), delBook);
    books.erase(delIter);
}
