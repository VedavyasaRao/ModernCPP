#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	cout << "File I/O example" << endl << endl
    << "Opening file output.txt for write" << endl;
    ofstream fo("output.txt", ios::out);
    cout << "Writing Text to the file " << endl;
	fo << "hello, Khri$ha!" << endl;
	fo << "how are you doing?" << endl;
	cout << "Closing file " << endl << endl;
    fo.close();

    cout << "Opening file output.txt for read" << endl;
	ifstream fi("output.txt", ios::in);
	vector<char> data(1000);
    cout << "Reading from the file " << endl << endl;
	fi.read(data.data(), data.size());
	cout << "Closing file " << endl << endl;
	fi.close();
    cout << "Dumping contents:" << endl << endl;
	cout << data.data();
}