#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using namespace chrono;

std::timed_mutex test_mutex;

void f()
{
	cout << "worker thread:waiting  on mutex for 5 seconds" << endl;
	auto b = test_mutex.try_lock_for(chrono::seconds(5));
    if (b)
	   cout << "worker thread:hello world" << endl;
	test_mutex.unlock();
}

int main()
{
	cout << "main thread:owning mutex" << endl;
	test_mutex.lock();
	cout << "main thread:creating worker thread" << endl;
	thread t(f);
	this_thread::sleep_for(500ms);
	cout << "main thread:sleeping for 3 seconds" << endl;
	this_thread::sleep_for(3s);
	cout << "main thread:unlocking mutex" << endl;
	test_mutex.unlock();
	t.join();
}