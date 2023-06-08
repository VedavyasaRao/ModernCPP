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
		cout << "async(launch::async) -  value example" << endl;
		auto result = async(launch::async, []() {return 10 / 2; });
		printstatus(result.wait_for(2s));
		printresult(result);
	}

	{
		cout << "async(launch::async) -  exception example" << endl;
		auto result = async(launch::async, []() {throw runtime_error("overflow"); return 0; });
		printstatus(result.wait_for(2s));
		printresult(result);
	}

	{
		cout << "async(launch::deferred) -  value example" << endl;
		auto result = async(launch::deferred, []() {return 10 / 5; });
		printstatus(result.wait_for(2s));
		printresult(result);
	}

	{
		cout << "async(launch::deferred) -  exception example" << endl;
		auto result = async(launch::deferred, []() {throw runtime_error("underflow"); return 0; });
		printstatus(result.wait_for(2s));
		printresult(result);
	}

}