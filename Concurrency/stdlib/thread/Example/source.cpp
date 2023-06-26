#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;


int main()
{
	{
		cout << "get_id() example" << endl;
		cout << "native_handle() example" << endl;
		cout << "join() example" << endl;
		cout << "hardware_concurrency() example" << endl;
		cout << endl;
		cout << "hardware_concurrency:" << thread::hardware_concurrency() << endl;
		cout << "starting thread" << endl;
		thread t([]() {});
		cout << "id: " << t.get_id() << endl;
		cout << "native handle: " << t.native_handle() << endl;
		cout << "waiting for thread completion" << endl;
		t.join();
		cout << "thread ended" << endl;
		cout << endl;
	}

	{
		cout << "detach() example" << endl;
		cout << endl;
		promise<void> p;
		auto f = p.get_future();
		cout << "starting thread" << endl;
		thread([](promise<void> p)
		{
			p.set_value();
		}, move(p)).detach();
		cout << "thread detached" << endl;
		f.wait();
		cout << "thread ended" << endl;
		cout << endl;
	}
}
