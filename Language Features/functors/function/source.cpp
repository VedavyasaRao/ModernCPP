#include <iostream>     // std::cout
#include <functional>   // std::binary_negate, std::equal_to


using namespace std;
int square_num(int i)
{
    return i*i;
}


int main () 
{
    // free function
    cout << "***** free function demo *****";
    cout << R"(       
        int square_num(int i)
        {
            return i*i;
        }
    )" << endl;

    // store a free function
    cout << R"(function<int(int)> {square_num}(-9))" 
         << "\t\t\t\t = " 
         << function<int(int)>{square_num}(-9) << endl;  

    // store the result of a call to std::bind to a free function
    cout << R"(function<int(int)> {bind(square_num,placeholders::_1)}(9))" 
         << "\t = " 
         << function<int(int)> {bind(square_num,placeholders::_1)}(9) << endl;  
    cout << R"(function<int()>    {bind(square_num,9)}())" 
         << "\t\t\t = " 
         << function<int()> {bind(square_num,9)}() << endl;  

    cout << endl << endl;
    

    // struct
    struct Foo
    {
        Foo(int num) : num_(num) {}
        void print_add(int i) const { cout << num_ + i << endl; }
        int num_;
    } foo {200};

    // struct
    cout << "***** struct demo *****";
    cout << R"(       
        struct Foo
        {
            Foo(int num) : num_(num) {}
            void print_add(int i) const { cout << num_ + i << endl; }
            int num_;
        } foo {200};
    )" << endl;

    // store a call to a member function
    cout << R"(function<void(const Foo&, int)>{&Foo::print_add}(foo, 100))" 
         << "\t\t\t = ";
    function<void(const Foo&, int)>{&Foo::print_add}(foo, 100);

    // store a call to a data member accessor
    cout << R"(function<int(Foo const&)> {&Foo::num_}(foo))" 
         << "\t\t\t\t\t = "
    << function<int(Foo const&)> {&Foo::num_}(foo) << endl;

    // store a call to a member function and object
    cout << R"(function<void(int)> {bind(&Foo::print_add, foo, placeholders::_1)}(2))" 
         << "\t\t = ";
    function<void(int)> {bind(&Foo::print_add, foo, placeholders::_1)}(2);

    // store a call to a member function and object ptr
    cout << R"(function<void(int)> {bind(&Foo::print_add, &foo, placeholders::_1)}(3))" 
         << "\t\t = " ;
    function<void(int)> {bind(&Foo::print_add, &foo, placeholders::_1)}(3);
    cout << endl << endl;

    // functor
    cout << "***** functor demo *****" << endl;
    // store a call to a function object
    cout << R"(function<int(int)>{negate<int>()}(18))" 
         << "\t\t = "
         <<  function<int(int)>{negate<int>()}(18) << endl;   
    cout << endl << endl;


    // lambda expression
    cout << "***** lambda expression demo *****" << endl;
    // store a lambda
    cout << R"(function<void(int)> {[](int i) { cout << i << endl; }}(42))" 
         << "\t\t = " ;
    function<void(int)> {[](int i) { cout << i << endl; }}(42);
    
    cout << R"(       
        auto factorial = [](int n)
        {
            // store a lambda object to emulate "recursive lambda"; aware of extra overhead
            function<int(int)> fac = [&](int n) 
            { 
                cout << n << ' '; 
                return (n < 2) ? 1 : fac(n - 1); 
            };
            // note that "auto fac = [&](int n) {...};" does not work in recursive calls
            fac(n);
        };
    )" << endl;

    auto factorial = [](int n)
    {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        function<int(int)> fac = [&](int n) 
        { 
            cout << n << ' '; 
            return (n < 2) ? 1 : fac(n - 1); 
        };
        // note that "auto fac = [&](int n) {...};" does not work in recursive calls
        fac(n);
    };

    // recursion    
    cout << R"(factorial(5)!)" 
         << "\t = " ;
      factorial(5);
}