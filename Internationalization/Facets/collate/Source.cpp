#include <iostream>
#include <string>
#include <locale>

using namespace std;

 
int main()
{
    wstring s1(L"år"), s2(L"ängel");
    auto lse = locale("sv_SE.UTF-8");

    //needed for console output
    setlocale(LC_ALL,   "sv_SE.UTF-8");
    
    wcout << "compare()" << endl;
	wcout << "Comparing \"" << s1 << "\" with \"" << s2 << '"' << endl;

    for (auto l :{locale(""),lse})
    {
        auto& f = use_facet<collate<wchar_t>>(l);
	    wcout << "In the locale: " << l.name().c_str() << endl;

        if(f.compare(&s1[0], &s1[0] + s1.size(),&s2[0], &s2[0] + s2.size() ) < 0)
            wcout << s1 << " before " << s2 << '\n';
        else
            wcout << s2 << " before " << s1 << '\n';
    }

    wcout << endl;
    
    wcout << "transform()" << endl;
    auto& f = use_facet<collate<wchar_t>>(lse);
    wstring out1 = f.transform(&s1[0], &s1[0] + s1.size());
    wstring out2 = f.transform(&s2[0], &s2[0] + s2.size());
 
    wcout << "In the locale: " << lse.name().c_str() << endl;
    wcout << "Transfrom of " << s1 << " is " << out1 << endl;
    wcout << "Transfrom of " << s2 << " is " << out2 << endl;
 
    wcout << endl;
    
    wcout << "hash()" << endl;
    auto h1 = f.hash(&s1[0], &s1[0] + s1.size());
    auto h2 = f.hash(&s2[0], &s2[0] + s2.size());
 
    wcout << "In the locale: " << lse.name().c_str() << endl;
    wcout << "Hash of " << s1 << " is " << h1 << endl;
    wcout << "Hash of " << s2 << " is " << h2 << endl;
}