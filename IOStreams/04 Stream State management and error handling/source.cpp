#include <iostream>
#include <sstream>

using namespace std;
istringstream ssin("10 20 30");

void printresult()
{
    cout << "IO Flags" << endl;
    if (ssin.good())
    {
        cout << "good " <<endl;
    }  
    if (ssin.bad())
    {
        cout << "bad " <<endl;
    }
    if (ssin.eof())
    {
        cout << "eof " <<endl;
    }
    if (ssin.fail())
    {
        cout << "fail " <<endl;
    }
}

int main()
{
    int a,b,c;

    cout << "Parsing three integers a,b,c from " << endl
        << ssin.str() <<  endl;

    ssin>> a;
    cout  << endl << "a:" << a << endl;
    printresult();

    ssin >> b ;
    cout  << endl << "b:" << b << endl;
    printresult();
        
    ssin >> c;
    cout  << endl << "c:" << c << endl;
    printresult();
}