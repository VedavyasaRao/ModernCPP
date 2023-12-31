#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <cuchar>
#include <cwchar>
#include <climits>
#include <clocale>

using namespace std;

int main()
{
	string flname("rao,khrisha");
	string fname, lname;
	stringstream ss;

	cout << "operator<< (ostream& os, const string& str)" << endl;
	cout << "operator << ([stringstream], [rao,khrisha])" << endl;
	operator << (ss, flname);
	cout << endl << endl;

	flname.clear();
	cout << "operator>> (istream& is, string& str)" << endl;
	cout << "operator >> ([stringstream], [])";
	operator >> (ss, flname);
	cout << "\t\t\t = [" << flname << "]" << endl;
	cout << endl << endl;

	ss.seekg(0, ios_base::beg);
	cout << "getline (istream& is, string& str, char delim)" << endl;
	cout << "getline ([stringstream], [], ',')";
	getline(ss, lname, ',');
	cout << "\t\t\t = [" << lname << "]" << endl;
	cout << endl << endl;

	cout << "getline (istream& is, string& str)" << endl;
	cout << "getline ([stringstream], [])";
	getline(ss, fname);
	cout << "\t\t\t\t = [" << fname << "]" << endl;
	cout << endl << endl;


	return 0;
}
