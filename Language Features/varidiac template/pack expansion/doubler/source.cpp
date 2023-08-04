#include <iostream>
using namespace std;

// Us... pargs expand to int E1, int E2, int E3
template<class... Us>
void print(Us... args) 
{
    for(auto v:{args...})
        cout << v << " ";
}
 
// Ts... args expand to int E1, int E2, int E3
template<class... Ts>
void doubler(Ts... args)
{
    // (args*2)...” is a pack expansion
    // “(args*2)” is its pattern
    // (args*2)... expands to E1*2, E2*2, E3*2
    print((args*2)...); 
}

int main()
{
    cout << R"(doubler(1, 2, 3))" << endl;
    cout << "output:" << endl;
    doubler(1, 2, 3);
}