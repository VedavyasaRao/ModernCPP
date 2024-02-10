#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

struct Greet
{
    void operator()()
    {
        time_t curr_time;
	    curr_time = time(NULL);

        tm *tm_local = localtime(&curr_time);
        size_t h = tm_local->tm_hour;
        cout << "Hello, ";

        if (h > 4 && h < 12)
            cout << "Good Morning";
        else if (h > 11 && h < 17)
            cout << "Good Afternnon";
        else if (h > 16 )
            cout << "Good Evening";
        cout << "!" << endl;
    }        
} g;
int main()
{
    g();
}