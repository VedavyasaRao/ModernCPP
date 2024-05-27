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
    
    cout << R"x(insert(vs.begin(),s))x" << endl;
    vs.insert(vs.begin(),s); 
    cout << endl << endl;
    
    cout << R"x(insert(vs.begin(),"insert(rvalue)"))x" << endl;
    vs.insert(vs.begin(),"insert(rvalue)");
    cout << endl << endl;
    
    cout << R"x(emplace(vs.begin(), "emplace"))x" << endl;
    vs.emplace(vs.begin(), "emplace");
    cout << endl << endl;
}