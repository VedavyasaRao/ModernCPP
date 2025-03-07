#include <iostream>
#include <array>

using namespace std;

/*
template<typename Iterator>
struct iterator_traits2 {
using difference_type = typename Iterator::difference_type;
using value_type = typename Iterator::value_type;
using pointer = typename Iterator::pointer;
using reference = typename Iterator::reference;
using iterator_category = typename Iterator::iterator_category;
};
*/

int main()
{
    array<int,10> a;
    auto itr = a.begin();
    //reference to the first element
    iterator_traits<decltype(itr)>::reference b  =  *itr; //int&  
    b = 100; //*itr == 100;
}