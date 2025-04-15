#include <iostream>     
#include <functional>   
#include <vector>   

using namespace std;

int main () 
{
    int a(10),b(20),c(30);

    reference_wrapper<int> refs[] = {a,b,c};
    vector<reference_wrapper<int>> vec {a,b,c};
    
    for (int& x : refs)
        ++x;

    for (int& x : vec)
        cout << x << ' ';
    cout << endl;
    
    for (int& x : vec)
        ++x;

    for (int& x : refs)
        cout << x << ' ';
    cout << endl;

  return 0;
}
