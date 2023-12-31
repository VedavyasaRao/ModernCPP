#include <iostream>
#include <cassert>

using namespace std;
template<class...A, class...B> 
void func(A...arg,int sz, int sz2, B...arg2)  
{
    cout << "sizeof...(arg) = " << sizeof...(arg) << "  sz = " << sz << endl;
    cout << "sizeof...(arg2) = " << sizeof...(arg2) << "  sz2 = " << sz2 << endl;
}

int main(void)
{
    //A:(int, int, int), B:(int, int, int, int, int) 
    cout << R"(A:(int, int, int), B:(int, int, int, int, int) )" << endl;
    cout << R"(func<int,int,int>(1,2,3,3,5,1,2,3,4,5))" << endl;
    func<int,int,int>(1,2,3,3,5,1,2,3,4,5);

    cout << endl;
    //A: empty, B:(int, int, int, int, int)
    cout << R"(A: empty, B:(int, int, int, int, int) )" << endl;
    cout << R"(func(0,5,1,2,3,4,5);)" << endl;
    func(0,5,1,2,3,4,5);

    
   return 0;
}