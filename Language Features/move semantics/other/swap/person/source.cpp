#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
struct Person
{
	Person()
	{
		cout << "default constructor" << endl;
	}

	Person(const string& fullname, const short& yob)
	{
		this->fullname = fullname;
		this->yob = yob;
		cout << "memberwise constructor:" << fullname << " " << yob << endl;
	}


	Person(const Person& p)
	{
		fullname = p.fullname;
		yob = p.yob;
		cout << "copy constructor(&):" << fullname << " " << yob << endl;
	}

	Person& operator=(const Person& p)
	{
		fullname = p.fullname;
		yob = p.yob;
		cout << "operator=(&):" << fullname << " " << yob << endl;
		return *this;
	}

	Person(Person&& p)
	{
		fullname = move(p.fullname);
		yob = p.yob;
		*this = move(p);
		cout << "copy constructor(&&):" << fullname << " " << yob << endl;
	}

	Person& operator=(Person&& p)
	{
		fullname = move(p.fullname);
		yob = p.yob;
		cout << "operator=(&&):" << fullname << " " << yob << endl;
		return *this;
	}


	string fullname;
	short yob;

};

int main()
{
	cout << "build" << endl;
	Person p{ "in",1643 };
	Person p2{ "wr",1845 };
	cout << endl;

	cout << "swap - no move" << endl;
	Person tmp = p;
	p = p2;
	p2 = tmp;
	cout << endl;

	cout << "swap - move" << endl;
	Person tmp2 = move(p);
	p = move(p2);
	p2 = move(tmp);
	cout << endl;
}