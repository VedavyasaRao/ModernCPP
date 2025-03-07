#include <iostream>

using namespace std;

struct X
{
    X(int) {}
    X(initializer_list<int>) {}
};

struct Y  :public X 
{
};

struct Z  :public X 
{
    using X::X;
};

int main()
{
    Y y{1}; //OK calls X(int)
    Y yy{1,2,3}; //error

   Z z{1}; //OK calls X(int)
   Z zz{1,2,3}; //OK calls X(initializer_list<int>)
}