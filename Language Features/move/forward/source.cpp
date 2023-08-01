#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void print(string& message)
{
    cout << "print(string& message)" << endl;
}

void print(const string& message)
{
    cout << "print(const string& message)" << endl;
}

void print(string&& message)
{
    cout << "print(string&& message)" << endl;
}

template<class T>
void factoryprint(T&& message)
{
    print(forward<T>(message));
}

int main()
{
    string message="hello, world!";
    const string message2="hello, world!";
    
    print(message);
    print(message2);
    print(move(message));
    cout << endl;
    
    factoryprint(message);
    factoryprint(message2);
    factoryprint(move(message));
    
}