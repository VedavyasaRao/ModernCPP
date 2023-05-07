#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    cout << "****************************" << endl;
    cout << "ios::manipulators for istream" << endl;
    cout << "****************************" << endl << endl;

    bool bt, bf;
    cin >> boolalpha >> bt >> bf;
    cout << "boolalpha example" << endl;
    cout << boolalpha << "true is:" << bt << endl
        << "false is:" << bf << endl << endl;
    
    cin >> noboolalpha >> bt >> bf;
    cout << "noboolalpha example" << endl;
    cout << noboolalpha << "true is:" << bt << endl
        << "false is:" << bf << endl << endl;

    int o,h;
    cin >> oct >> o;
    cin >> hex >> h;
    cout << "oct hex example" << endl;
    cout << showbase 
        << oct << o << " oct is decimal " << dec << o << endl 
        << hex << h << " hex is decimal " << dec << h << endl 
        << endl << endl;

    istringstream inp ("hello world!");
    string s1, s2;
    cout << "skipws example" << endl;
    inp >> skipws >> s1 >> s2;
    cout << "Parsing \"" << inp.str() << "\" yields \"" << s1 << "\"  \"" << s2 << '"'
        << endl << endl;
    inp.clear();
    inp.seekg(0, ios::beg);
    cout << "noskipws example" << endl;
    inp >> noskipws >> s1 >> s2;
    cout << "Parsing \"" << inp.str() << "\" yields \"" << s1 << "\"  \"" << s2 << '"'
        << endl << endl;

    cout << "ws example" << endl;
    string sample = "one \n \n \n two";
    string a, b;
    istringstream iss (sample);
    //cout << R"(one \n \n \n two)" << endl;
    cout << quoted(sample) << endl;
    getline(iss,a);
    getline(iss,b);
    cout << "getline Without ws yields "
        << "a:" << a << "b:" << b << endl;

    iss.str(sample);
    getline(iss,a);
    getline(iss>>ws,b);
    cout << "getline With ws yields "
        << "a:" << a << "b:" << b << endl << endl;

    cout << "get_currency example" << endl;
    std::istringstream in("$1,234.56 2.22 USD  3.33");
    long double v1, v2;
    std::string v3;
 
    in.imbue(std::locale("en_US.UTF-8"));
    in >> std::get_money(v1) >> std::get_money(v2) >> std::get_money(v3, true);
    cout << std::quoted(in.str()) << endl 
         << "parsed as: " << endl 
         << v1 << ", " << v2 << ", " << v3 << endl << endl;
    
    cout << "get_time example" << endl;
    std::tm t = {};
    std::istringstream ss("2018-September-21 11:58:00");
    ss.imbue(std::locale("en_US.UTF8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
    cout << "Parsing " << ss.str() << " in US locale yields" << endl 
        << std::put_time(&t, "%c") << endl << endl;
    return 0;
}