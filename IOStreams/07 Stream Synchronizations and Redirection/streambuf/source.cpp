#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    
	cout << "Reuse of same streambuf() Demo" << endl << endl;
	cout << "hexstream: Reusing cout.rdbuf() to initialize" << endl;
	ostream hexout(cout.rdbuf());

	cout << "octstream: Reusing cout.rdbuf() to initialize" << endl << endl;
	ostream octout(cout.rdbuf());

	int n=1969;
	cout << "cout: printing 1969 in decimal to console" << endl;
	cout << "cout: " << n << endl << endl;
	cout << "octstream: printing 1969 in oct to console" << endl;
	octout << oct << showbase << "octout: " << n << endl << endl;
	cout << "hexstream: printing 1969 in hex to console" << endl;
	hexout << hex << showbase << "hexout: " << n << endl;
}