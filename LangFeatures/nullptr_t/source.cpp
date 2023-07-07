#include <iostream>
#include <iomanip>

using namespace std;
void f(int a)
{
    cout << "f(int a)" << endl;
    cout << "f(" << a << ")" << endl;
    cout << endl;
}

void f(void* a)
{
    cout << "f(void* a)" << endl;
    cout << "f(" << a << ")" << endl;
    cout << endl;
}

int main()
{
    f(0);
    f((void*)NULL);
    f(nullptr);
}