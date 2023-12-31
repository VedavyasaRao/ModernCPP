#include <iostream>
#include <utility>
#include <tuple>
#include <string>

using namespace std;

template <size_t i, typename ...Args>
struct printer
{
    void print(ostream &os, const tuple<Args...>& tup)
    {
        printer<i-1,  Args...>{}.print(os,tup);
        os << get<i>(tup) << ((sizeof ...(Args) > i+1)?",":"]");
    }
};

template <typename ...Args>
struct printer<0, Args...>
{
    void print(ostream &os, const tuple<Args...>& tup)
    {
         os << "[" << get<0>(tup) << ((sizeof ...(Args) > 1)?",":"]");
    }
};

template<typename ...Args>
ostream& operator<< (ostream& os, const tuple<Args...> &tup)
{
    constexpr int n=sizeof...(Args);
    printer<n-1,Args...>().print(os,tup);
    return os;
}

int main()
{
    cout << R"(tuple<int,float, string> t(2018,4.11, "Khri$ha"))" << endl;
    tuple<int,float, string> t(2018,4.11, "Khri$ha");
    cout << t << endl  << endl;

    cout << R"(tuple<int> t2(1975))" << endl;
    tuple<int> t2(1975);
    cout << t2 << endl;
}