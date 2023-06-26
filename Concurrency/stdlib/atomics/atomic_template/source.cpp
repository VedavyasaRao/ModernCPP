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
			atomic<bool> lock;
			critical_section()
			{
				lock.store(false);
			}
			void acquire()
			{
				while (atomic_exchange_explicit(&lock, true, memory_order_acquire))
					this_thread::yield();
			}

			void release()
			{
				atomic_store_explicit(&lock, false, memory_order_release);
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

	{
		struct node
		{
			int data;
			node* next;
			node(const int& data) : data(data), next(nullptr) {}
		};

		struct stack
		{
			atomic<node*> head;
			stack()
			{
				head.store(nullptr);
			}

			void push(const int& data)
			{
				node* new_node = new node(data);

				// put the current value of head into new_node->next
				new_node->next = head.load(memory_order_relaxed);

				// now make new_node the new head, but if the head
				// is no longer what's stored in new_node->next
				// (some other thread must have inserted a node just now)
				// then put that new head into new_node->next and try again
				while (!atomic_compare_exchange_weak_explicit(
					&head,
					&new_node->next,
					new_node,
					memory_order_release,
					memory_order_relaxed))
					;
			}
		};

		auto f = [](int n, stack& s)
		{
			this_thread::sleep_for(chrono::milliseconds(rand()*n % 100));
			s.push(n);
		};



		stack s;
		vector<thread> v;
		for (int n = 0; n < 10; ++n)
		{
			v.emplace_back(f, n, ref(s));
		}

		for (auto& t : v)
		{
			t.join();
		}

		cout << "atomic_compare_exchange_weak_explicit demo" << endl;
		cout << "items in stack" << endl;
		for (auto h = s.head.load(); h != nullptr; h = h->next)
		{
			cout << h->data << " ";
		}
	}

}

