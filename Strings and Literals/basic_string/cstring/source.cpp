#include <string>
#include <typeinfo>
#include <iostream>

using namespace std;

template <typename T>
void printtype(T) 
{
    cout << typeid(T).name() << endl;
}

int main()
{
    const char *str = "hello,";
    const char str2[9] = "world!";
    printtype(str);
    printtype( str2);
}