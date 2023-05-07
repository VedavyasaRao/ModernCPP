#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;
int main()
{
    string msg = "Hello, Khri$ha!";
    cout << "streambuf_iterator iterator demo " << endl << endl;

    cout << "stringstream: creating and initializing " 
        << "with \"" << msg << "\"" << endl;
	istringstream iss(msg);
	
    cout << "istreambuf_iterator: creating and initializing to stringstream" << endl;
	istreambuf_iterator<char> ibuf(iss),ibufend;
    cout << "ostreambuf_iterator: creating and initializing to cout" << endl;
	ostreambuf_iterator<char> obuf(cout);
	cout << "streambuf_iterator: iterating read(stringstream)/write(cout) till eof" << endl;
	for (; ibuf != ibufend; ++ibuf)
		*obuf = *ibuf;
}