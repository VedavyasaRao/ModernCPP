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
		cout << "packaged_task -  value example" << endl;
		auto ptask = packaged_task<int(int, int)>([](int a, int b) 
		{
			return a / b; 
		});
		auto result = ptask.get_future();
		ptask(10, 5);
		printstatus(result.wait_for(2s));
		printresult(result);

		cout << "packaged_task -  reset() example" << endl;
		ptask.reset();
		result = ptask.get_future();
		ptask(10, 2);
		printstatus(result.wait_for(2s));
		printresult(result);

	}

	{
		cout << "packaged_task -  exception example" << endl;
		cout << "packaged_task -  valid() example" << endl;
		auto ptask = packaged_task<int()>([]()
		{
			throw runtime_error("overflow");
			return 0;
		});
		cout << "function valid:" << ptask.valid() << endl;
		auto result = ptask.get_future();
		ptask();
		printstatus(result.wait_for(2s));
		printresult(result);
	}

	{
		cout << "packaged_task -  make_ready_at_thread_exit() example" << endl;
		auto worker = [](future<int>& f)
		{
			cout << "worker thread start" << endl;
			auto ptask = packaged_task<int(int, int)>([](int a, int b)
			{
				return a / b;
			});
			auto result = ptask.get_future();
			ptask.make_ready_at_thread_exit(10, 1);
			printstatus(result.wait_for(0s));
			f = move(result);
			cout << "worker thread end" << endl;
		};
		future<int> result;
		async(worker, ref(result)).wait();
		printstatus(result.wait_for(0s));
		printresult(result);
	}
}