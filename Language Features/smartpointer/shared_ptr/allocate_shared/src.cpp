#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct C
{
    // constructors needed (until C++20)
    C(int i) : i(i) {}
    C(int i, float f) : i(i), f(f) {}
    int i;
    float f{};
};
 
int main()
{
    cout << "auto sp1 = make_shared<C>(1)" << endl;
    auto sp1 = make_shared<C>(1);
    cout << "sp1\t\t= C{ i:" << sp1->i << ", f:" << sp1->f << " }" << endl;
    cout << endl;
    
    cout << "shared_ptr<C> sp2 = make_shared<C>(2, 3.0f)" << endl;
    shared_ptr<C> sp2 = make_shared<C>(2, 3.0f);
    cout << "sp2\t\t= C{ i:" << sp2->i << ", f:" << sp2->f << " }" << endl;
    cout << endl;

    cout << "auto sp3 = make_shared<int>(20)" << endl;
    auto sp3 = make_shared<int>(20);
    cout << "*sp3\t\t= " << *sp3 << endl;
    cout << endl;
    
    cout << "auto sp4 = make_shared<vector<int>>(30)" << endl;
    auto sp4 = make_shared<vector<int>>(30);
    cout << "sp4->size()\t = " << sp4->size() << endl;
    cout << endl;

}