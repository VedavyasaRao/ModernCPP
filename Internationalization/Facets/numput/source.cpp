#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
	ostringstream oss;
	double dbl = 1234567.89;
	cout << fixed;
	oss << fixed;

	auto loc = locale("en_US.UTF-8");
	oss.imbue(loc);
	oss << dbl;
	cout << "Converted  " << dbl << " to " << oss.str() << " in " << loc.name() << endl;

	auto& numput = use_facet<num_put<char>>(loc);

	oss.str("");
	numput.put(std::ostreambuf_iterator<char>(oss), oss, ' ', dbl);
	cout << "Converted using put " << dbl << " to " << oss.str() << " in " << loc.name() << endl;

	loc = locale("de_DE.UTF-8");
	oss.str("");
	oss.imbue(loc);
	oss << dbl;
	cout << "Converted  " << dbl << " to " << oss.str() << " in " << loc.name() << endl;

	loc = locale("en_IN.UTF-8");
	oss.str("");
	oss.imbue(loc);
	oss << dbl;
	cout << "Converted  " << dbl << " to " << oss.str() << " in " << loc.name() << endl;
} 