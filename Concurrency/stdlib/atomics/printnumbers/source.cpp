#include <future>
#include <thread>
#include <iostream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <mutex>
#include <chrono>


using namespace std;
using namespace std::chrono;

#define  MAX_COUNTER 25
#define  MAX_THREADS 3
//atomic_int counter = 1;
int counter = 1;
mutex iom;

void printnumber(int kounter)
{
    lock_guard lk(iom);
	cout << "Thread Id ";
	cout << setw(6) << setfill(' ') << this_thread::get_id();
	cout << ": Value = ";
	cout << setw(2) << setfill('0') << kounter;
	cout << endl;
    
}
void ConsoleWriterFunction()
{

	while (true)
	{
		if (counter > MAX_COUNTER)
			break;
        printnumber(counter++);
		this_thread::sleep_for(chrono::milliseconds(5));
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
