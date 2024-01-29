#include <iostream>
#include <string>
#include <cassert>
#include <memory>
#include <future>
#include <chrono>

using namespace std;

struct offer
{
    string name;
    chrono::seconds validity;
    void print() {cout << "offer\t\t:" << name << "\nvalidity\t:" << validity.count() << " seconds"<< endl;}
};

void offermanager(shared_ptr<offer>& sp)
{
    this_thread::sleep_for(sp->validity);
    sp.reset();
    cout << "offermanager thread:\toffer expired" << endl;
}


void fulfill(weak_ptr<offer> wp)
{
    this_thread::sleep_for(chrono::seconds(5));
    auto sp = wp.lock();
    if (wp.expired())
    {
        cout << "fulfill thread:\toffer expired" << endl;
        return;
    }
    cout << "fulfill thread:\toffer fulfilled" << endl;
}


shared_ptr<offer> sp (new offer{"sfo-blr\t100 usd",chrono::seconds(8)});
int main()
{
    
    cout << "main thread:" <<  endl;
    {    
        cout << "starting offer manager" << endl;
        sp->print();
        cout << endl;
        this_thread::sleep_for(100ms);
        thread(offermanager,ref(sp)).detach();
    }
    
    {    
        cout << "calling fulfill 1st time" << endl;
        weak_ptr<offer> wp = sp;
        auto f = async(launch::deferred,fulfill,wp);
        f.wait();
    }
    
    cout << endl;
    {
        cout << "calling fulfill  2nd time" << endl;
        weak_ptr<offer> wp = sp;
        auto f = async(launch::deferred,fulfill,wp);
        f.wait();
    }

    
    return 0;
}