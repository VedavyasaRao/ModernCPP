#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//ಖ್ರಿಷಾ Rao👸
int main()
{
	string s("khrisha rao");

	cout << boolalpha;
	cout << "c_str()" << endl;
	cout << "[khrisha rao].c_str()\t\t\t = [";
	for_each(s.begin(), s.end(), [](char c) {cout << c << ",";});
	cout << "\\0]";
	cout << endl << endl;
	
	cout << "data()" << endl;
	cout << "[khrisha rao].data()\t\t\t = [";
	for_each(s.begin(), s.end()-1, [](char c) {cout << c << ","; });
	cout << *(s.end()-1) << "]";
	cout << endl << endl;

	cout << "size()" << endl;
	cout << "[khrisha rao].size()\t\t\t = " << s.size();
	cout << endl << endl;

	cout << "length()" << endl;
	cout << "[khrisha rao].length()\t\t\t = " << s.length();
	cout << endl << endl;

	s = "";
	cout << "max_size()" << endl;
	cout << "[].max_size()\t\t\t\t = " << s.max_size();
	cout << endl << endl;

	s = "khrisha rao";
	cout << "resize(size_t n)" << endl;
	s.resize(7);
	cout << "[khrisha rao].resize(7)\t\t\t = " << s;
	cout << endl << endl;

	s = "";
	cout << "resize(size_t n, char c)" << endl;
	s.resize(20, 'k');
	cout << "[].resize(20,'k')\t\t\t = " << s;
	cout << endl << endl;

	s = "";
	cout << "capacity()" << endl;
	cout << "[kkkkkkkkkkkkkkkkkkkk].capacity()\t = " << s.capacity();
	cout << endl << endl;

	s = "";
	cout << "reserve()" << endl;
	s.reserve();
	cout << "[].reserve()" << endl;
	cout << "[].capacity()\t\t\t\t = " << s.capacity();
	cout << endl << endl;

	cout << "reserve(size_t n)" << endl;
	s.reserve(1000);
	cout << "[].reserve(1000)" << endl;
	cout << "[].capacity()\t\t\t\t = " << s.capacity();
	cout << endl << endl;

	s = "khrisha rao";
	cout << "clear()" << endl;
	s.clear();
	cout << "[khrisha rao].clear()" << endl;
	cout << "[].empty()\t\t\t\t = " << s.empty();
	cout << endl << endl;


	s = "khrisha rao";
	cout << "empty()" << endl;
	cout << "[khrisha rao].empty()\t\t\t = " << s.empty();
	cout << endl << endl;

	cout << "shrink_to_fit()" << endl;
	s.reserve(1000);
	s = "khrisha rao";
	s.resize(11);
	cout << "[khrisha rao].capacity()\t\t = " << s.capacity() << endl;
	s.shrink_to_fit();
	cout << "[khrisha rao].shrink_to_fit()" << endl;
	cout << "[khrisha rao].capacity()\t\t = " << s.capacity();
	cout << endl << endl;

	return 0;
}