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
    mystring()
    {
        cout << "default constructor" << endl;
    }

    mystring(const char* s):std::string(s)
    {
        cout << "memberwise constructor:" << s << endl;
    }


    mystring(const mystring& s) :std::string(s)
    {
        cout << "copy constructor:" << s << endl;
    }

    mystring& operator=(const mystring& s)
    {
        cout << "operator=:" << s  << endl;
        dynamic_cast<string*>(this)->operator=(s);
        return *this;
    }

};

void exchange(mystring &p, mystring &p2)
{
    mystring t = p;
    p = p2;
    p2 = t;
}

int main()
{
    mystring p{"bill gates"}, p2{"steve jobs"};
    cout << p << "  " << p2 << endl;
    exchange(p,p2);
    cout << p << "  " << p2 << endl;
}