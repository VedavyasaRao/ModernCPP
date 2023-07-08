#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct  P
{
    int i;
    double j;
    string k;
    void print()
    {
        cout << "i="  << i << " j=" << j << " k=" << k << endl << endl;
    }

};

int main()
{
    P p{1, 2., "3"};
    p.print();

    P p2 = {3, 4.};
    p2.print();

}