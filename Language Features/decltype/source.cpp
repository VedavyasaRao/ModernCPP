#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*************************DECLTYPE*********************/
template <typename U, typename V>
auto add(U u, V v)->decltype(u+v) {    return u+v; };

int main()
{
    cout << "decltype demo" << endl;
    
    /*************************DECLTYPE*********************/

    cout << boolalpha;
    //int
    auto i=0;
    decltype(i) i2=i;
    cout << "//int" << endl;
    cout << "auto i=0;" << endl;
    cout << "decltype(i) i2=i;" << endl;
    cout << "(typeid(i) == typeid(i2)) = " << (typeid(i) == typeid(i2)) << endl << endl;

    
    //long
    auto l=10l;
    decltype(l) l2=l;
    cout << "//long" << endl;
    cout << "auto l=10l;" << endl;
    cout << "decltype(l) l2=l;" << endl;
    cout << "(typeid(l) == typeid(l2)) = " << (typeid(l) == typeid(l2)) << endl << endl;

    //long long
    auto ll=10ll;
    decltype(ll) ll2=ll;
    cout << "//long long" << endl;
    cout << "auto ll=10ll;" << endl;
    cout << "decltype(ll) ll2=ll;" << endl;
    cout << "(typeid(ll) == typeid(ll2)) = " << (typeid(ll) == typeid(ll2)) << endl << endl;

    //float
    auto f=5.f;
    decltype(f) f2=f;
    cout << "//float" << endl;
    cout << "auto f=5.f;" << endl;
    cout << "decltype(f) f2=f;" << endl;
    cout << "(typeid(f) == typeid(f2)) = " << (typeid(f) == typeid(f2)) << endl << endl;

    //double
    auto d=5.;
    decltype(d) d2=d;
    cout << "//double" << endl;
    cout << "auto d=5.;" << endl;
    cout << "decltype(d) d2=d;" << endl;
    cout << "(typeid(f) == typeid(f2)) = " << (typeid(f) == typeid(f2)) << endl << endl;

    
    //vector
    vector<int> vec;
    vec.push_back(9); 
    //vector<int>::iterator
    auto itr=vec.begin();
    //vector<int>::iterator
    decltype(itr) itr2=itr;
    cout << "//vector<int>::iterator" << endl;
    cout << "auto itr=vec.begin();" << endl;
    cout << "decltype(itr) itr2=itr;" << endl;
    cout << "(typeid(itr) == typeid(itr2)) = " << (typeid(itr) == typeid(itr2)) << endl << endl;

    //lambda
    auto lam = [](){cout << "hello, world!";};
    decltype(lam) lam2=lam;
    cout << "//lambda" << endl;
    cout << "auto lam = [](){cout << \"hello, world!\";};" << endl;
    cout << "decltype(lam) lam2=lam;" << endl;
    cout << "(typeid(lam) == typeid(lam2)) = " << (typeid(lam) == typeid(lam2)) << endl << endl;

     cout << "template <typename U, typename V>" << endl;
     cout << "auto add(U u, V v)->decltype(u+v) {    return u+v; };" << endl;
    cout << "add<float,int>(3.5,10) = " << add<float,int>(3.5,10) << endl;
 
}
