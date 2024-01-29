#include <iostream>
#include <memory>

using namespace std;

int main()
{
    cout << "weak_ptr<T>()" << endl;
    weak_ptr<int>();

{    
    cout << "weak_ptr(weak_ptr&& x)" << endl;
    weak_ptr<int> x;
    weak_ptr<int> (move(x));
}
    cout << "weak_ptr<T>(weak_ptr<T>&& x)" << endl;
    weak_ptr<int> (weak_ptr<int>());

{    
    cout << "weak_ptr(const weak_ptr& x)" << endl;
    weak_ptr<int> x;
    weak_ptr<int> y(x);
}

{    
    cout << "weak_ptr<T>(const weak_ptr<T>& x)" << endl;
    weak_ptr<int>x;
    weak_ptr<int> y(x);
    weak_ptr<int> z(y);
}

{    
    cout << "weak_ptr<T>(const shared_ptr<T>& x)" << endl;
    shared_ptr<int> x(new int, default_delete<int>());
    weak_ptr<int> w(x);    
}
    
}