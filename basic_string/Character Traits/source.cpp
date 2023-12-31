#include <iostream>   // std::cout
#include <string>     // std::char_traits
#include <cctype>     // std::tolower
#include <cstddef>    // std::size_t

using namespace std;

// case-insensitive traits:
struct custom_traits: std::char_traits<char> 
{
    static bool eq (char c, char d) 
    { 
      return std::tolower(c)==std::tolower(d); 
    }
    static bool lt (char c, char d) 
    { 
      return std::tolower(c)<std::tolower(d); 
    }
  
    static int compare (const char* p, const char* q, std::size_t n) 
    {
        while (n--) 
        {
            if (!eq(*p,*q)) return lt(*p,*q)?-1:1; 
            ++p; ++q;
        }
        return 0;
    }
};

typedef basic_string<char,custom_traits> insensitive_string;

using namespace std;
int main ()
{
    {
        char foo[] = "---o............";
        cout << R"(char foo[] = "---o............";)" << endl;
        cout << R"(char_traits<char>::move (foo+3,foo,4);)" << endl;
        cout << R"(char_traits<char>::move (foo+6,foo,7);)" << endl;

        cout << foo << endl;
        char_traits<char>::move (foo+3,foo,4);
        cout << foo << endl;
        char_traits<char>::move (foo+6,foo,7);
        cout << foo << endl;

        cout << endl;
    }
    
    {
        insensitive_string foo{"Test"},bar{"test"};
        cout << R"(insensitive_string foo{"Test"},bar{"test"};)" << endl;
        cout << boolalpha << "(foo==bar):\t" <<  (foo==bar) << endl;
    }
    
    return 0;
}