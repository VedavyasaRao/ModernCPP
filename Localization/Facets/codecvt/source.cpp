#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
    locale::global(locale("sv_SE.utf8"));
    cout << "Locale is " << locale().name().c_str() << endl << endl;
    auto& f = use_facet<codecvt<wchar_t, char, mbstate_t>>(locale());
    {
        wstring internal =  L"khri$ha är bäst😂"; //U1+f602
        cout << "out()" << endl;
        mbstate_t mb{}; // initial shift state
        string external(internal.size() * f.max_length(), '\0'); 
        const wchar_t* from_next;
        char* to_next;
        auto result = f.out(mb, &internal[0], &internal[internal.size()], from_next,
                  &external[0], &external[external.size()], to_next);
        cout << "result = " << result << endl;
        if (result == 0)
        {
            external.resize(to_next - &external[0]);
            wcout << "internal wchar_t string :" << internal << endl;
            cout << "The string in narrow multibyte encoding: " << external << endl;
        }
        else 
            cout << "Conversion failed" << endl;
    }
    cout << endl;
    
    {
        string external = "khri$ha är bäst😂"; //U1+f602
     
        wcout << "in()" << endl;
        cout << "external char_t string :" << external << endl;
        mbstate_t mb = mbstate_t(); // initial shift state
        wstring internal(external.size(), '\0'); 
        const char* from_next;
        wchar_t* to_next;
        auto result = f.in(mb, &external[0], &external[external.size()], from_next,
                 &internal[0], &internal[internal.size()], to_next);
        cout << "result = " << result << endl;
        if (result == 0)
        {
            internal.resize(to_next - &internal[0]);
            wcout << "The string in wide encoding: " << internal << '\n';    
        }
        else 
            wcout << "Conversion failed" << endl;
    }
    cout << endl;
    
    {
        cout << "length()" << endl;
        string s = "khri$ha är bäst😂"; //U1+f602
        mbstate_t mb = mbstate_t();
        cout << f.length(mb, s.data()+8, s.data() + s.size(), 2) << " bytes would be consumed"
                 << " to produce är" << endl;
    }        
    cout << endl;
        
    
    {
        cout << "encoding()" << endl;
        cout << "The encoding  is " << ((f.encoding()==0)? "variable":"state dependent") << endl;    
    }
    cout << endl;

    {
        cout << "max_length()" << endl;
        cout << "The longest multibyte character is " << f.max_length() << " bytes long" << endl;    
    }
    cout << endl;

}