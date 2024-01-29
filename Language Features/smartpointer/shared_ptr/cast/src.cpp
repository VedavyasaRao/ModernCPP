#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct base {virtual ~base() {}} b;
struct derived:public base {virtual ~derived() {}} d;

 
int main()
{
    cout << "sp = make_shared<derived>()" << endl;
    auto sp = make_shared<derived>();
    cout << "type of *sp\t= " << typeid(*sp).name() << endl;
    cout << endl;

    
    auto sp2 = static_pointer_cast<base>(sp);
    cout << "sp2 = static_pointer_cast<base>(sp)" << endl;
    cout << "type of *sp2\t= " << typeid(*sp2).name() << endl;
    cout << "sp.use_count()\t= " << sp.use_count() << endl;
    cout << endl;

    cout << "sp3 = dynamic_pointer_cast<derived>(sp2)" << endl;
    auto sp3 = dynamic_pointer_cast<derived>(sp2);
    cout << "type of *sp3\t= " << typeid(*sp3).name() << endl;
    cout << "sp.use_count()\t= " << sp.use_count() << endl;
    cout << endl;

    auto sp4 = make_shared<int>(10);
    cout << "sp4 = make_shared<int>(10)" << endl;
    cout << "sp5 = const_pointer_cast<const int>(sp4)" << endl;
    auto sp5 = const_pointer_cast<const int>(sp4);
    cout << "*sp5\t= " << *sp5 << endl;
    cout << "sp4.use_count()\t= " << sp4.use_count() << endl;
    cout << endl;
}