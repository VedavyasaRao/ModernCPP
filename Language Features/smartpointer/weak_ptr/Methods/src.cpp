#include <iostream>
#include <memory>
#include <vector>

using namespace std;


 
int main()
{
    shared_ptr<int> x(new int(20));
    //create weak_ptr from shared_ptr
    weak_ptr<int> w;
    cout << "Before assignment" << endl;
    cout << "use_count \t= " << w.use_count() << endl;
    cout << boolalpha << "expired() \t= " << w.expired() << endl;
    cout << endl;
    w = x;
    cout << "After assignment" << endl;
    cout << "use_count \t= " << w.use_count() << endl;
    cout << boolalpha << "expired() \t= " << w.expired() << endl;
    cout << endl;
    cout << "After lock" << endl;
    //check if weak_ptr is valid
    if (!w.expired())
    {
        //generate new shared_ptr and use it if it's valid
        if (auto sp = w.lock()) 
        {
            cout << "*sp \t\t= " << *sp << endl;
            cout << "use_count \t= " << w.use_count() << endl;
            cout << boolalpha << "expired() \t= " << w.expired() << endl;
        }
    }

    cout << endl;
    cout << "After reset" << endl;
    w.reset();
    cout << "use_count \t= " << w.use_count() << endl;
    cout << boolalpha << "expired() \t= " << w.expired() << endl;
    cout << endl;

    shared_ptr<int> y(x, new int(10));
    w = x;
    weak_ptr<int> w2(y);
    cout << "owner_before() demo" << endl;
    {
        auto sp = w.lock();
        auto sp2 = w2.lock();
        cout << "*x\t\t\t= " << *x << endl;
        cout << "*w2.lock()\t\t= " << *w2.lock() << endl;
        cout << "x < y\t\t\t= " << (w.lock() < w2.lock()) << endl;
        cout << "w2.owner_before(x)\t= " << w2.owner_before(x) << endl;
    }
}