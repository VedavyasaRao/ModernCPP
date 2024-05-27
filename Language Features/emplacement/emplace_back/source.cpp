#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

struct mystring:std::string
{
    //defined in basic_string class; contains underlying chars
    //char *buffer; 

    mystring() noexcept
    {
        cout << "default constructor" << endl;
    }

    ~mystring() noexcept
    {
        cout << "destructor:" << *this << endl;
    }

    mystring(const char* s) noexcept
    :std::string(s) 
    {
        cout << "memberwise constructor\t: " << s << endl;
    }


    mystring(const mystring& s) noexcept :std::string(s) 
    {
        cout << "copy constructor\t: " << s << endl;
    }

    mystring& operator=(const mystring& s) noexcept
    {
        cout << "operator=\t\t: " << s  << endl;
        dynamic_cast<string*>(this)->operator=(s);
        return *this;
    }


    mystring(mystring&& s)  noexcept :std::string(s) 
    {
        cout << "copy constructor&&:" << s << endl;
    }

    mystring& operator=(mystring&& s) noexcept
    {
        cout << "operator=&&:" << s  << endl;
        dynamic_cast<string*>(this)->operator=(s);
        return *this;
    }

};

int main()
{
    vector<mystring> vs;
    mystring s("push_back(lvalue)");
    vs.reserve(10);
    vs.push_back("dummy");
    cout << endl << endl;
    
    cout << "push_back(lvalue)" << endl;
    vs.push_back(s); 
    cout << endl << endl;
    
    cout << "push_back(rvalue)" << endl;
    vs.push_back("push_back(rvalue)");
    cout << endl << endl;
    
    cout << "emplace_back()" << endl;
    vs.emplace_back("emplace_back()");
    cout << endl << endl;
}