#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <iterator>
#include <sstream>

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
    return  printvector(iv) + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}

int main()
{
    vector<int> i12345 = { 1,2,3,3,4,4,5 };
    vector<int> i123 = { 1,3,5 };

    cout << boolalpha;

    cout << "lower_bound (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 3)";
    cout << endl;
    auto itr = lower_bound(i12345.begin(), i12345.end(), 3);
    cout << "Return:\t";
    cout << getitrstring(i12345, itr);
    cout << endl << endl;

    cout << "lower_bound (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 4, less<int>())";
    cout << endl;
    itr = lower_bound(i12345.begin(), i12345.end(), 4, less<int>());
    cout << "Return:\t";
    cout << getitrstring(i12345, itr);
    cout << endl << endl;

    cout << "upper_bound (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 3)";
    cout << endl;
    itr = upper_bound(i12345.begin(), i12345.end(), 3);
    cout << "Return:\t";
    cout << getitrstring(i12345, itr);
    cout << endl << endl;

    cout << "upper_bound (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 4, less<int>())";
    cout << endl;
    itr = upper_bound(i12345.begin(), i12345.end(), 4, less<int>());
    cout << "Return:\t";
    cout << getitrstring(i12345, itr);
    cout << endl << endl;

    cout << "equal_range (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 3)";
    cout << endl;
    auto p = equal_range(i12345.begin(), i12345.end(), 3);
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i12345, p.first);
    cout << " , ";
    cout << getitrstring(i12345, p.second);
    cout << "}";	cout << endl << endl;

    cout << "equal_range (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 4, less<int>())";
    cout << endl;
    p = equal_range(i12345.begin(), i12345.end(), 4, less<int>());
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i12345, p.first);
    cout << " , ";
    cout << getitrstring(i12345, p.second);
    cout << "}";
    cout << endl << endl;

    cout << "binary_search (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 6)";
    cout << endl;
    cout << "Return:\t";
    cout << binary_search(i12345.begin(), i12345.end(), 6);
    cout << endl << endl;

    cout << "binary_search (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 3)";
    cout << endl;
    cout << "Return:\t";
    cout << binary_search(i12345.begin(), i12345.end(), 3);
    cout << endl << endl;

    cout << "binary_search (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 6, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << binary_search(i12345.begin(), i12345.end(), 6, less<int>());
    cout << endl << endl;

    cout << "binary_search (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), 4, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << binary_search(i12345.begin(), i12345.end(), 4, less<int>());
    cout << endl << endl;
}