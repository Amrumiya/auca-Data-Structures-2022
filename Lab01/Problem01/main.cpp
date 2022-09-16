#include <iostream>


int main()
{
    #ifdef AUCA_DEBUG
    std::cout << "author Murid Amrumiyan";
    #endif
std::cout << "Hello, C++ " << __cplusplus << "!\n";
}