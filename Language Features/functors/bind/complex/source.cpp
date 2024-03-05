#include <functional>
#include <iostream>
#include <memory>
#include <random>

using namespace std;

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << endl;
}
 
int g(int n1)
{
    return n1;
}
 
struct Foo
{
    void print_sum(int n1, int n2)
    {
        cout << n1 + n2 << endl;
    }
 
    int data = 10;
} foo;
 
int main()
{
    cout << R"(
        void f(int n1, int n2, int n3, const int& n4, int n5);
        int g(int n1);
 
        struct Foo
        {
            void print_sum(int n1, int n2);
        int data = 10;
        } foo;
    )" << endl;

    
    cout << "1) argument reordering and pass-by-reference: " << endl;
    int n = 7;
    // (_1 and _2 are from placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = bind(f, placeholders::_2, 42, placeholders::_1, cref(n), n);
    n = 10;
    cout << " bind(f, placeholders::_2, 42, placeholders::_1, cref(n), n)(1, 2, 1001) = ";
    f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused
    cout << endl;

    
    cout << "2) achieving the same effect using a lambda: " << endl;
    n = 7;
    auto lambda = [&ncref = n, n](auto a, auto b, auto /*unused*/)
    {
        f(b, 42, a, ncref, n);
    };
    n = 10;
    cout << "[&ncref = n, n](auto a, auto b, auto /*unused*/)(1, 2, 1001) = " ;
    lambda(1, 2, 1001); // same as a call to f1(1, 2, 1001)
    cout << endl;
    
    cout << "3) nested bind subexpressions share the placeholders: " << endl;
    auto f2 = bind(f, placeholders::_3, bind(g, placeholders::_3), placeholders::_3, 4, 5);
    cout << "bind(f, placeholders::_3, bind(g, placeholders::_3), placeholders::_3, 4, 5)(10, 11, 12) = " ;
    f2(10, 11, 12); // makes a call to f(12, g(12), 12, 4, 5);
    cout << endl;

    
    cout << "4) bind a RNG with a distribution: " << endl;
    cout << "bind(uniform_int_distribution<>(0, 10), default_random_engine{})() = ";
    cout << bind(uniform_int_distribution<>(0, 10), default_random_engine{})();
    cout << endl;
 
    cout << "5) bind to a pointer to member function: " << endl;
    cout << "bind(&Foo::print_sum, &foo, 95, placeholders::_1) = ";
    auto f3 = bind(&Foo::print_sum, &foo, 95, placeholders::_1);
    f3(5);
    cout << endl;

    
    cout << "6) bind to a mem_fn that is a pointer to member function: " << endl;
    auto ptr_to_print_sum = mem_fn(&Foo::print_sum);
    auto f4 = bind(ptr_to_print_sum, &foo, 95, placeholders::_1);
    cout << "bind(mem_fn(&Foo::print_sum), &foo, 95, placeholders::_1) = ";
    f4(5);
     cout << endl;
    
    cout << "7) bind to a pointer to data member: " << endl;
    auto f5 = bind(&Foo::data, placeholders::_1);
    cout << "bind(&Foo::data, placeholders::_1)(foo) = ";
    cout << f5(foo) << endl;
    cout << endl;
    
    cout << "8) bind to a mem_fn that is a pointer to data member: " << endl;
    auto ptr_to_data = mem_fn(&Foo::data);
    auto f6 = bind(ptr_to_data, placeholders::_1);
    cout << "bind(mem_fn(&Foo::data), placeholders::_1)(foo) = ";
    cout << f6(foo) << endl;
     cout << endl;
    
    cout << "9) use smart pointers to call members of the referenced objects: " << endl;
    cout << "bind(mem_fn(&Foo::data), placeholders::_1)(make_shared<Foo>(foo)) = ";
    cout << f6(make_shared<Foo>(foo)) << endl;
    cout << "bind(mem_fn(&Foo::data), placeholders::_1)(make_unique<Foo>(foo)) = ";
    cout << f6(make_unique<Foo>(foo)) << endl;
}