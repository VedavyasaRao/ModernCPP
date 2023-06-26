#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;


void printresult(future<int>&  result)
{
	cout << boolalpha;
	cout << "is valid:" << result.valid() << endl;
	try
	{
		cout << "result:" << result.get() << endl;
	}
	catch (const exception& e)
	{
		cout << "exception:" << e.what() << endl;
	}
	cout << "is valid:" << result.valid() << endl;
	cout << endl;
}

void printstatus(const future_status& status)
{
	switch (status)
	{
	case future_status::deferred: cout << "status:deferred"; break;
	case future_status::timeout: cout << "status:timeout"; break;
	case future_status::ready: cout << "status:ready!"; break;
	}
	cout << endl;
}

int main()
{

	{
		cout << "get() - value example" << endl;
		auto result = async([]() {return 10 / 2; });
		printresult(result);
	}

	{
		cout << "get() - exception example" << endl;
		auto result = async([]() {throw runtime_error("div by 0"); return 0; });
		printresult(result);
	}

	{
		cout << "wait() example" << endl;
		auto result = async([]() {return 21; });
		result.wait();
		printresult(result);
	}

	{
		cout << "wait_for() example" << endl;
		future<int> result = async(launch::async, []()
		{
			this_thread::sleep_for(3s);
			return 9;
		});

		printstatus(result.wait_for(1s));
		printstatus(result.wait_for(3s));
		printresult(result);
	}

	{
		cout << "wait_until() example" << endl;
		std::chrono::system_clock::time_point two_seconds_passed
			= std::chrono::system_clock::now() + std::chrono::seconds(2);
		future<int> result = async(launch::async, []()
		{
			this_thread::sleep_for(3s);
			return 18;
		});

		printstatus(result.wait_until(two_seconds_passed));
		printstatus(result.wait_until(two_seconds_passed));
		printresult(result);
	}

	{
		cout << "share example" << endl;
		auto result = async([]() {return 20; });
		auto result2 = result.share();
		cout << "is valid result:" << result.valid() << endl;
		cout << "is valid result2:" << result2.valid() << endl;
	}

}
