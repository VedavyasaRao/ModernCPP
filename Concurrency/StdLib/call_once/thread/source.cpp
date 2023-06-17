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

using namespace std;
mutex io_mutex;
once_flag balance_init;
struct account
{
	account(string id) :id(id) {};
	string id;
	double balance;
	mutex m;
} 	sam_acct{ "sam" }, rob_acct{ "rob" }, steve_acct{ "steve" };


void initbalance(bool bthrow)
{
	{
		lock_guard<mutex> io(io_mutex);
		cout << "threadid: " << this_thread::get_id() << " enter initbalance()" << endl;
	}

	if (bthrow)
		throw exception();
	sam_acct.balance = 1000;
	rob_acct.balance = 100;
	steve_acct.balance = 200;

	{
		lock_guard<mutex> io(io_mutex);
		cout << "balance of " << sam_acct.id << " is " << sam_acct.balance << endl;
		cout << "balance of " << rob_acct.id << " is " << rob_acct.balance << endl;
		cout << "balance of " << steve_acct.id << " is " << steve_acct.balance << endl;
		cout << "threadid: " << this_thread::get_id() << " exit initbalance()" << endl;
		cout << endl;
	}
}



void transfer_funds(account &f, account &t, bool bthrow)
{
	try
	{
		call_once(balance_init, initbalance, bthrow);
	}
	catch (...)
	{
		return;
	}

	{
		lock_guard<mutex> io(io_mutex);
		cout << "threadid: " << this_thread::get_id() << " enter transfer_funds()" << endl;
		cout << "account " << f.id << " and account " << t.id << " are waiting for assignment" << endl;
	}

	{
		unique_lock<mutex> lk(f.m, defer_lock);
		unique_lock<mutex> lk2(t.m, defer_lock);
		lock(lk, lk2);
		{
			lock_guard<mutex> io(io_mutex);
			cout << endl;
			cout << "account " << f.id << " and account " << t.id << " are assigned" << endl;
			t.balance += 100;
			f.balance -= 100;
			cout << "balance of account " << f.id << " is  " << f.balance << endl;
			cout << "balance of account " << t.id << " is  " << t.balance << endl;
		}
		this_thread::sleep_for(chrono::seconds(3));
		{
			lock_guard<mutex> io(io_mutex);
			cout << "account " << f.id << " is free and account " << t.id << " is free" << endl;
			cout << "threadid: " << this_thread::get_id() << " exit transfer_funds()" << endl;
		}
	}
}

int main()
{
	thread a(transfer_funds, ref(sam_acct), ref(rob_acct), true);
	thread b(transfer_funds, ref(sam_acct), ref(steve_acct), false);
	a.join();
	thread c(transfer_funds, ref(sam_acct), ref(rob_acct), true);
	b.join();
	c.join();


}