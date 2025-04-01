#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

std::exception_ptr eptr;

void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
    try
    {
        if (eptr)
            std::rethrow_exception(eptr);
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void  divide(int m, int n)
{
    if (n == 0)
    {
        std::ostringstream s;
        s <<  m << '/' << n; 
        eptr = std::make_exception_ptr(std::domain_error("bad input:"+s.str()));
    }
    else
        std::cout << "result:" << (m/n) << std::endl;
}

int main()
{
 
    try
    {
        std::cout << "std::string().at(1)" << std::endl;
        std::string().at(1); // this generates a std::out_of_range
    }
    catch(...)
    {
        eptr = std::current_exception(); // capture
    }
 
    handle_eptr(eptr);
    std::cout << std::endl;
    
    eptr = nullptr;
    std::cout << "divide(1,0)" << std::endl;
    divide(1,0);
    handle_eptr(eptr);
    
 
} // destructor for std::out_of_range called here, when the eptr is destructed
