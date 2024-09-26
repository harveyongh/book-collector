#include "../library.hpp"
#include "../book.hpp"

#include <iostream>

int main()
{
    std::cout << removeThe("The test string") << std::endl;
    std::cout << removeThe("Second test string") << std::endl;

    return 0;
}
