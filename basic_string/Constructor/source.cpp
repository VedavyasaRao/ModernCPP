#include <iostream>
#include <string>

using namespace std;

string printvector(string& iv)
{
	return  '[' + iv + ']';
}

string getitrstring(string& iv, string::iterator& itr)
{
	return  printvector(iv) + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}

int main()
{
	string s("khrisha rao");

	cout << "string()" << endl;
	cout << "string()";
	cout << "\t\t\t\t\t\t = [";
	string s2;
	cout << s2;
	cout << "]";
	cout << endl << endl;


	cout << "string(const string&)" << endl;
	cout << R"(string ([khrisha rao]))";
	cout << "\t\t\t\t\t = [";
	string s3(s);
	cout << s3;
	cout << "]";
	cout << endl << endl;
	
	cout << "string(string&&)" << endl;
	cout << R"(string (move([khrisha rao])))";
	cout << "\t\t\t\t = [";
	string s4(move(s3));
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "string(initializer_list<char>)" << endl;
	cout << R"(string ({'k','h','r','i','s','h','a',' ','r','a','o'}))";
	cout << "\t = [";
	string s5({ 'k','h','r','i','s','h','a',' ','r','a','o' });
	cout << s5;
	cout << "]";
	cout << endl << endl;

	cout << "string (const string& str, size_t pos, size_t len))" << endl;
	cout << "string ([khrisha rao], 0, 7)";
	string s6(s, 0, 7);
	cout << "\t\t\t\t = [";
	cout << s6;
	cout << "]";
	cout << endl << endl;

	cout << "string (const char* s)" << endl;
	cout << "string (\"khrisha rao\")";
	string s7("khrisha rao");
	cout << "\t\t\t\t\t = [";
	cout << s7;
	cout << "]";
	cout << endl << endl;

	cout << "string (const char* s, size_t n)" << endl;
	cout << "string (\"khrisha rao\", 7)";
	string s8("khrisha rao", 7);
	cout << "\t\t\t\t = [";
	cout << s8;
	cout << "]";
	cout << endl << endl;

	cout << "string (size_t n, char c)" << endl;
	cout << "string (7, 'k')";
	string s9(7, 'k');
	cout << "\t\t\t\t\t\t = [";
	cout << s9;
	cout << "]";
	cout << endl << endl;

	cout << "string(InputIterator b, InputIterator e)" << endl;
	cout << "string s9([khrisha rao].begin(), [khrisha rao].end())";
	string s10(s.begin(), s.end());
	cout << "\t = [";
	cout << s10;
	cout << "]";
	cout << endl << endl;

	return 0;
}