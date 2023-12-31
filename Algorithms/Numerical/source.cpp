#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <iterator>
#include <sstream>
#include <functional>
#include <numeric>

using namespace std;

string printvector(vector<int>& iv)
{
    ostringstream ss;
    copy(iv.begin(), iv.end(), ostream_iterator<int>(ss, ", "));
    auto s = ss.str();
    s.pop_back();
    s.pop_back();
    return  '[' + s + ']';
}


string getitrstring(vector<int>& iv, vector<int>::iterator& itr)
{
    return  printvector(iv)+ ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}


int main()
{

    cout << boolalpha;
    vector<int> i123{ 10,20,30 };
    vector<int> o123{ 0,0,0 };

    cout << "accumulate ([10,20,30].begin(), [10,20,30].end(), 100)";
    cout << endl;
    cout << "Return:\t";
    cout << accumulate(i123.begin(), i123.end(), 100);	
    cout << endl << endl;

    cout << "accumulate ([10,20,30].begin(), [10,20,30].end(), 100,  multiplies<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << accumulate(i123.begin(), i123.end(), 100, multiplies<int>());	
    cout << endl << endl;


    cout << "partial_sum ([10,20,30].begin(), [10,20,30].end(), [0,0,0].begin())";
    cout << endl;
    auto itr = partial_sum(i123.begin(), i123.end(), o123.begin());
    cout << "Return:\t";
    cout << getitrstring(o123, itr);
    cout << endl << endl;

    cout << "partial_sum ([10,20,30].begin(), [10,20,30].end(), [0,0,0].begin(), multiplies<int>())";
    cout << endl;
    itr = partial_sum(i123.begin(), i123.end(), o123.begin(), multiplies<int>());
    cout << "Return:\t";
    cout << getitrstring(o123, itr);
    cout << endl << endl;

    cout << "inner_product ([10,20,30].begin(), [10,20,30].end(), [10,20,30].begin(), 100)";
    cout << endl;
    cout << "Return:\t";
    cout << inner_product(i123.begin(), i123.end(), i123.begin(), 100);
    cout << endl << endl;

    cout << "inner_product ([10,20,30].begin(), [10,20,30].end(), [10,20,30].begin(), 100,";
    cout << " minus<int>(), multiplies<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << inner_product(i123.begin(), i123.end(), i123.begin(), 100, minus<int>(), multiplies<int>());
    cout << endl << endl;

    cout << "iota ([10,20,30].begin(), [10,20,30].end(), 100)";
    cout << endl;
    iota(i123.begin(), i123.end(),  100);
    cout << "Return:\t";
    cout << printvector(i123);
    cout << endl << endl;

    i123 = { 10,20,30 };
    o123 = { 0,0,0 };
    cout << "adjacent_difference ([10,20,30].begin(), [10,20,30].end(), [0,0,0].begin())";
    cout << endl;
    itr = adjacent_difference(i123.begin(), i123.end(), o123.begin());
    cout << "Return:\t";
    cout << getitrstring(o123, itr);
    cout << endl << endl;

    o123 = { 0,0,0 };
    cout << "adjacent_difference ([10,20,30].begin(), [10,20,30].end(), [0,0,0].begin(), multiplies<int>())";
    cout << endl;
    itr = adjacent_difference(i123.begin(), i123.end(), o123.begin(), multiplies<int>());
    cout << "Return:\t";
    cout << getitrstring(o123, itr);
    cout << endl << endl;
}
