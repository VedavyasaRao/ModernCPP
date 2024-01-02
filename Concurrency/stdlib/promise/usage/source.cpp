#include <iostream>
#include <future>
#include <thread>
#include <system_error>

using namespace std;

void doubler(int n,promise<int>& p)
{

    if (n < 0)
        p.set_exception(make_exception_ptr(runtime_error("no negative number")));
    else
        p.set_value(n*2);
}

void print_result(promise<int>& p)
{
    try
    {
        auto ret = p.get_future().get();
        cout << "doubler(10)=\t\t" << ret << endl;
    }
    catch(const exception& e)
    {
        cout << "exception caught:\t" << e.what() << endl;
    }
    
}

int main()
{
    {
        promise<int> p;
        thread {doubler,10, ref(p)}.detach();
        print_result(p);
    }

    {
        promise<int> p;
        thread {doubler,-10, ref(p)}.join();
        print_result(p);
    }
}
