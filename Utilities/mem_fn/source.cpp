#include <functional>
#include <iostream>
#include <memory>
 

using namespace std;

struct Foo
{
    void display_greeting()
    {
        std::cout << "Hello, world.\n";
    }
 
    void display_number(int i)
    {
        std::cout <<  i << '\n';
    }
 
    int add_xy(int x, int y)
    {
        return data + x + y;
    }
 
    template<typename... Args> int add_many(Args... args)
    {
        return data + (args + ...);
    }
 
   
    int data = 7;
} f;
auto u = make_unique<Foo>();
 
int main()
{
    cout << R"(
        struct Foo
        {
            void display_greeting();
            void display_number(int i);
            int add_xy(int x, int y);
            template<typename... Args> int add_many(Args... args);
            int data = 7;
        } f;
        auto u = make_unique<Foo>();
    )" << endl << endl;

    cout << "**** using instance ****" << endl;
    cout << "display_greeting(f)\t\t = " ;
    mem_fn(&Foo::display_greeting)(f);
 
    cout << "display_number(f,42)\t\t = ";
    std::mem_fn(&Foo::display_number)(f,42);
 
    cout << "data(f)\t\t\t\t = ";
    cout << mem_fn(&Foo::data)(f) << endl;
 
    cout << "add_xy(f, 1, 2)\t\t\t = ";
    cout << mem_fn(&Foo::add_xy)(f, 1, 2) << endl;
    cout << endl;
 
    cout << "**** using unique_ptr ****" << endl;
    cout << "data(u)\t\t\t\t = ";
    cout << mem_fn(&Foo::data)(u) << endl;
    cout << "add_xy(u, 1, 2)\t\t\t = ";
    cout << mem_fn(&Foo::add_xy)(u, 1, 2) << endl;
 
    cout << "add_many(u, 1, 2, 3)\t\t = ";
    cout <<  mem_fn(&Foo::add_many<short, int, long>)(u, 1, 2, 3) << endl;
 
}