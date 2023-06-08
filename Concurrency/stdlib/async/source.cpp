#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define BUF_SIZE 255
#define  MAX_COUNTER 25
#define  MAX_THREADS 1
int counter = 1;

void ConsoleWriterFunction()
{
	while (true)
	{
		if (counter > MAX_COUNTER)
			break;
		cout << "Thread Id " << this_thread::get_id() << ": Value = " << counter++ << endl;
		this_thread::sleep_for(chrono::milliseconds(5));
	}
}

int main()
{
	auto start_time = system_clock::now();

	std::future<void>  workers[MAX_THREADS];

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		workers[i] = async(launch::async,ConsoleWriterFunction);
	}


	for (int i = 0; i < MAX_THREADS; ++i)
	{
		workers[i].wait();
	}
	auto dur = duration_cast<chrono::milliseconds>(system_clock::now() - start_time).count();
	cout << endl << "Elapsed Time = " << dur << " MilliSeconds" << endl;

}
