#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
	istringstream iss;
	double dbl;

	auto loc = locale("en_US.utf8");
	iss.str("1,234,567.89");
	iss.imbue(loc);
	iss >> dbl;
	cout << "Parsing " << iss.str() << " as double gives " << fixed
		<< dbl << " in " << loc.name() << endl;

	auto& numget = use_facet<num_get<char>>(loc);
	ios::iostate err;
	iss.str("1,234,567.89");
	istreambuf_iterator<char> beg(iss), end;
	numget.get(beg, end, iss, err, dbl);
	cout << "Parsing using get() " << iss.str() << " as double gives " << fixed
		<< dbl << " in " << loc.name() << endl;

	loc = locale("de_DE.UTF-8");
	iss.str("1.234.567,89");
	iss.imbue(loc);
	iss >> dbl;
	cout << "Parsing " << iss.str() << " as double gives " << fixed
		<< dbl << " in " << loc.name() << endl;

	loc = locale("en_IN.UTF-8");
	iss.str("12,34,567.89");
	iss.imbue(loc);
	iss >> dbl;
	cout << "Parsing " << iss.str() << " as double gives " << fixed
		<< dbl << " in " << loc.name() << endl;
}
