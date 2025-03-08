#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;
int main()
{
	for (const char* name : { "en_US.UTF-8", "de_DE.UTF-8", "en_IN.UTF-8" })
	{
		locale loc = locale(name); 
		cout.imbue(loc);
		cout << "Locale Name is " << loc.name() << endl;
		auto &np = use_facet<numpunct<char>>(loc);

		cout << dec;
		cout << "decimal point is "
		<< np.decimal_point() << endl << "Example:" << 3.14156 << endl;

		std::cout << "thousands separator is "
			<< np.thousands_sep() << endl << "Example:"  << 10000000 << endl;
		 
		std::cout << "numeric grouping is ";
		for (int c : np.grouping()) 
			cout << showbase <<  oct << '\\'  << c  << ',';
		cout << endl << "Example:" << dec << 10000000 << endl;

		std::cout << "true name is " << boolalpha 
			<< np.truename() << endl << "Example: 1 is " << true << endl;

		std::cout << "false name is " << boolalpha
			<< np.falsename() << endl << "Example 0 is:" << false << endl;
		cout << endl;
	}
}