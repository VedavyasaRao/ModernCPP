#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
 
void handle_ne(const std::nested_exception& ne) // passing by value is ok
{
    try
    {
       if (ne.nested_ptr())
           ne.rethrow_nested();
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught exception: '" << e.what() << "'\n";
    }
}

 std::nested_exception ne;
int main()
{

    try
    {
        std::string().at(1); // this generates a std::out_of_range
    }
    catch(...)
    {
        ne = std::nested_exception(); // capture
    }
 
    handle_ne(ne);
 
}