#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;



int main()
{

	{
		struct critical_section
		{
			atomic_flag lock = ATOMIC_FLAG_INIT;
			critical_section()
			{
			}
			void acquire()
			{
				while (lock.test_and_set(memory_order_acquire))
					this_thread::yield();
			}

			void release()
			{
				lock.clear(memory_order_release);
			}

		} lock;

		mutex iom;

		cout << "load,store and atomic_exchange_explicit demo" << endl;

		auto  f = [&lock, &iom](int n)
		{
			auto tid = this_thread::get_id();
			{
				lock_guard<mutex> l(iom);
				cout << endl << "Thread Id:" << tid << " waiting " << endl;
			}
			lock.acquire();
			{
				lock_guard<mutex> l(iom);
				cout << endl << "Thread Id:" << tid << " acquiring " << endl;
			}
			this_thread::sleep_for(chrono::milliseconds(rand()*n % 100));

			{
				lock_guard<mutex> l(iom);
				cout << "Thread Id:" << tid << " releaseing" << endl;
			}
			lock.release();
		};

		vector<thread> v;
		for (int n = 0; n < 5; ++n)
		{
			v.emplace_back(f, n);
		}
		for (auto& t : v)
		{
			t.join();
		}
	}
	cout << endl;
}

