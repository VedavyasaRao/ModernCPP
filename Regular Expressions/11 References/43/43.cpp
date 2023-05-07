#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <boost/regex.hpp>
using namespace std;

auto reg_pattern  = boost::regex(R"()");
auto reg_input = ""s;
auto reg_replacement = ""s;

void write_header()
{
    cout << "Pattern:" << reg_pattern << endl;
    cout << "Input:" << reg_input << endl;
    if (!reg_replacement.empty())
        cout << "Replacement:" << reg_replacement << endl;
}

void match()
{
    write_header();
    
    boost::smatch m;
    auto b = boost::regex_match ( reg_input, m, reg_pattern);
    cout << boolalpha << "match? " << boolalpha << b << endl;
}



int main()
{
    reg_pattern = boost::regex(R"((a)(b)(c)\k-3)");   
    reg_input = R"(abca)";    
    match();
    cout << endl;

    reg_pattern = boost::regex(R"((a)(b)(c)\k-1)");   
    reg_input = R"(abcc)";    
    match();
    cout << endl;

    reg_pattern = boost::regex(R"((a)(b)(c\k-2))");   
    reg_input = R"(abcb)";    
    match();
    cout << endl;
    return 0;
}