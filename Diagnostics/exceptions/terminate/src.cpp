#include <iostream>
#include <cstdlib>
#include <exception>
 
int main()
{
    std::set_terminate([]()
    {
        std::cout << "inside terminate handler\n" << std::flush;
    });

    throw 1;
}