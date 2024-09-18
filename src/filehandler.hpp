#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
#include <string>
#include "library.hpp"

BookLibrary createLibrary(std::string fileName);
void writeLibrary(BookLibrary* workingLibrary);

#endif // FILEHANDLER_H_
