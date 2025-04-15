#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

int main()
{
    cout  << "STL alogorithms" << endl;
    cout << R"(vector<int> c{1, 2, 3, 4, 5, 6, 7};)" <<  endl;
    cout  << "remove_if" << endl;
    vector<int> c{1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());
 
    cout << "for_each" << endl;
    for_each(c.begin(), c.end(), [](int i) { cout << i << ' '; });
    cout  <<  endl << endl;

    cout  << "function objects" << endl;
    auto func1 = [](int i = 6) { return i + 4; };
    cout << "func1: " << func1() << '\n';
 
    function<int(int)> func2 = [](int i) { return i + 4; };
    cout << "func2: " << func2(6) << '\n';
    cout  <<  endl;
 
    constexpr int fib_max {8};
    cout << "Emulate `recursive lambda` calls:" << endl;
    cout << "Fibonacci numbers: " << endl;
    auto nth_fibonacci = [](int n)
    {
        function<int(int, int, int)> fib = [&](int n, int a, int b)
        {
            return n ? fib(n - 1, a + b, a) : b;
        };
        return fib(n, 0, 1);
    };
 
    for (int i{1}; i <= fib_max; ++i)
        cout << nth_fibonacci(i) << " ";
        

    cout  <<  endl << endl;
    cout << "Launching thread" << endl;
    thread t([]()
    {
        cout << "hello, world!" << endl;
    });
    t.join();        
}