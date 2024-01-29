#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>
#include <memory>
#include <stdexcept>

using namespace std;

 
// helper class for runtime polymorphism demo below
struct B
{
    virtual ~B() = default;
 
    virtual void bar() { cout << "B::bar" << endl; }
};
 
struct D : B
{
    D() { cout << "D::D" << endl; }
    ~D() { cout << "D::~D" << endl; }
 
    void bar() override { cout << "D::bar" << endl; }
};
 
// a function consuming a unique_ptr can take it by value or by rvalue reference
unique_ptr<D> pass_through(unique_ptr<D> p)
{
    p->bar();
    return p;
}
 
// helper function for the custom deleter demo below
void close_file(FILE* fp)
{
    fclose(fp);
}
 
int main()
{
    cout << "1) Unique ownership semantics demo" << endl;
    {
        // Create a (uniquely owned) resource
        unique_ptr<D> p = make_unique<D>();
 
        // Transfer ownership to `pass_through`,
        // which in turn transfers ownership back through the return value
        unique_ptr<D> q = pass_through(move(p));
 
        // p is now in a moved-from 'empty' state, equal to nullptr
        assert(!p);
    }
 
    cout <<  endl <<  "2) Runtime polymorphism demo" << endl;
    {
        // Create a derived resource and point to it via base type
        unique_ptr<B> p = make_unique<D>();
 
        // Dynamic dispatch works as expected
        p->bar();
    }
 
    cout  << endl <<  "3) Custom deleter demo" << endl;
    ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        using unique_file_t = unique_ptr<FILE, decltype(&close_file)>;
        unique_file_t fp(fopen("demo.txt", "r"), &close_file);
        if (fp)
            cout << char(fgetc(fp.get())) << endl;
    } // `close_file()` called here (if `fp` is not null)
 
    cout << endl <<  "4) Custom lambda-expression deleter and exception safety demo" << endl;
    try
    {
        unique_ptr<D, void(*)(D*)> p(new D, [](D* ptr)
        {
            cout << "destroying from a custom deleter..." << endl;
            delete ptr;
        });
 
        throw runtime_error(""); // `p` would leak here if it were a plain pointer
    }
    catch (const exception&) { cout << "Caught exception" << endl; }
 
    cout  << endl << "5) Array form of unique_ptr demo" << endl;
    {
        unique_ptr<D[]> p(new D[3]);
    } // `D::~D()` is called 3 times

    unique_ptr<int> foo;
    int* p = nullptr;

    cout << endl << "6) get demo" << endl;
    //foo:null          p:null
    foo = unique_ptr<int>(new int(10));
    //foo:(10)          p:null
    p = foo.get();
    //foo:(10)          p:(10)
    *p = 20;
    //foo:(20)          p:(20)
    p = nullptr;
    //foo:(20)          p:null

    cout << endl << "7) reset demo" << endl;
    //foo:(20)
    foo.reset(new int(10));
    //foo:(10)

    cout << endl << "8) release demo" << endl;    
    //foo:(10)          p:null
    foo = unique_ptr<int>(new int(30));
    //foo:(30)          p:null
    p = foo.release();
    //foo:null          p:(30)
    *p = 40;
    //foo:null          p:(40)

    cout << endl << "9) operator bool demo" << endl;    
    //foo:null
    cout << boolalpha << "foo\t\t: " << !!foo << endl;

    cout << endl << "10) operator [] demo" << endl;    
    //foo:null
    unique_ptr<int[]> foo2(new int [10],default_delete<int[]>());
    //foo:(int[10])
    cout << "foo2[2]\t\t: " << foo2[2] << endl;
    
   
    return 0;
}    