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
    cout  << "****************"  << endl;
    cout << "Pattern:" << reg_pattern << endl;
    cout << "Input:" << reg_input << endl;
    if (!reg_replacement.empty())
        cout << "Replacement:" << reg_replacement << endl;
    cout  << "****************"  << endl;
}

void match()
{
    write_header();
    
    boost::smatch m;
    auto b = boost::regex_match ( reg_input, m, reg_pattern);
    cout << boolalpha << "match:" << b << endl;
    if (!b)
    {
        cout << endl;
        return;
    }   
    
    for (auto i=0u; i<m.size(); ++i)
    {
        cout  << "****************"  <<endl;
        cout  << m[i]<< endl;
        cout << "****************"  <<endl;
      }    
}

void replace()
{
    write_header();
    //Note $0 means full match ; $1 means sub match
    std::cout << boost::regex_replace(reg_input, reg_pattern, reg_replacement) << '\n';
}

void search()
{
    write_header();
    boost::regex_token_iterator<std::string::iterator> it;
    //Note: 0 means full match; 1 means sub match(es)
    it = {reg_input.begin(), reg_input.end(), reg_pattern, {0,1}};
    boost::regex_token_iterator<std::string::iterator> theend;
    if (it == theend)
    {
        cout << "No matches!" << endl;
        return;
    }

    while (it != theend)
    {
        cout  << "****************"  << endl;
        cout  << *it << endl;
        cout << "****************"  << endl;
        ++it;
    }
}

int main()
{
    cout << "Match input postive testcase - match SSN" << endl;
    reg_pattern = boost::regex(R"(\d{3}-\d{2}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    match();
    cout << endl;

    cout << "Match input  negative testcase - match Phone number" << endl;
    reg_pattern = boost::regex(R"(\d{3}-\d{3}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    match();
    cout << endl;

    cout << "Extract from input postive testcase - find adjacent duplicate words" << endl;
    reg_pattern = boost::regex(R"((\b\w+\b)\s+\1)");   
    reg_input = R"(state of of  the the art)";    
    search();
    cout << endl;

    cout << "Extract from input negative testcase - extract area code" << endl;
    reg_pattern = boost::regex(R"((\d{3})-\d{3}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    search();
    cout << endl;
    
    cout << "Replace text testcase - full replacement with new string" << endl;
    reg_input = R"(Hello, World!)";    
    reg_pattern = boost::regex("World");   
    reg_replacement = "Khri$ha";
    replace();
    cout << endl;
    
    cout << "Replace text testcase - full replacement with sub match" << endl;
    reg_pattern = boost::regex(R"((\b\w+\b)\s+\1)");   
    reg_input = R"(state of of  the the art)";    
    reg_replacement = "$1";
    replace();
    cout << endl;

    
    return 0;
}

