#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*************************DECLTYPE*********************/
template <typename U, typename V>
auto add(U u, V v)->decltype(u+v)
{
    return u+v;
};

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

    cout << "auto deno" <<endl;
    cout << "sizeof(i) = " << sizeof i << endl;
    cout << "sizeof(l) = " << sizeof l << endl;
    cout << "sizeof(ll) = " << sizeof ll << endl;
    cout << "sizeof(f) = " << sizeof f << endl;
    cout << "sizeof(d) = " << sizeof d << endl;

    vector<int> vec;
    vec.push_back(9);
    
    //vector<int>::iterator
    auto itr=vec.begin();

    cout << boolalpha << "(vec.front() == *itr) = " << (vec.front() == *itr) << endl;

    //lambda function
    auto lam = [](){cout << "hello, world!";};

    cout << "lam() = "  << endl;
    lam();
    cout << endl;
    cout << endl;

     cout << "decltype deno" <<endl;

    /*************************DECLTYPE*********************/
    //int 
    decltype(i) i2=i;
    
    //long
    decltype(l) l2=l;

    //long long
    decltype(ll) ll2=ll;
        
    //float
    decltype(f) f2=f;

    //double
    decltype(d) d2=d;

    //vector<int>::iterator
    decltype(itr) itr2=itr;

    //lambda function
    decltype(lam) lam2=lam;

    cout << "(typeid(i) == typeid(i2)) = " << (typeid(i) == typeid(i2)) << endl;
    cout << "(typeid(l) == typeid(l2)) = " << (typeid(l) == typeid(l2)) << endl;
    cout << "(typeid(ll) == typeid(ll2)) = " << (typeid(ll) == typeid(ll2)) << endl;
    cout << "(typeid(d) == typeid(d2)) = " << (typeid(d) == typeid(d2)) << endl;
    cout << "(typeid(f) == typeid(f2)) = " << (typeid(f) == typeid(f2)) << endl;
    cout << "(typeid(itr) == typeid(itr2)) = " << (typeid(itr) == typeid(itr2)) << endl;
    cout << "(typeid(lam) == typeid(lam2)) = " << (typeid(lam) == typeid(lam2)) << endl;
    cout << "add<float,int>(3.5,10) = " << add<float,int>(3.5,10) << endl;
 
}
