#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>

using namespace std;

struct account
{
	account(string id, double bal) :id(id), balance(bal) {};
	string id;
	double balance;
	mutex m;
};


void transfer_funds(account &f, account &t)
{
	static mutex io_mutex;
	{
		lock_guard<mutex> io(io_mutex);
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
        
		this_thread::sleep_for(3s);
        
		{
			lock_guard<mutex> io(io_mutex);
			cout << "account " << f.id << " is free and account " << t.id << " is free" << endl;

		}
	}
}

int main()
{
	account sam_acct{ "sam",1000 }, rob_acct{ "rob", 100 }, steve_acct{ "steve", 50 };

	cout << "balance of " << sam_acct.id << " is " << sam_acct.balance << endl;
	cout << "balance of " << rob_acct.id << " is " << rob_acct.balance << endl;
	cout << "balance of " << steve_acct.id << " is " << steve_acct.balance << endl;
	cout << endl;

	vector<thread> threads;
	threads.emplace_back(transfer_funds, ref(sam_acct), ref(rob_acct));
	threads.emplace_back(transfer_funds, ref(sam_acct), ref(steve_acct));

	for (auto &thread : threads) thread.join();

}