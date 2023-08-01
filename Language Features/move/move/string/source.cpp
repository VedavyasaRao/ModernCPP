#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() 
{

    cout << R"(string name = "khrisha rao")" << endl;
    string name = "khrisha rao";
    cout << "name before move:" << name  << endl;
    cout << R"(string name2=move(name);)" << endl;
    string name2=move(name);
    cout << "name after move:" << name   << endl;
    cout << "name2 after move:" << name2   << endl;
    
}