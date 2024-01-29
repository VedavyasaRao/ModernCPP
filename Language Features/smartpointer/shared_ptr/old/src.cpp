#include <iostream>
#include <string>
#include <cassert>
#include <memory>
#include <future>
using namespace std;
using namespace std::chrono_literals;

void tfunc(shared_ptr<int> sp)
{
    this_thread::sleep_for(500ms);
    cout << "child thread:"  << endl;
    cout << "get():" << *sp.get() << endl;
    cout << "use_count:" << sp.use_count() << endl;
}

int main()
{
    shared_ptr<int> sp (new int(42), [](int *){cout << "deleter..." << endl;});
    cout << "main thread:" <<  endl;
    cout << "get():" << *sp.get() << endl;
    cout << "calling async()" << endl;
    auto f = async(launch::deferred, tfunc, sp);
    cout << "use_count before reset:" << sp.use_count() << endl;
    sp.reset();
    cout << "use_count after:" << sp.use_count() << endl;
    f.wait();
    return 0;
}
