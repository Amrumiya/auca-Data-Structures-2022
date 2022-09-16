#include <iostream>


int main()
{
    #ifdef AUCA_DEBUG
    std::cout << "author Murid Amrumiya\n";
    #endif
std::cout << "Hello, C++ " << __cplusplus << "!\n";
}