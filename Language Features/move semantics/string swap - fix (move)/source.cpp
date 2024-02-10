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
        cout << "copy constructor&&\t: " << s << endl;
    }

    mystring& operator=(mystring&& s) noexcept
    {
        cout << "operator=&&\t\t: " << s  << endl;
        dynamic_cast<string*>(this)->operator=(s);
        return *this;
    }
};

int main()
{
    //swap
    cout << "swap" << endl;
    mystring g{"Guarantee"}, w{"Warranty"};
    mystring t = move(g);
    g = move(w);
    w = move(t);
    cout << endl << endl;
    
    cout << "vector insert" << endl;
    vector<mystring> test;
    for (auto i=0; i<5; ++i)
    {
        string t = "instance"+to_string(i);
        test.emplace_back(mystring(t.c_str()));
    }
}