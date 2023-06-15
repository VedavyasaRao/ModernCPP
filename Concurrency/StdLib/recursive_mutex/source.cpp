#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using namespace chrono;

recursive_mutex test_mutex;

void create_table_withoutdata()
{
	test_mutex.lock();
	cout << "creating table without data" << endl;
	test_mutex.unlock();
}

void insert_data()
{
	test_mutex.lock();
	cout << "inserting data" << endl;
	test_mutex.unlock();
}

void create_table_withdata()
{
	test_mutex.lock();
	cout << "creating table with data" << endl;
	insert_data();
	test_mutex.unlock();
}

int main()
{
	cout << "create table A" << endl;
	create_table_withoutdata();
	cout << "insert data to table A" << endl;
	insert_data();
	cout << "create table B and insert data" << endl;
	create_table_withdata();

}