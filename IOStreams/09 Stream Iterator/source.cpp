#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    string msg = "1 2 3 4 5";
    cout << "stream_iterator iterator demo " << endl << endl;

    cout << "stringstream: creating and initializing " 
        << "with \"" << msg << "\"" << endl;
	istringstream iss(msg);
	
    cout << "istream_iterator: creating and initializing to stringstream" << endl;
	istream_iterator<int> ibuf(iss),ibufend;
    cout << "ostream_iterator: creating and initializing to cout" << endl;
	ostream_iterator<int> obuf(cout, " ");
	cout << "partial_sum: iterating read(stringstream)/write(cout) till eof" << endl;
    partial_sum(ibuf,ibufend,obuf);
}