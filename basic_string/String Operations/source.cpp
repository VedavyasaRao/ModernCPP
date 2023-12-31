#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s("khrisha rao");
	string s2("khrisha");
	string s3(" rao");
	string s4;
	char buf[100]={};
	string s50(75, '*');

	cout << boolalpha;

	cout << s50 << endl;
	cout << "copy (char* s, size_t n, size_t p = 0)" << endl;
	cout << R"([khrisha rao].copy("xxxxxxx", 7))" << "\t\t\t\t\t\t = ";
	cout << s.copy(buf, 7) << endl;
	cout << "result\t\t\t\t\t\t\t\t\t\t = ";
	cout << '"' << buf << '"' << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "find (const string& s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find([ rao]))" << "\t\t\t\t\t\t\t = ";
	cout << s.find(s3) << endl;
	cout << endl;

	cout << "find (const char* s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find(" rao"))" << "\t\t\t\t\t\t\t = ";
	cout << s.find(" rao") << endl;
	cout << endl;

	cout << "find (const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].find(" rao", 0, 4))" << "\t\t\t\t\t\t = ";
	cout << s.find(" rao", 0, 4) << endl;
	cout << endl;

	cout << "find (char c, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find('r'))" << "\t\t\t\t\t\t\t\t = ";
	cout << s.find('r') << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "rfind (const string& s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].rfind([ rao]))" << "\t\t\t\t\t\t\t = ";
	cout << s.rfind(s3) << endl;
	cout << endl;

	cout << "rfind (const char* s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].rfind(" rao"))" << "\t\t\t\t\t\t\t = ";
	cout << s.rfind(" rao") << endl;
	cout << endl;

	cout << "rfind (const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].rfind(" rao", string::npos, 4))" << "\t\t\t\t\t = ";
	cout << s.rfind(" rao", string::npos, 4) << endl;
	cout << endl;

	cout << "rfind (const char* s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].rfind('r'))" << "\t\t\t\t\t\t\t = ";
	cout << s.rfind('r') << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "find_first_of(const string& s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_of([ rao]))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_of(s3) << endl;
	cout << endl;

	cout << "find_first_of(const char* s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_of(" rao"))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_of(" rao") << endl;
	cout << endl;

	cout << "find_first_of(const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].find_first_of(" rao", 0, 4))" << "\t\t\t\t\t = ";
	cout << s.find_first_of(" rao", 0, 4) << endl;
	cout << endl;

	cout << "find_first_of(char c, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_of('r'))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_of('r') << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "find_last_of(const string& s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_of([ rao]))" << "\t\t\t\t\t\t = ";
	cout << s.find_last_of(s3) << endl;
	cout << endl;

	cout << "find_last_of(const char* s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_of(" rao"))" << "\t\t\t\t\t\t = ";
	cout << s.find_last_of(" rao") << endl;
	cout << endl;

	cout << "find_last_of(const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].find_last_of(" rao", string::npos, 4))" << "\t\t\t\t = ";
	cout << s.find_last_of(" rao", string::npos, 4) << endl;
	cout << endl;

	cout << "find_last_of(char c, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_of('r'))" << "\t\t\t\t\t\t\t = ";
	cout << s.find_last_of('r') << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "find_first_not_of(const string& s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_not_of([ rao]))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_not_of(s3) << endl;
	cout << endl;

	cout << "find_first_not_of(const char* s, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_not_of(" rao"))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_not_of(" rao") << endl;
	cout << endl;

	cout << "find_first_not_of(const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].find_first_not_of(" rao", 0, 4))" << "\t\t\t\t\t = ";
	cout << s.find_first_not_of(" rao", 0, 4) << endl;
	cout << endl;

	cout << "find_first_not_of(char c, size_t p = 0)" << endl;
	cout << R"([khrisha rao].find_first_not_of('r'))" << "\t\t\t\t\t\t = ";
	cout << s.find_first_not_of('r') << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "find_last_not_of(const string& s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_not_of([ rao]))" << "\t\t\t\t\t\t = ";
	cout << s.find_last_not_of(s3) << endl;
	cout << endl;

	cout << "find_last_not_of(const char* s, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_not_of(" rao"))" << "\t\t\t\t\t\t = ";
	cout << s.find_last_not_of(" rao") << endl;
	cout << endl;

	cout << "find_last_not_of(const char* s, size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].find_last_not_of(" rao", string::npos, 4))" << "\t\t\t\t = ";
	cout << s.find_last_not_of(" rao", string::npos, 4) << endl;
	cout << endl;

	cout << "find_last_not_of(char c, size_t p = npos)" << endl;
	cout << R"([khrisha rao].find_last_not_of('r'))" << "\t\t\t\t\t\t = ";
	cout << s.find_last_not_of('r') << endl;
	cout << s50 << endl;
	cout << endl;


	cout << s50 << endl;
	cout << "compare (const string& s)" << endl;
	cout << R"([khrisha rao].compare([khrisha]))" << "\t\t\t\t\t\t = ";
	cout << s.compare(s2) << endl;
	cout << endl;

	cout << "compare (size_t p, size_t n, const string& s)" << endl;
	cout << R"([khrisha rao].compare(7, 4, [ rao]))" << "\t\t\t\t\t\t = ";
	cout << s.compare(7, 4, s3) << endl;
	cout << endl;

	cout << "compare (size_t p, size_t n, const string& s, size_t sp, size_t  sn)" << endl;
	cout << R"([khrisha rao].compare(0, 4, [khrisha], 0, string::npos))" << "\t\t\t\t = ";
	cout << s.compare(0, 4, s2, 0, string::npos) << endl;
	cout << endl;

	cout << "compare (const char* s)" << endl;
	cout << R"([khrisha rao].compare("khrisha"))" << "\t\t\t\t\t\t = ";
	cout << s.compare("khrisha") << endl;
	cout << endl;

	cout << "compare (size_t p, size_t n, const char* s)" << endl;
	cout << R"([khrisha rao].compare(7, 4, " rao"))" << "\t\t\t\t\t\t = ";
	cout << s.compare(7, 4, " rao") << endl;
	cout << endl;

	cout << "compare (size_t p, size_t n, const char* s, size_t n)" << endl;
	cout << R"([khrisha rao].compare(0, 4, "khrisha", 5))" << "\t\t\t\t\t = ";
	cout << s.compare(0, 4, "khrisha", 5) << endl;
	cout << s50 << endl;
	cout << endl;

	cout << s50 << endl;
	cout << "substr (size_t p = 0, size_t n = npos)" << endl;
	cout << R"([khrisha rao].substr(0, 7))" << "\t\t\t\t\t\t\t = [";
	cout << s.substr(0, 7) << ']' << endl;
	cout << endl;
	cout << R"([khrisha rao].substr(8))" << "\t\t\t\t\t\t\t\t = [";
	cout << s.substr(8) << ']' << endl;
	cout << s50 << endl;
	cout << endl;

}
