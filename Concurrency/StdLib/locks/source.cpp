#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>

using namespace std;

struct table
{
	table(int id) :id(id) {}
	int id;
	mutex m;
};

struct waiter
{
	waiter(int id) :id(id) {}
	int id;
	mutex m;
};

void assign_waiter(table &t, waiter &w)
{
	static mutex io_mutex;
	{
		lock_guard<mutex> lk(io_mutex);
		cout << "table " << t.id << " and waiter " << w.id << " are waiting for assignment" << endl;
	}

	{
		lock(t.m, w.m);
		lock_guard<mutex> lk1(t.m, adopt_lock);
		lock_guard<mutex> lk2(w.m, adopt_lock);
		{
			lock_guard<mutex> lk(io_mutex);
			cout << "table " << t.id << " and waiter " << w.id << " are assigned" << endl;
		}
		this_thread::sleep_for(3s);
		{
			lock_guard<mutex> lk(io_mutex);
			cout << "table " << t.id << "  clean up" << endl;
		}
	}
}

int main()
{
	table  t{ 1 }, t2{ 2 };
	waiter w{ 1 }, w2{ 2 };

	vector<thread> threads;
	threads.emplace_back(assign_waiter, ref(t), ref(w));
	threads.emplace_back(assign_waiter, ref(t2), ref(w));
	threads.emplace_back(assign_waiter, ref(t2), ref(w2));
	threads.emplace_back(assign_waiter, ref(t), ref(w2));

	for (auto &thread : threads) thread.join();

}