#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>
using namespace std;

template <size_t i, typename ...Args>
struct HandleManipulator
{
    void doit(ostream &os, const tuple<Args...>& tup)
    {
        HandleManipulator<i-1,  Args...>{}.doit(os,tup);
        os << get<i>(tup);
    }
};

template <typename ...Args>
struct HandleManipulator<0, Args...>
{
    void doit(ostream &os, const tuple<Args...>& tup)
    {
         os << get<0>(tup);
    }
};

template<typename ...Args>
ostream& operator<< (ostream& os, const tuple<Args...> &tup)
{
    constexpr int n=sizeof...(Args);
    HandleManipulator<n-1,Args...>().doit(os,tup);
    return os;
}

template<typename U, typename V>
ostream& operator<< (ostream& os, const pair<U,V> &p)
{
    os << p.second;
    os << p.first;
    return os;
}

template<class T>
void process(ostream& os, T t)
{
	os << t;

}

void smartprint(ostream&) {}

template<typename T, typename... Ts>
void smartprint(ostream& os, T t, Ts... ts)
{
 	process(os, t);
	// “ts” is its pattern
	// “ts...” is  pack expansion
	smartprint(os, ts...);
}

int main()
{
    time_t t = std::time(nullptr);
    tm tm = *localtime(&t);
    bool b = true;
    long m = 123456;
    double h = 1.56795;
    const char * ssn ="123";
 
    cout.imbue(locale("en_US.UTF-8"));
	cout << R"z(	smartprint(cout, 
        "Citizen\t\t\t:", make_pair(b, make_tuple(boolalpha)), 
        "\nheight(meters)\t\t:", make_pair(h, make_tuple(fixed,setprecision(3))),
        "\nincome\t\t\t:", make_pair(put_money(m),  make_tuple(showbase)),
        "\nSocial Security number\t:", make_pair(ssn, make_tuple(left,setw(8),setfill('#'),showbase)),
        "\ntime stamp\t\t:", put_time(&tm, "%c %Z"),
        "\n"))z" << endl << endl;

	smartprint(cout, 
        "Citizen\t\t\t:", make_pair(b, make_tuple(boolalpha)), 
        "\nheight(meters)\t\t:", make_pair(h, make_tuple(fixed,setprecision(3))),
        "\nincome\t\t\t:", make_pair(put_money(m),  make_tuple(showbase)),
        "\nSocial Security number\t:", make_pair(ssn, make_tuple(left,setw(8),setfill('#'),showbase)),
        "\ntime stamp\t\t:", put_time(&tm, "%c %Z"),
        "\n");

}