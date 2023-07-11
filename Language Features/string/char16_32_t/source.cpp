 #include <climits>
#include <cassert>
#include <clocale>
#include <cstring>
#include <cuchar>
#include <cwchar>
#include <iomanip>
#include <iostream>
 
using namespace std;

void NarrowtoUTF16()
{
    string str(u8"ಖ್ರಿಷಾ Rao🍌"); //"\u0c96\u0ccd\u0cb0\u0cbf\u0cb7\u0cbe rao\U0001F34C"
    cout << "Processing " << str.size() << " bytes: [ " << showbase;
    for (unsigned char c: str)
        cout << hex << +c << ' ';
    cout << "]\n";
 
    mbstate_t state{}; // zero-initialized to initial state
    char16_t c16;
    const char *ptr = &str[0], *end = &str[0] + str.size();
 
    while (size_t rc = mbrtoc16(&c16, ptr, end - ptr + 1, &state))
    {
        cout << "Next UTF-16 char: " << hex 
                  << static_cast<int>(c16) << " obtained from ";
        if (rc == (size_t)-3)
            cout << "earlier surrogate pair\n";
        else if (rc == (size_t) - 2)
            break;
        else if (rc == (size_t) - 1)
            break;
        else
        {
            cout << dec << rc << " bytes [ ";
            for (size_t n = 0; n < rc; ++n)
                cout << hex << +static_cast<unsigned char>(ptr[n]) << ' ';
            cout << "]\n";
            ptr += rc;
        }
    }
}

void UTF16toNarrow()
{
    u16string strv = u"ಖ್ರಿಷಾ Rao🍌"; //"\u0c96\u0ccd\u0cb0\u0cbf\u0cb7\u0cbe rao\U0001F34C"
    cout << "Processing " << strv.size() << " UTF-16 code units: [ ";
    for (char16_t c : strv)
        cout << showbase << hex << static_cast<int>(c) << ' ';
    cout << "]\n";
 
    mbstate_t state{};
    char out[MB_LEN_MAX]{};
    for (char16_t c : strv)
    {   
        size_t rc = c16rtomb(out, c, &state);
        cout << static_cast<int>(c) << " converted to [ ";
        if (rc != (size_t) - 1)
            for (unsigned char c8 : string(out, rc))
                cout << +c8 << ' ';
        cout << "]\n";
    }
}

void NarrowtoUTF32()
{
    string str(u8"ಖ್ರಿಷಾ Rao🍌"); //"\u0c96\u0ccd\u0cb0\u0cbf\u0cb7\u0cbe rao\U0001F34C"
 
    cout << "Processing " << str.size() << " bytes: [ " << showbase;
    for (unsigned char c : str)
        cout << hex << +c << ' ';
    cout << "]\n";
 
    mbstate_t state{}; // zero-initialized to initial state
    char32_t c32;
    const char *ptr = str.c_str(), *end = str.c_str() + str.size() + 1;
 
    while (size_t rc = mbrtoc32(&c32, ptr, end - ptr, &state))
    {   
        cout << "Next UTF-32 char: " << hex
                  << static_cast<int>(c32) << " obtained from ";
        assert(rc != (size_t) - 3); // no surrogates in UTF-32
        if (rc == (size_t) - 1)
            break;
        if (rc == (size_t) - 2)
            break;
        cout << dec << rc << " bytes [ ";
        for (size_t n = 0; n < rc; ++n)
            cout << hex << +static_cast<unsigned char>(ptr[n]) << ' ';
        cout << "]\n";
        ptr += rc;
    }
}


void UTF32toNarrow()
{
    u32string strv = U"ಖ್ರಿಷಾ Rao🍌"; //"\u0c96\u0ccd\u0cb0\u0cbf\u0cb7\u0cbe rao\U0001F34C"
    cout << "Processing " << strv.size() << " UTF-32 code units: [ ";
    for (char32_t c : strv)
        cout << showbase << hex << static_cast<int>(c) << ' ';
    cout << "]\n";
 
    mbstate_t state{};
    char out[MB_LEN_MAX]{};
    for (char32_t c : strv)
    {
        size_t rc = c32rtomb(out, c, &state);
        cout << static_cast<int>(c) << " converted to [ ";
        if (rc != (size_t) - 1)
            for (unsigned char c8 : string{out, rc})
                cout << +c8 << ' ';
        cout << "]\n";
    }
}


int main()
{
    setlocale(LC_ALL, "en_US.utf8");
    cout << "Narrow multibyte string to UTF16 Demo" << endl;
    NarrowtoUTF16();
    cout << endl;

    cout << "UTF16 to Narrow multibyte string Demo" << endl;
    UTF16toNarrow();
    cout << endl;

    cout << "Narrow multibyte string to UTF32 Demo" << endl;
    NarrowtoUTF32();
    cout << endl;

    cout << "UTF32 to Narrow multibyte string Demo" << endl;
    UTF32toNarrow();
    cout << endl;
    
}