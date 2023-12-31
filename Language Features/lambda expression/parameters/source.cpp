#include <iostream>
using namespace std;

int main()
{
	cout << R"([](const char * param))" << endl;
	[](const char *  param)
	{
		cout <<  param << endl;
	}("hello, world!");

}