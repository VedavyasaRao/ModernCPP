#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
    string name{"stressed desserts"};
    cout << "forward iterator" << endl;
    for(auto itr=name.begin(); itr != name.end(); ++itr) cout << *itr;
    cout << endl;
    cout << endl;
    cout << "reverse iterator" << endl;
    for(auto ritr=name.rbegin(); ritr != name.rend(); ++ritr) cout << *ritr;
    cout << endl;

}