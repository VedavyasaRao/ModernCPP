#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	cout << "Built-in stream redirection Demo" << endl << endl;
	cout << "stringstream: creating memory stream for read/write" << endl;
	stringstream ss;
	cout << "initializing clog redirection to stringstream" << endl << endl;
	clog.rdbuf(ss.rdbuf());

    string msg = "Hello, Khri$ha!";
    cout << "clog: printing  \"" << msg << '"' << endl;
    clog << msg;

    cout << "stringstream: received \"" << ss.str() << '"' << endl;
}