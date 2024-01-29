#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <stdexcept>

using namespace std;


 
int main()
{

{
    cout << "shared_ptr<T>()" << endl;
    shared_ptr<int>();
}

{
    cout << "shared_ptr<T>(nullptr_t)" << endl;
    shared_ptr<int>(nullptr);
}

{
cout << "shared_ptr<T>(T *p)" << endl;
shared_ptr<int>(new int);
}

{
cout << "shared_ptr<T,D>(T * p, const D& del)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  (new int, d);
}

{
cout << "shared_ptr<D>(nullptr_t,  const D& del)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  (nullptr, d);
}

{
cout << "shared_ptr<T,D,A>(T *p,  const D& del, Alloc a)" << endl;
auto d = default_delete<int>();
//shared_ptr<int>  ((new int, d, allocator<int>());
}

{
cout << "shared_ptr<D,A>(nullptr_t,  const D& del, Alloc a)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  (nullptr, d, allocator<int>());
}

{
cout << "shared_ptr(shared_ptr&& x)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  x(new int, d);
shared_ptr<int>  (move(x));
}

{
cout << "shared_ptr<T>(shared_ptr<T>&& x)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  (move(shared_ptr<int> (new int, d)));
}

{
cout << "shared_ptr(const shared_ptr& x)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  x(new int, d);
shared_ptr<int>  x2(x);
}

{
cout << "shared_ptr<T>(const shared_ptr<T>& x)" << endl;
auto d = default_delete<int>();
shared_ptr<int>  (shared_ptr<int> (new int, d));
}

{
cout << "shared_ptr<T>(weak_ptr<T>& x)" << endl;
shared_ptr<int> (auto_ptr<int>(new int));
}

{
cout << "shared_ptr<T>(auto_ptr<T>&& x)" << endl;
shared_ptr<int> (auto_ptr<int>(new int));
}

{
cout << "shared_ptr<T,D>(unique_ptr<T,D>&& x)" << endl;
unique_ptr<int> x(new int);
shared_ptr<int>  (move(x));
}

{
cout << "shared_ptr<T>(const shared_ptr<T>& x, element_type *p)" << endl;
struct S {int data;};
shared_ptr<S>  x(new S);
shared_ptr<int> (x, &x->data);
}
    return 0;
}    