#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <iterator>
 using namespace std;
 
int main()
{
    string str = "$1.11 $2.22 $3.33";
    cout << fixed << setprecision(2);
 
    cout << '"' << str << "\" parsed with the I/O manipulator: ";
    istringstream s1(str);
    s1.imbue(locale("en_US.UTF-8"));
 
    long double val;
    while (s1 >> get_money(val))
        cout << val / 100 << ' ';
    cout << endl;
 
    str = "USD  1,234.56";
    cout << '"' << str << "\" parsed with the facet directly: ";
    istringstream s2(str);
    s2.imbue(locale("en_US.UTF-8"));
 
    auto& f = use_facet<money_get<char>>(s2.getloc());
    ios_base::iostate err;
    istreambuf_iterator<char> beg(s2), end;
    f.get(beg, end, true, s2, err, val);
 
    cout << val / 100 << endl;
}