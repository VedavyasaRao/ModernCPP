#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
void foo() noexcept(sizeof(T)<8) 
{
    throw 10;
}
 
void bar() noexcept(false) 
{
    throw 20;
}

int main() 
{
    cout << "calling bar()" << endl;
    try
    {
        bar(); // fine
    }
    catch(...) { }

    cout << "foo<int()" << endl;
    try
    {
        foo<int>(); // noexcept(sizeof(T)<8) => noexcept(true), 
    }
    catch(...) { }
}