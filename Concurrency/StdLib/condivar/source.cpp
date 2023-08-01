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
#include <iomanip>

using namespace std;
mutex io_mutex;
condition_variable cv;
mutex cv_mutex;
string message;
using namespace std;

void receiver()
{
	{
		lock_guard<mutex> lk(cv_mutex);
		cout << setw(6)  << this_thread::get_id();
		cout << ": starting" << endl;
	}

	while (true)
	{
		unique_lock<mutex> lk(cv_mutex);
		cv.wait(lk);
		{
			lock_guard<mutex> io(io_mutex);
			if (message.empty())
				break;
			cout << setw(6) << this_thread::get_id();
			cout << ": received message " << message << endl;
		}
	}
	lock_guard<mutex> io(io_mutex);
	cout << setw(6) << this_thread::get_id();
	cout << ": exiting" << endl;
}

void receiver2(bool &bnewmsg)
{
	{
		lock_guard<mutex> lk(cv_mutex);
		cout << setw(6) << this_thread::get_id();
		cout << ": starting" << endl;
	}

	while (true)
	{
		unique_lock<mutex> lk(cv_mutex);
		cv.wait(lk, [&]() {return bnewmsg; });
		{
			bnewmsg = false;
			if (message == "quit")
				break;

			lock_guard<mutex> io(io_mutex);
			cout << setw(6) << this_thread::get_id();
			cout << ": received message " << message << endl;
		}
	}
	lock_guard<mutex> io(io_mutex);
	cout << setw(6) << this_thread::get_id();
	cout << ": exiting" << endl;
}

void receiver3()
{
	{
		lock_guard<mutex> lk(cv_mutex);
		cout << setw(6) << this_thread::get_id();
		cout << ": starting" << endl;
	}

	while (true)
	{
		unique_lock<mutex> lk(cv_mutex);
		bool timeout(cv.wait_for(lk, chrono::seconds(3)) == cv_status::timeout);
		{
			lock_guard<mutex> io(io_mutex);
			cout << setw(6) << this_thread::get_id();
			if (timeout)
			{
				cout << ": timeout" << endl;
				break;
			}
			else
				cout << ": received message " << message << endl;
		}
	}
	lock_guard<mutex> io(io_mutex);
	cout << setw(6) << this_thread::get_id();
	cout << ": exiting" << endl;
}

int main()
{
	{
		cout << "wait() demo" << endl << endl;
		thread a(receiver), b(receiver);
		this_thread::sleep_for(chrono::seconds(1));
		{
			cout << endl;
			lock_guard<mutex> lk(cv_mutex);
			message = "hello,";
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lk(cv_mutex);
			message = "Khrisha!";
			cout << endl;
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
	}

	{
		message = "";
		cout << endl << endl;
		cout << "wait(cb) demo" << endl << endl;
		bool ba = false, bb = false;
		thread a(receiver2, ref(ba)), b(receiver2, ref(bb));
		this_thread::sleep_for(chrono::seconds(1));
		{
			cout << endl;
			lock_guard<mutex> lk(cv_mutex);
			ba = true;
			bb = true;
			message = "hello,";
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lk(cv_mutex);
			message = "Khrisha!";
			ba = true;
			bb = true;
			cout << endl;
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lk(cv_mutex);
			message = "";
			ba = true;
			bb = true;
			cout << endl;
			cout << "spurious wakeup" << endl;
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lk(cv_mutex);
			message = "quit";
			ba = true;
			bb = true;
			cout << endl;
			cv.notify_all();
		}

		a.join();
		b.join();
	}

	{
		message = "";
		cout << endl << endl;
		cout << "wait_for() demo" << endl << endl;
		thread a(receiver3), b(receiver3);
		this_thread::sleep_for(chrono::seconds(1));
		{
			cout << endl;
			lock_guard<mutex> lk(cv_mutex);
			message = "hello,";
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lk(cv_mutex);
			message = "Khrisha!";
			cout << endl;
			cv.notify_all();
		}
		this_thread::sleep_for(chrono::seconds(1));
		cout << endl;

		a.join();
		b.join();
	}

}
