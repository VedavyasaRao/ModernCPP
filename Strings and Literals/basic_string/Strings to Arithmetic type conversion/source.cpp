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
	size_t idx{};

	cout << "int stoi (const string&  str, size_t* idx = 0, int base = 10)" << endl;
	cout << "stoi ([100])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stoi("100") << endl;
	cout << "stoi([100], nullptr, 16)";
	cout << "\t\t\t\t\t\t\t\t = " << stoi("100", nullptr, 16) << endl;
	cout << "stoi([0xabcdworld!], &idx, 0)";
	cout << "\t\t\t\t\t\t\t\t = " << stoi("0xabcdworld!", &idx, 0);
	cout << "    idx = " << idx << endl;
	cout << endl << endl;


	cout << "long stol (const string&  str, size_t* idx = 0, int base = 10)" << endl;
	cout << "stol ([10l])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stol("10l") << endl;
	cout << endl << endl;

	cout << "unsigned long stoul (const string&  str, size_t* idx = 0, int base = 10)" << endl;
	cout << "stoul ([10ul])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stoul("10ul") << endl;
	cout << endl << endl;

	cout << "long long stoll (const string&  str, size_t* idx = 0, int base = 10)" << endl;
	cout << "stoll ([10ll])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stoll("10ll") << endl;
	cout << endl << endl;

	cout << "unsigned long long stoull (const  str, string&  str, size_t* idx = 0, int base = 10)" << endl;
	cout << "stoull ([10ull])";
	cout << "\t\t\t\t\t\t\t\t\t = " << stoull("10ull") << endl;
	cout << endl << endl;

	cout << "float stof (const string&  str, size_t* idx = 0)" << endl;
	cout << "stof ([10.2f])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stof("10.2f") << endl;
	cout << endl << endl;

	cout << "double stod (const string&  str, size_t* idx = 0)" << endl;
	cout << "stod ([10.2])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stod("10.2") << endl;
	cout << endl << endl;

	cout << "long double stold (const string&  str, size_t* idx = 0)" << endl;
	cout << "stold ([10.2l])";
	cout << "\t\t\t\t\t\t\t\t\t\t = " << stold("10.2l") << endl;
	cout << endl << endl;

	return 0;
}