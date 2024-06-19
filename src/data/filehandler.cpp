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
        Book parsedBook(currLine);
        fileLibrary.addBook(parsedBook);
    }
    fileInput.close();
    return fileLibrary;
}

void writeLibrary(BookLibrary *workingLibrary)
{
    std::ofstream fileOutput (workingLibrary->name);
    fileOutput << "title,authorLast,authorFirst,publishYear\n";
    for (auto book : workingLibrary->books){
        fileOutput << book.title << "," << book.authorLast << ","
            << book.authorFirst << "," << book.publishYear << "\n";
    }
    fileOutput.close();
}
