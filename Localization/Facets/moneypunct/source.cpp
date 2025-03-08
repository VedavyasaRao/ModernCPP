#include <iostream>
#include <iomanip>
#include <locale>

 
using namespace std;

ostream&   operator << (ostream& os, const money_base::pattern& pat)
{
    string names[] = {"none", "space", "symbol", "sign", "value"};
    for(auto c:pat.field)
    {
        os << names[(short)c] << ",";
    }
    return os;
}

void show_dpt(const char* locname)
{
    locale loc(locname);
    cout.imbue(loc);
    auto &f = use_facet<moneypunct<char>>(loc);
    cout << locname << endl;
    cout << "decimal point: '" << f.decimal_point() << "'" << endl ;
    cout << "frac_digits: " << f.frac_digits() << endl ;
    cout << "thousands_sep: '" << f. thousands_sep() << "'" << endl;
    cout << "grouping is {";
        for (auto c :f.grouping()) cout << char(c+'0') << ",";
    cout << "}" << endl;
    cout << "currency symbol: '" << f.curr_symbol() << "'" << endl ;
    cout << "positive sign: '" << f.positive_sign() << "'" << endl ;
    cout << "negative sign: '" << f.negative_sign() << "'" << endl ;
    cout << "pos format: {" << f.pos_format() << "}" << endl ;
    cout << "neg format: {" << f.neg_format() << "}" << endl ;

    cout << endl;
}
 
int main()
{
    show_dpt("en_US.utf8");
    show_dpt("en_IN.utf8");
    show_dpt("ja_JP.utf8");
    show_dpt("sv_SE.utf8");
    show_dpt("de_DE.utf8");
 
}