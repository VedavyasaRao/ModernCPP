#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <system_error>
#include <boost/filesystem.hpp>
#include <boost/filesystem/exception.hpp>

namespace fs = boost::filesystem;
using namespace std;

int main()
{
    boost::system::error_code ec;
    fs::create_directory("",ec);
    if (!ec)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "errorCode.message():\t\t\t\t" << ec.message() << endl;
        cout << "errorCode.value():\t\t\t\t" << ec.value() << "(ENOENT)" << endl;
        cout << "errorCode.default_error_condition().value():\t" << ec.default_error_condition().value() 
            << "(errc::no_such_file_or_directory)" << endl;            
    }
}
