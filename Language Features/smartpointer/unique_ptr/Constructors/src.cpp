#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <stdexcept>

using namespace std;

 int main ()
{
    cout << "unique_ptr<T>()" << endl;
    unique_ptr<int>();
    
    cout << "unique_ptr<T>(nullptr_t)" << endl;
    unique_ptr<int>(nullptr);

    cout << "unique_ptr<T>(T *p)" << endl;
    unique_ptr<int>(new int);

    cout << "unique_ptr<T,D>(T *p, const D& del)" << endl;
    unique_ptr<int> (new int, *(new default_delete<int>()));

    cout << "unique_ptr<T,D>(T *p,  D&& del)" << endl;
    unique_ptr<int> U5(new int, default_delete<int>());
    
    cout << "unique_ptr<T,D>(unique_ptr&& x)" << endl;
    unique_ptr<int> U6(move(U5));

    cout << "unique_ptr<T,D>(unique_ptr<T,D>&& x)" << endl;
    unique_ptr<int>(move(unique_ptr<int>(move(unique_ptr<int>(new int, default_delete<int>())))));

    cout << "unique_ptr<T>(auto_ptr<T>&& x)" << endl;
    unique_ptr<int>(auto_ptr<int>(new int));

    cout << "unique_ptr<T,D>(T[] p, const D& del )" << endl;
    unique_ptr<int[]> (new int[10], default_delete<int[]>());
    
}