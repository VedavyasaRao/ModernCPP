#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

void handlemanipulator(ostream& os, const string& token)
{
	if (token == "endl")
		os << endl;
	else if (token == "showbase")
		os << showbase;
	else if (token == "boolalpha")
		os << boolalpha;
	else if (token == "noboolalpha")
		os << noboolalpha;
	else if (token == "showpos")
		os << showpos;
	else if (token == "noshowpos")
		os << noshowpos;
	else if (token == "uppercase")
		os << uppercase;
	else if (token == "nouppercase")
		os << nouppercase;
	else if (token == "oct")
		os << oct;
	else if (token == "dec")
		os << dec;
	else if (token == "hex")
		os << hex;
	else if (token == "noshowpos")
		os << noshowpos;
	else if (token == "showpoint")
		os << showpoint;
	else if (token == "fixed")
		os << fixed;
	else if (token == "scientific")
		os << scientific;
	else if (token == "hexfloat")
		os << hexfloat;
	else if (token == "defaultfloat")
		os << defaultfloat;
	else if (token == "left")
		os << left;
	else if (token == "right")
		os << right;
	else if (token == "internal")
		os << internal;
	else if (token.find("setprecision") != string::npos)
		os.precision(stoi(token.substr(13, token.find(')') - 13)));
	else if (token.find("setw") != string::npos)
		os.width(stoi(token.substr(5, token.find(')') - 5)));
	else if (token.find("put_money ") != string::npos)
		os.width(stoi(token.substr(10, token.find(')') - 10)));
	else if (token.find("setfill") != string::npos)
		os.fill(token.substr(token.find('\''))[1]);
	else
		os << token;
}

void handleformat(ostream& os, const char * format)
{
	string formats(format);
	size_t p = 0, p2 = 0;
	while (p2 != string::npos)
	{
		p2 = formats.find(',', p);
		auto token = formats.substr(p, p2 - p);
		handlemanipulator(os, token);
		p = p2 + 1;
	}
}

template<class T>
void process(ostream& os, T t)
{
	os << t;
}

template<class T>
void process(ostream& os, const pair<T, char const *>& t)
{
	handleformat(os, t.second);
	os << t.first;
}

void smartprint(ostream&) {}

template<typename T, typename... Ts>
void smartprint(ostream& os, T t, Ts... ts)
{
	process(os, t);
	// “ts” is its pattern
	// “ts...” is  pack expansion
	smartprint(os, ts...);
}

int main()
{
    time_t t = std::time(nullptr);
    tm tm = *localtime(&t);
    long m = 123456;
    double h = 1.56795;
    const char * ssn ="123";
 
    cout.imbue(locale("en_US.UTF-8"));
	cout << R"z(	smartprint(cout, 
        "Citizen\t\t\t:", make_pair(true, "boolalpha"), 
        "\nheight(meters)\t\t:", make_pair(h, "fixed,setprecision(3)"),
        "\nincome\t\t\t:", make_pair(put_money(m),  "showbase"),
        "\nSocial Security number\t:", make_pair(ssn, "left,setw(8),setfill('#'),showbase"),
        "\ntime stamp\t\t:", put_time(&tm, "%c %Z"),
        "\n"))z" << endl << endl;

	smartprint(cout, 
        "Citizen\t\t\t:", make_pair(true, "boolalpha"), 
        "\nheight(meters)\t\t:", make_pair(h, "fixed,setprecision(3)"),
        "\nincome\t\t\t:", make_pair(put_money(m),  "showbase"),
        "\nSocial Security number\t:", make_pair(ssn, "left,setw(8),setfill('#'),showbase"),
        "\ntime stamp\t\t:", put_time(&tm, "%c %Z"),
        "\n");
 

}