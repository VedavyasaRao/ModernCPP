#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>

using namespace std;

int main()
{
    // using the I/O manipulator
    cout.imbue(locale("en_US.UTF-8"));
    cout << "American locale: "
               << showbase << put_money(12345678.9) << endl;
 
    // using the facet directly
    cout.imbue(locale("sv_SE.UTF-8"));
    cout << "Swedish locale: ";
    auto& f = use_facet<money_put<char>>(cout.getloc());
    f.put({cout}, false, cout, cout.fill(), 12345678.9);
    cout << endl;
}