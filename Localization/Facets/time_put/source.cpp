#include <iostream>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;

 
int main()
{
    time_t t = std::time(NULL);
    string fmt = "%c";
    tm tm = *localtime(&t);
 
    cout << "put()" << endl;
    for (auto ln:{"C","en_US.utf-8","ja_JP.utf8","de_DE.utf-8",	
    "sv_SE.utf-8","en_IN.utf-8"})
    {
        auto l = locale(ln);
        auto &f = use_facet<time_put<char>>(l);
        cout.imbue(l);
        cout << "Locale is " << l.name() << endl;
        f.put({cout}, cout, ' ', &tm, &fmt[0], &fmt[0] + fmt.size());
        cout << endl;
    }
   cout << endl;
}   