#include "book.hpp"

Book parseBook(std::string csvLine)
{
    Book parsedBook;
    std::string workingString = csvLine;
    std::string splitArray[4];

    for (int i = 0; i < 4; i++){
        int currentSeparation = workingString.find(",");
        splitArray[i] = workingString.substr(0, currentSeparation);
        if (i < 3){
            workingString.erase(0, currentSeparation);
        }
    }
    parsedBook.arrayToBook(splitArray);
    return parsedBook;
}
