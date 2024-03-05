#include <iostream>     // cout
#include <functional>   // bind

using namespace std;

struct MyPair 
{
  double a,b;
  double multiply() {return a*b;}
} ten_two {10,2};

int main () 
{

    cout << R"(
        struct MyPair 
        {
            double a,b;
            double multiply() {return a*b;}
        } ten_two {10,2};
    )" << endl;

    cout << "bind (divides<int>{},10,2)()\t\t\t\t\t\t = "
        << bind (divides<int>{},10,2)() << endl; 
    
    cout << "bind (divides<int>{},placeholders::_1,2)(10)\t\t\t\t = "
        << bind (divides<int>{},placeholders::_1,2)(10) << endl; 
    
    cout << "bind (divides<int>{},placeholders::_2,placeholders::_1)(10,2)\t\t = "
        << bind (divides<int>{},placeholders::_2,placeholders::_1)(10,2) << endl;
    
    cout << "bind<int> (divides<int>{},placeholders::_1,placeholders::_2)(10,3)\t = "
        << bind<int> (divides<int>{},placeholders::_1,placeholders::_2)(10,3) << endl;

    cout << "bind (&MyPair::multiply,placeholders::_1)(ten_two)\t\t\t = "
        <<  bind (&MyPair::multiply,placeholders::_1)(ten_two) << endl;

    cout << "bind (&MyPair::a,ten_two)()\t\t\t\t\t\t = "
        <<  bind (&MyPair::a,ten_two)() << endl;
  
  return 0;
}