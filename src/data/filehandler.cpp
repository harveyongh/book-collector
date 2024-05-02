#include "filehandler.hpp"
#include <fstream>

BookLibrary createLibrary(std::string fileName)
{
    std::ifstream fileInput (fileName);
    std::string currLine;
    BookLibrary fileLibrary;
    fileLibrary.name = fileName;

    getline(fileInput, currLine);// Discard column labels
    while (getline(fileInput, currLine)){
        Book parsedBook;
        parsedBook.parseBook(currLine);
        fileLibrary.addBook(parsedBook);
    }
    return fileLibrary;
}

void writeLibrary(BookLibrary *workingLibrary)
{
    //
}
