#include <iostream>
#include <string>
#include <cassert>
#include <memory>
#include <future>
using namespace std;
using namespace std::chrono_literals;

void tfunc(weak_ptr<int> wp)
{
    this_thread::sleep_for(500ms);
    cout << "child thread:"  << endl;
    auto sp = wp.lock();
    if (wp.expired())
    {
        cout << "expired" << endl;
        return;
    }
    cout << "get():" << *sp.get() << endl;
    cout << "use_count:" << wp.use_count() << endl;
}

int main()
{
    shared_ptr<int> sp (new int(42), [](int *){cout << "deleter..." << endl;});
    cout << "main thread:" <<  endl;
    cout << "get():" << *sp.get() << endl;
    cout << endl;
    
    {    
        cout << "calling async() 1st time" << endl;
        weak_ptr<int> wp = sp;
        auto f = async(launch::deferred, tfunc,wp);
        f.wait();
    }
    cout << endl;
    {
        cout << "calling async()  2nd time" << endl;
        weak_ptr<int> wp = sp;
        auto f = async(launch::deferred, tfunc,wp);
        cout << "resetting" << endl;
        sp.reset();
        f.wait();
    }

    
    return 0;
}