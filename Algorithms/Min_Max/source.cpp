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
    return  printvector(iv) + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}



int main()
{
    cout << boolalpha;
    vector<int> i12{ 10,20 };
    cout << "min (10, 20)";
    cout << endl;
    cout << "Return:\t";
    cout << min(10, 20);
    cout << endl << endl;

    cout << "min (10, 20, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << min(10, 20, less<int>());
    cout << endl << endl;

    cout << "min ({10, 20})";
    cout << endl;
    cout << "Return:\t";
    cout << min({ 10, 20 });
    cout << endl << endl;

    cout << "min ({10, 20}, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << min({ 10, 20 }, less<int>());
    cout << endl << endl;

    cout << "max (10, 20)";
    cout << endl;
    cout << "Return:\t";
    cout << max(10, 20);
    cout << endl << endl;

    cout << "max (10, 20, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << max(10, 20, less<int>());
    cout << endl << endl;

    cout << "max ({10, 20})";
    cout << endl;
    cout << "Return:\t";
    cout << max({ 10, 20 });
    cout << endl << endl;

    cout << "max ({10, 20}, less<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << max({ 10, 20 }, less<int>());
    cout << endl << endl;

    cout << "minmax (10, 20)";
    cout << endl;
    cout << "Return:\t";
    auto p = minmax(10, 20);
    cout << "{" << p.first << "," << p.second << "}";
    cout << endl << endl;

    cout << "minmax (10, 20, less<int>())";
    cout << endl;
    cout << "Return:\t";
    auto p2 = minmax(10, 20, less<int>());
    cout << "{" << p2.first << "," << p2.second << "}";
    cout << endl << endl;

    cout << "minmax ({10, 20})";
    cout << endl;
    cout << "Return:\t";
    auto p3 = minmax({ 10, 20 });
    cout << "{" << p3.first << "," << p3.second << "}";
    cout << endl << endl;

    cout << "minmax ({10, 20}, less<int>())";
    cout << endl;
    cout << "Return:\t";
    auto p4 = minmax({ 10, 20 }, less<int>());
    cout << "{" << p4.first << "," << p4.second << "}";
    cout << endl << endl;

    cout << "min_element ([10, 20].begin(),[10, 20].end())";
    cout << endl;
    cout << "Return:\t";
    auto itr = min_element(i12.begin(), i12.end());
    cout << getitrstring(i12, itr);
    cout << endl << endl;

    cout << "min_element ([10, 20].begin(),[10, 20].end(), less<int>())";
    cout << endl;
    cout << "Return:\t";
    itr = min_element(i12.begin(), i12.end(), less<int>());
    cout << getitrstring(i12, itr);
    cout << endl << endl;

    cout << "max_element ([10, 20].begin(),[10, 20].end())";
    cout << endl;
    cout << "Return:\t";
    itr = max_element(i12.begin(), i12.end());
    cout << getitrstring(i12, itr);
    cout << endl << endl;

    cout << "max_element ([10, 20].begin(),[10, 20].end(), less<int>())";
    cout << endl;
    cout << "Return:\t";
    itr = max_element(i12.begin(), i12.end(), less<int>());
    cout << getitrstring(i12, itr);
    cout << endl << endl;

    cout << "minmax_element ([10, 20].begin(),[10, 20].end())";
    cout << endl;
    cout << "Return:\t";
    auto p5 = minmax_element(i12.begin(), i12.end());
    cout << "{";
    cout << getitrstring(i12, p5.first);
    cout << " , ";
    cout << getitrstring(i12, p5.second);
    cout << "}";
    cout << endl << endl;

    cout << "minmax_element ([10, 20].begin(),[10, 20].end(), less<int>())";
    cout << endl;
    cout << "Return:\t";
    auto p6 = minmax_element(i12.begin(), i12.end(), less<int>());
    cout << "{";
    cout << getitrstring(i12, p6.first);
    cout << " , ";
    cout << getitrstring(i12, p6.second);
    cout << "}";
    cout << endl << endl;
}