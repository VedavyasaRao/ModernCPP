#include <mutex>
#include <thread>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>
#include <cstdlib>

using namespace std;

mutex m;
timed_mutex tm;
mutex w;
int counter = 1;
ostream off(cout.rdbuf());

void print(bool b, int counter)
{
	lock_guard<mutex> lw(w);
	cout << "Thread Id ";
	cout << setw(6) << setfill(' ') << this_thread::get_id();
	cout << "  ";
	if (b)
		cout << setw(2) << setfill('0') << counter;
	else
		off << "no lock";
	cout << endl;

}

void increment()
{
	unique_lock<mutex> l(m);
	for (int i = 0; i < 5; ++i)
	{
		l.unlock();
		this_thread::sleep_for(chrono::microseconds(rand() % 1000));
		l.lock();
		print(true, counter++);
	}
}

void increment2()
{
	unique_lock<mutex> l(m);
	bool b = true;
	while (counter <= 10)
	{
		if (b)
			l.unlock();
		this_thread::sleep_for(chrono::microseconds(rand() % 1000));
		b = l.try_lock();
		if (b)
			print(b, counter++);
		else
			print(b, counter);
	}

}

void increment3()
{
	unique_lock<timed_mutex> l(tm);
	bool b = true;
	while (counter <= 10)
	{
		if (b)
			l.unlock();
		b = l.try_lock_for(chrono::microseconds(rand() % 1000));
		if (b)
			print(b, counter++);
		else
			print(b, counter);
	}
}


int main()
{
	{
		cout << endl << "lock() demo" << endl << endl;
		vector<thread> threads;
		threads.emplace_back(increment);
		threads.emplace_back(increment);
		for (auto &thread : threads) thread.join();
	}

	{
		cout << endl << "try_lock() demo" << endl << endl;
		vector<thread> threads;
		counter = 1;
		threads.emplace_back(increment2);
		threads.emplace_back(increment2);
		for (auto &thread : threads) thread.join();
	}

	{

		cout << endl << "try_lock_for() demo" << endl << endl;
		vector<thread> threads;
		counter = 1;
		threads.emplace_back(increment3);
		threads.emplace_back(increment3);
		for (auto &thread : threads) thread.join();
	}
}