#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    /*************************AUTO*********************/
    //int
    auto i=0;
    
    //long
    auto l=10l;

    //long long
    auto ll=10ll;
        
    //float
    auto f=5.f;

    //double
    auto d=5.;

    cout << "decltype deno" << endl;
    cout << "//int" << endl;
    cout << "auto i=0;" << endl;
    cout << "sizeof(i) = " << sizeof i << endl << endl;
    
    cout << "//long" << endl;
    cout << "auto l=10l;" << endl;
    cout << "sizeof(l) = " << sizeof l << endl << endl;

    cout << "//long long" << endl;
    cout << "auto ll=10ll;" << endl;
    cout << "sizeof(ll) = " << sizeof ll << endl << endl;
    
    cout << "//float" << endl;
    cout << "auto f=5.f;" << endl;
    cout << "sizeof(f) = " << sizeof f << endl << endl;

    
    cout << "//double" << endl;
    cout << "auto d=5.;" << endl;
    cout << "sizeof(d) = " << sizeof d << endl << endl;

    vector<int> vec;
    vec.push_back(9);
    
    //vector<int>::iterator
    auto itr=vec.begin();

    cout << "//vector<int>::iterator" << endl;
    cout << "auto itr=vec.begin();" << endl;
    cout << boolalpha << "(vec.front() == *itr) = " << (vec.front() == *itr) << endl << endl;

    //lambda function
    auto lam = [](){cout << "hello, world!";};

    cout << "//lambda function" << endl;
    cout << "auto lam = [](){cout << \"hello, world!\";};" << endl;
    cout << "lam() = "  << endl;
    lam();
    cout << endl;
    cout << endl;
}
