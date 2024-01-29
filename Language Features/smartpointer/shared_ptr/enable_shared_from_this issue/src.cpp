#include <iostream>
#include <memory>

using namespace std;

struct C
{
    shared_ptr<C> getptr()
    {
        return shared_ptr<C>(this);
    }
};
 
int main()
{
    shared_ptr<C> x = make_shared<C>();
    shared_ptr<C> y = x->getptr();
    cout << "x.use_count=" << x.use_count() << endl;
}