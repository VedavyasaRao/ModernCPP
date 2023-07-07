#include <future>
#include <thread>
#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <mutex>

using namespace std;
using namespace std::chrono;

#define  MAX_COUNTER 25
#define  MAX_THREADS 3
int counter = 1;
mutex m;
void ConsoleWriterFunction()
{

	while (true)
	{
		if (counter > MAX_COUNTER)
			break;
        m.lock();
		cout << "Thread Id ";
		cout << setw(6) << setfill(' ') << this_thread::get_id();
		cout << ": Value = ";
		cout << setw(2) << setfill('0') << counter++;
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(5));
        m.unlock();
	}
}

int main()
{
	auto start_time = system_clock::now();

	thread  workers[MAX_THREADS];

	for (int i = 0; i < MAX_THREADS; ++i)
	{
		workers[i] = thread(ConsoleWriterFunction);
	}


	for (int i = 0; i < MAX_THREADS; ++i)
	{
		workers[i].join();
	}
	auto dur = duration_cast<chrono::milliseconds>(system_clock::now() - start_time).count();
	cout << endl << "Elapsed Time = " << dur << " MilliSeconds" << endl;

}