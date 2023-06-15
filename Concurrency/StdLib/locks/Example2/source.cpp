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
		lock_guard<mutex> lk(io_mutex);
		cout << "account " << f.id << " and account " << t.id << " are waiting for assignment" << endl;
	}

	{
		unique_lock<mutex> lk(f.m, defer_lock);
		unique_lock<mutex> lk2(t.m, defer_lock);
		lock(lk, lk2);
		{
			lock_guard<mutex> lk(io_mutex);
			cout << endl;
			cout << "account " << f.id << " and account " << t.id << " are assigned" << endl;
			t.balance += 100;
			f.balance -= 100;
			cout << "balance of account " << f.id << " is  " << f.balance << endl;
			cout << "balance of account " << t.id << " is  " << t.balance << endl;
		}
		this_thread::sleep_for(3s);
		{
			lock_guard<mutex> lk(io_mutex);
			cout << "account " << f.id << " is free and account " << t.id << " is free" << endl;

		}
	}
}

int main()
{
	account govt_acct{ "sam",1000 }, beneficiary_acct{ "rob", 100 }, beneficiary_acct2{ "steve", 50 };

	cout << "balance of " << govt_acct.id << " is " << govt_acct.balance << endl;
	cout << "balance of " << beneficiary_acct.id << " is " << beneficiary_acct.balance << endl;
	cout << "balance of " << beneficiary_acct2.id << " is " << beneficiary_acct2.balance << endl;
	cout << endl;

	vector<thread> threads;
	threads.emplace_back(transfer_funds, ref(govt_acct), ref(beneficiary_acct));
	threads.emplace_back(transfer_funds, ref(govt_acct), ref(beneficiary_acct2));

	for (auto &thread : threads) thread.join();

}