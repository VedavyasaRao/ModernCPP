#include <iostream>
using namespace std;

int main()
{
    int i=10, j=20, k=30;

    auto  r = [] {return 1;}();
    cout << R"([] {return 1;})" << endl;
    cout << typeid(r).name() << endl;
    cout << endl;

    auto  r2 = [] -> double {return 1;}();
    cout << R"([] -> double {return 1;})" <<  endl;
    cout << typeid(r2).name() << endl;

}