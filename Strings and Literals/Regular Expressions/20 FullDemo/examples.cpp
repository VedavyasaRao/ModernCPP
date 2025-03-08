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

void print_submatches(const boost::smatch m)
{
    cout << "Sub matches:" << endl;
    for (auto i=1u; i<m.size(); ++i)
    {
        cout  << m[i]<< endl;
    }    
    cout << endl;
        
}

void match()
{
    write_header();
    
    boost::smatch m;
    auto b = boost::regex_match ( reg_input, m, reg_pattern);
    cout << boolalpha << "match? " << boolalpha << b << endl;
}

void replace()
{
    write_header();
    //Note $0 means full match ; $1 means sub match
    std::cout << "result:" << boost::regex_replace(reg_input, reg_pattern, reg_replacement) <<  endl;;
}

void searchwithsmatch()
{
    write_header();
    boost::smatch reg_matches;
    if (boost::regex_search(reg_input, reg_matches, reg_pattern))
    {
        print_submatches(reg_matches);
    }
}

void searchwithtokenizer(int matchsel)
{
    write_header();
    boost::regex_token_iterator<std::string::iterator> it;
    //Note: 0 means full match; 1 means sub match(es); -1 means no matches
    it = {reg_input.begin(), reg_input.end(), reg_pattern, matchsel};
    boost::regex_token_iterator<std::string::iterator> theend;
    if (it == theend)
    {
        cout << "No matches!" << endl;
        return;
    }

    cout << "Sub matches:" << endl;
    while (it != theend)
    {
        cout  << *it << endl;
        ++it;
    }
}


int main()
{
    cout << "match: positive testcase - match SSN" << endl;
    reg_pattern = boost::regex(R"(\d{3}-\d{2}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    match();
    cout << endl;

    cout << "match: negative testcase - match Phone number" << endl;
    reg_pattern = boost::regex(R"(\d{3}-\d{3}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    match();
    cout << endl;

    cout << "search: positive testcase - extract area code" << endl;
    cout << "using non recursive smatch" << endl;
    reg_pattern = boost::regex(R"((\d{3})-\d{3}-\d{4})");   
    reg_input = R"(408-206-2335)";    
    //searchwithsmatch();
    searchwithtokenizer(1);
    cout << endl;

    cout << "search: negative testcase - extract area code" << endl;
    cout << "using non recursive smatch" << endl;
    reg_pattern = boost::regex(R"((\d{3})-\d{3}-\d{4})");   
    reg_input = R"(123-45-6789)";    
    searchwithsmatch();
    cout << endl;

    cout << "search: find recurring duplicate words" << endl;
    cout << "using recursive tokenizer(1)" << endl;
    reg_pattern = boost::regex(R"((\b\w+\b)\s+\1)");   
    reg_input = R"(state of of the the art)";    
    searchwithtokenizer(1);
    cout << endl;

    cout << "search: find recurring non duplicate words" << endl;
    cout << "using recursive tokenizer(-1)" << endl;
    reg_pattern = boost::regex(R"((\b\w+\b)\s+\1)");   
    reg_input = R"(state of of  the the art)";    
    searchwithtokenizer(-1);
    cout << endl;
    
    cout << "replace: full replacement with new string" << endl;
    reg_input = R"(Hello, World!)";    
    reg_pattern = boost::regex("World");   
    reg_replacement = "Khri$ha";
    replace();
    cout << endl;
    
    cout << "replace: full replacement with sub match" << endl;
    reg_pattern = boost::regex(R"((\b\w+\b)\s+\1)");   
    reg_input = R"(state of of  the the art)";    
    reg_replacement = "$1";
    replace();
    cout << endl;

    cout << "replace: internationalization with sweden locale" << endl;
    reg_input = "khri$ha är bättre";
    reg_pattern.imbue(locale{"sv_SE.UTF-8"});
    reg_pattern = "bättre";
    reg_replacement = "bäst😂";
    replace();
    cout << endl;

    
    return 0;
}
