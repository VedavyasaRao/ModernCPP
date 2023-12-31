#include <iostream>
#include <string>
#include <cassert>
#include <memory>

using namespace std;

template<typename T>
struct smartptr
{
    smartptr(T *ptr):m_ptr(ptr) {};
    ~smartptr() {delete m_ptr;}
    T operator*() {return *m_ptr;}
    T* operator->() {return m_ptr;}

    T* m_ptr;
};


struct X
{
    X(){a=100; cout << "X() called" << endl;}
    ~X(){cout << "~X() called" << endl;}
    int a;
    void print() {cout << "hello, world!" << endl;}
};

int main()
{
    cout << R"(smartptr<X> a(new X))" << endl;
    smartptr<X> x(new X);
    cout << "(*x).a = " << (*x).a << endl;
    cout << "x->print()" << endl;
    x->print();

    return 0;
}