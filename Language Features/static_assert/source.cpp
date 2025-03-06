
#include <iostream>
using namespace std;
template <typename T, typename T2>
void  swap(T src, T2 dst)
{
    static_assert((sizeof(T2) > sizeof(T)), "overflow");
    dst = src;
}
int main () 
{
    char ch = 'a';
    double d;
    swap(ch, d);  //OK
    swap(d, ch);  //Compilation Error    
}