#include <iostream>
using namespace std;

int g=100;
int main()
{
    int i=10, j=20, k=30;

    //acccess i,j,k by as read/write reference
    cout << R"([&]  {std::cout << ++i << " " << ++j << " " << ++k << std::endl; })" << endl;
    [&]  {std::cout << ++i << " " << ++j << " " << ++k << std::endl; }();
    cout << endl;
    
    //acccess i and j as readonly value and k as read/write reference
    cout << R"([i,j, &k]  {std::cout << i << " " << j << " " << ++k << std::endl; })" << endl;
    [i,j, &k]  {std::cout << i << " " << j << " " << ++k << std::endl; }();
    cout << endl;
    
    //acccess i and j as readonly value and k as read/write reference
    //use mutable for modifying i and j
    cout << R"([i,j,&k] mutable {std::cout << ++i << " " << ++j << " " << ++k << std::endl; })" << endl;
    [i,j,&k] mutable {std::cout << ++i << " " << ++j << " " << ++k << std::endl; }();
    cout << endl;

    //acccess i,j,k by readonly value
    cout << R"([=]  {std::cout << i << " " << j << " " << k << std::endl; })" << endl;
    [=]  {std::cout << i << " " << j << " " << k << std::endl; }();
    cout << endl;
}