#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>

#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <vector>

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
}


int main()
{
	{
		promise<int> p;
		auto result = p.get_future();
		cout << "set_value example" << endl;
		thread t([](promise<int>& p)
		{
			cout << "thread starting threadid:" << this_thread::get_id() << endl;
			p.set_value(10 / 2);
			this_thread::sleep_for(1s);
			cout << "thread exiting threadid:" << this_thread::get_id() << endl;
		}, ref(p));
		result.wait();
		printresult(result);
		t.join();
		cout << endl;
	}

	{
		promise<int> p;
		auto result = p.get_future();
		cout << "set_value_at_thread_exit example" << endl;
		thread([](promise<int>& p)
		{
			cout << "thread starting threadid:" << this_thread::get_id() << endl;
			p.set_value_at_thread_exit(10 / 5);
			this_thread::sleep_for(1s);
			cout << "thread exiting threadid:" << this_thread::get_id() << endl;
		}, ref(p)).detach();
		result.wait();
		printresult(result);
		cout << endl;
	}


	{
		promise<int> p;
		auto result = p.get_future();
		cout << "set_exception example" << endl;
		thread t([](promise<int>& p)
		{
			cout << "thread starting threadid:" << this_thread::get_id() << endl;
			p.set_exception(make_exception_ptr<runtime_error>(runtime_error("div by 0")));
			this_thread::sleep_for(1s);
			cout << "thread exiting threadid:" << this_thread::get_id() << endl;
		}, ref(p));
		result.wait();
		printresult(result);
		t.join();
		cout << endl;
	}

	{
		promise<int> p;
		auto result = p.get_future();
		cout << "set_exception_at_thread_exit example" << endl;
		thread([](promise<int>& p)
		{
			cout << "thread starting threadid:" << this_thread::get_id() << endl;
			p.set_exception_at_thread_exit(make_exception_ptr<runtime_error>(runtime_error("div by 0")));
			this_thread::sleep_for(1s);
			cout << "thread exiting threadid:" << this_thread::get_id() << endl;
		}, ref(p)).detach();
		result.wait();
		printresult(result);
		cout << endl;
	}

}

