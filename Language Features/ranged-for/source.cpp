#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() 
{
    vector<int>  intvec {1,2,3,4,5};
    for (int i:intvec)
    {
        cout << i << " ";
    }
    cout << endl;
    
    list<string>  strvec {"mon","tue","wed","thu","fri","sat","sun"};
    for (const string& s  :strvec)
    {
        cout << s << " ";
    }
    cout << endl;


    map<string,int> strintmap {{"a",97},{"b",98},{"c",99}};
    for (const auto& p  :strintmap)
    {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
    
}