#include <iomanip>
#include <map>
using namespace std;

struct X
{
    virtual void print(int){}
};

struct Y: public X
{
    void print(double) override {}
};
//compiler error

int main () 
{

}