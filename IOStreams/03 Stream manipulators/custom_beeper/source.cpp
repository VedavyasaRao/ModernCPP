#include <windows.h>
#include <iostream>

std::istream &beep(std::istream &iss)
{
	Beep(523, 800);
	return iss;
}

std::ostream &beep(std::ostream &oss)
{
	Beep(523, 800);
	return oss;
}

int main()
{
	using namespace std;

	int a;
	cout << "enter a number" << endl;
	cin >> beep >> a;
	if (!cin)
		cerr << "bad input" << beep << endl;
	else
		cout << "the number is " << a;
}