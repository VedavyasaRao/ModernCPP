#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

struct X
{
    virtual void print(int) final {}
};

struct Y: public X
{
    void print(int) {}
};

struct A final
{
    virtual void print(int) final {}
};

struct B: public A
{
    
};

int main () 
{

}
