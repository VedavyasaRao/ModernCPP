#include <iostream>
#include <locale>
#include <iomanip>
#include <fstream>
using namespace std;

struct custom_tf : numpunct<char>
{
	string do_truename()  const { return "nija"; }
	string do_falsename() const { return "sullu"; }
};

int main()
{
	cout << boolalpha;

	// default boolalpha output
	cout << "Default locale," << endl
		<< "  boolalpha  true: " << true << endl
		<< "  boolalpha false: " << false << "\n\n";

	// with custom_tf applied to locale
	cout.imbue(locale(cout.getloc(), new custom_tf));
	cout << "Locale with modified numpunct," << endl
		<< "  boolalpha  true: " << true << endl
		<< "  boolalpha false: " << false << endl;
}