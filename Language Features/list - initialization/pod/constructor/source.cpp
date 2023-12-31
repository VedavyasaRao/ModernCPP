#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct  P
{
    int i;
    double j;
    string k;

    P(int i, double j, string k) :i(i),j(j),k(k) 
    {
        cout << "Constructor:\t P(int i, double j, string k)"  << endl;
    
    }

    P(int i, string k) :i(i),j(1.1),k(k) 
    {
        cout << "Constructor:\t P(int i, string k)"  << endl;
    
    }

    void print()
    {
        cout << "i="  << i << " j=" << j << " k=" << k << endl << endl;
    }
};

int main()
{
     cout << R"(P p{1, 2., "3"})" << endl;
    P p{1, 2., "3"};
    p.print();

     cout << R"(P p2 = {4, "5"})" << endl;
    P p2 = {4, "5"};
    p2.print();
}
