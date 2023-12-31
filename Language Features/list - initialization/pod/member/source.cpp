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
    cout << R"(P p{1, 2., "3"})" << endl;
    p.print();

    cout << R"(P p2 = {3, 4.})" << endl;
    P p2 = {3, 4.};
    p2.print();
}