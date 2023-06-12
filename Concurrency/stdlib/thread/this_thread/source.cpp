#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;


int main()
{
	{
		cout << "get_id() example" << endl;
		cout << "id:" << this_thread::get_id() << endl;
		cout << endl;
	}

	{
		cout << "yield example" << endl;
		cout << "yielding" << endl;
		this_thread::yield();
		cout << endl;
	}

	{
		cout << "sleep_for example" << endl;
		cout << "sleeping for 2 secs" << endl;
		this_thread::sleep_for(2s);
		cout << endl;
	}

	{
		cout << "sleep_until example" << endl;
		cout << "sleeping for 3 secs  from ";
		auto now = std::chrono::system_clock::now();
		auto in_time_t = chrono::system_clock::to_time_t(now);
		cout << put_time(std::localtime(&in_time_t), "%c");
		cout << endl;
		auto ts = now + 3s;
		this_thread::sleep_until(ts);
		now = std::chrono::system_clock::now();
		in_time_t = chrono::system_clock::to_time_t(now);
		cout << "current time:";
		cout << put_time(std::localtime(&in_time_t), "%c");
	}
}
