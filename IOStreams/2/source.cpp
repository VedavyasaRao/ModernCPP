#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string buf;
    int n=0;
	cout << "cin: Enter a text from keyboard" << endl;
	cin >> buf;
	cout << "cout: " << buf << " was entered from keyboard" 
        << endl << endl; 

    stringstream ss;
	cout << "stringstream: Writing 100 to string stream" << endl;
	ss << 100;
	ss >> n;
    cout << "stringstream: Parased number from string stream is " << n
        << endl << endl;

	cout << "Opening output.txt file for write" << endl;
	ofstream ofs ("output.txt");
	cout << "ofstream: Writing " << 1000  << " to output.txt file" << endl;
    ofs << 1000;
	ofs.close();
	cout << "Closing output.txt file " << endl << endl;

	cout << "Opening output.txt file for read" << endl;
	ifstream ifs ("output.txt");
	ifs >> n;
	cout << "ifstream: Read " << n << " from output.txt file" << endl;
	ifs.close();
	cout << "Closing output.txt file" << endl << endl;


	return 0;
}