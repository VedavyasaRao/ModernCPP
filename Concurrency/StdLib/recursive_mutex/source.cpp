#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using namespace chrono;

recursive_mutex test_mutex;

void create_table()
{
	test_mutex.lock();
	cout << "creating table" << endl;
	test_mutex.unlock();
}

void insert_data()
{
	test_mutex.lock();
	cout << "inserting data" << endl;
	test_mutex.unlock();
}

void create_table_and_insert_data()
{
	test_mutex.lock();
	cout << "creating table" << endl;
	insert_data();
	test_mutex.unlock();
}

int main()
{
	cout << "create table A" << endl;
	create_table();
	cout << "insert data to table A" << endl;
	insert_data();
	cout << "create table B and insert data" << endl;
	create_table_and_insert_data();

}