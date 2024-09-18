#include "filehandler.hpp"
#include <fstream>
#include <stdio.h>

BookLibrary createLibrary(std::string fileName)
{
    std::ifstream fileInput (fileName);
    std::string currLine;
    BookLibrary fileLibrary;

    // Returns blank library if file does not open properly
    if (!fileInput.is_open())
    {
        perror("Error in createLibrary. Error opening file.");
        return fileLibrary;
    }

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

    // Repeats open process if file fails to open
    int i = 0;
    while (!fileOutput.is_open())
    {
        fileOutput.open(workingLibrary->name);
        if (i >= 3)
        {
            perror("Error in writeLibrary. Failed to open file for write.");
            return;
        }
        i++;
    }

    fileOutput << "title,authorLast,authorFirst,publishYear\n";
    for (auto book : workingLibrary->books){
        fileOutput << book.title << "," << book.authorLast << ","
            << book.authorFirst << "," << book.publishYear << "\n";
    }
    fileOutput.close();
    return;
}
