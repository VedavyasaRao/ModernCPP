#include <iostream>
using namespace std;


template<typename... Args>
void printlist(Args... args) 
{
    for (const auto arg:{args...})
        cout << arg << " ";
}

int main() 
{
    cout << R"(printlist(1, 2, 3, 4))" << endl;
    cout << "output:" << endl;
    printlist(1, 2, 3, 4);
    //printlst(1, 2, 3, "4"); compiler error
    return 0;    
}