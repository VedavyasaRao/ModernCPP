#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

int main() 
{
    //compile time
    static_assert((6 == factorial(3)));
    //runtime
    cout << "3! =" << factorial(3) << endl;
}