#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>
#include <exception>
#include <stdexcept>
#include <future>
#include <condition_variable>

using namespace std;
mutex io_mutex;
condition_variable cv;
mutex cv_mutex;
string message;
using namespace std;

void receiver()
{
	while (true)
	{
		unique_lock<mutex> lk(cv_mutex);
		cv.wait(lk);
		{
			lock_guard<mutex> io(io_mutex);
			if (message == "")
			{
				cout << this_thread::get_id() << ": exiting" << endl;
				break;
			}
			cout << this_thread::get_id() << ": received message " << message << endl;
		}
	}
}


int main()
{
	thread a(receiver), b(receiver), c(receiver);
	this_thread::sleep_for(chrono::seconds(1));
	{
		lock_guard<mutex> lk(cv_mutex);
		message = "hello,";
		cv.notify_all();
	}
	this_thread::sleep_for(chrono::seconds(1));
	{
		lock_guard<mutex> lk(cv_mutex);
		message = "Khrisha!";
		cout << endl ;
		cv.notify_all();
	}
	this_thread::sleep_for(chrono::seconds(1));
	{
		lock_guard<mutex> lk(cv_mutex);
		message = "";
		cout << endl;
		cv.notify_all();
	}

	a.join();
	b.join();
	c.join();
}
