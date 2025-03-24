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
    cout << "f((int)NULL);" << endl;
    //f(NULL) compilation error
    f((int)NULL);
    
    cout << "f((void*)NULL);" << endl;
    //f(NULL) compilation error
    f((void*)NULL);
    
    cout << "f(nullptr);" << endl;
    f(nullptr);
}
