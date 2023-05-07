#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main()
{
	istringstream iss("Hello, Khri$ha!");
	
	cout << iss.rdbuf();
} 
 