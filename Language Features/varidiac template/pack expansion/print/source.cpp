#include <iostream>
using namespace std;

template<typename T>
void print(T t)
{
    cout << t << endl;
}

template<typename T, typename... Ts>
void print(T t, Ts... ts)
{
    print(t);
    // “ts” is its pattern
    // “ts...” is  pack expansion
    print(ts...);
    //1st expansion:recursively calls self print(t=0.2,ts="3,4")
    //2nd expansion:calls print(t="3,4")
    
}

int main()
{
    cout << R"(print(1, 0.2, "3 4"))" << endl;
    cout << "output:" << endl;
    //calls print(t=1, ts=0.2, "3,4")
    print(1, 0.2, "3 4");
}