#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


using namespace std;

int main()
{
	cout << "Memory I/O example" << endl << endl;
	ostringstream fo;
    cout << "Writing Text to the string buffer " << endl;
	fo << "hello, Khri$ha!" << endl;
	fo << "how are you doing?" << endl;

	istringstream fi(fo.str() );
	vector<char> data(1000);
    cout << "Reading from the string buffer " << endl << endl;
	fi.read(data.data(), data.size());
    cout << "Dumping contents:" << endl << endl;
	cout << data.data();
}