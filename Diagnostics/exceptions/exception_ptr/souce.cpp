#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;


void handle_eptr(exception_ptr eptr) 
{
    try
    {
        if (eptr)
            rethrow_exception(eptr);
    }
    catch(const exception& e)
    {
        cerr << "Caught exception: " << e.what() << endl;
    }
}

int main()
{
 
   exception_ptr eptr;
    try
    {
        // this generates a out_of_range
        string().at(1); 
    }
    catch(...)
    {
        // capture
        eptr = current_exception(); 
    }    
    
    /*prints
    Caught exception: basic_string::at: __n (which is 1) >= this->size() (which is 0)
    */
    handle_eptr(eptr);   
}  // destructor for out_of_range called when the eptr is destructed