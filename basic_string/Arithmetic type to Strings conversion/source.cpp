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

	cout << "string to_string (int val)" << endl;
	cout << "to_string (100)";
	cout << "\t\t\t\t\t\t\t = [" << to_string(100) << "]" <<  endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (int val)" << endl;
	wcout << "to_wstring (100)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (long val)" << endl;
	cout << "to_string (100l)";
	cout << "\t\t\t\t\t\t = [" << to_string(100l) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (long val)" << endl;
	wcout << "to_wstring (100l)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100l) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (long long val)" << endl;
	cout << "to_string (100ll)";
	cout << "\t\t\t\t\t\t = [" << to_string(100l) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (long long val)" << endl;
	wcout << "to_wstring (100ll)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100l) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (unsigned val)" << endl;
	cout << "to_string (100u)";
	cout << "\t\t\t\t\t\t = [" << to_string(100l) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (unsigned val)" << endl;
	wcout << "to_wstring (100u)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100l) << "]" << endl;
	wcout << endl << endl;


	cout << "string to_string (unsigned long val)" << endl;
	cout << "to_string (100ul)";
	cout << "\t\t\t\t\t\t = [" << to_string(100ul) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (unsigned long val)" << endl;
	wcout << "to_wstring (100ul)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100ul) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (unsigned long long val)" << endl;
	cout << "to_string (100ull)";
	cout << "\t\t\t\t\t\t = [" << to_string(100ull) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (unsigned long long val)" << endl;
	wcout << "to_wstring (100ull)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100ull) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (float val)" << endl;
	cout << "to_string (100.2f)";
	cout << "\t\t\t\t\t\t = [" << to_string(100.2f) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (float val)" << endl;
	wcout << "to_wstring (100.2f)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100.2f) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (double val)" << endl;
	cout << "to_string (100.2)";
	cout << "\t\t\t\t\t\t = [" << to_string(100.2) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (double val)" << endl;
	wcout << "to_wstring (100.2)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100.2) << "]" << endl;
	wcout << endl << endl;

	cout << "string to_string (long double val)" << endl;
	cout << "to_string (100.2l)";
	cout << "\t\t\t\t\t\t = [" << to_string(100.2l) << "]" << endl;
	cout << endl << endl;

	wcout << "wstring to_wstring (long double val)" << endl;
	wcout << "to_wstring (100.2l)";
	wcout << "\t\t\t\t\t\t = [" << to_wstring(100.2l) << "]" << endl;
	wcout << endl << endl;



	return 0;
}