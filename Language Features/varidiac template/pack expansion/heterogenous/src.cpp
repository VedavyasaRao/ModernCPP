#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <size_t i, typename T, typename... Ts>
struct nthTypePtr : nthTypePtr<i - 1, Ts...> 
{
    static_assert(i < sizeof...(Ts)+1, "index is out of bounds");
};

template <typename T, typename... Ts>
struct nthTypePtr<0, T, Ts...> 
{ 
    T* valueptr;
};

template <size_t i,typename T, typename... Ts>
void * get(T* t) 
{
    return t;
}

template <size_t i, typename T, typename... Ts>
void *  get(T *t, Ts... ts) 
{
    if (i > 0)
       return get<i-1>(ts...);
    return t;
}

template <size_t i,  typename... Ts>
auto  getter(Ts... ts) -> decltype(*(nthTypePtr<i, Ts...>::valueptr))
{
    return *reinterpret_cast<decltype(nthTypePtr<i, Ts...>::valueptr)>(get<i>(&ts...));
}

int main()
{
    cout << R"(getter<2>(100, 2.34, "3,4"))" << endl << endl;
    cout << "output:" << endl;
    cout << getter<2>(100, 2.34, "3,4") << endl;


    return 0;
}