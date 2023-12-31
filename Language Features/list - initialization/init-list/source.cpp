#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct  P
{
    int i;
    int j;
    int k;

    P(initializer_list<int> lst)
    {
        cout << "P(initializer_list<int>)" << endl;
        i=j=k=0;
        auto itr = lst.begin();
        if (itr != lst.end())
        {
            i=*itr++;
        }

        if (itr != lst.end())
        {
            j=*itr++;
        }
        
        if (itr != lst.end())
        {
            k=*itr++;
        }

    }


    void print()
    {
        cout << "i="  << i << " j=" << j << " k=" << k << endl << endl;
    }

};

int main()
{
    cout << "P p{1,2,3}" << endl;
    P p{1,2,3};
    p.print();

    cout << "P p2={4,5}" << endl;
    P p2={4,5};
    p2.print();
    
}