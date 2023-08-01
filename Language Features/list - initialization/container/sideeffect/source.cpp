#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> vint{20};
    cout << "vector<int> vint{20}" << endl;
    cout << "vint.size()=" << vint.size() << endl << endl;

    vector<int> vint2(20);
    cout << "vector<int> vint2(20)" << endl;
    cout << "vint2.size()=" << vint2.size();
    
}