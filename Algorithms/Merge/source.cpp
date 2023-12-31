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

string printvector(vector<int>& iv, vector<int>::iterator& itr)
{
    ostringstream ss;

    copy(iv.begin(), itr, ostream_iterator<int>(ss, ", "));
    for_each(itr, iv.end(), [&](int i) {ss << "X, "; });
    auto s = ss.str();
    s.pop_back();
    s.pop_back();
    return  '[' + s + ']' + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}


int main()
{
    auto issame = [](int i, int j) {return i == j; };
    vector<int> i124 = { 1,2,4 };
    vector<int> i1244 = { 1,2,4,4 };
    vector<int> i2446 = { 2,4,4,6 };
    vector<int> i3456 = { 3,4,5,6 };
    vector<int> i0000000 = { 0,0,0,0,0,0,0 };

    cout << boolalpha;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "merge([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin())";
    cout << endl;
    auto itr = merge(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin());
    cout << "Return:\t";
    cout << getitrstring(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "merge([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin(), less<int>())";
    cout << endl;
    itr = merge(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin(), less<int>());
    cout << "Return:\t";
    cout << getitrstring(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 1, 2, 4, 3, 4, 5, 6 };
    cout << "inplace_merge([1,2,4,3,4,5,6].begin(), [1,2,4,3,4,5,6].begin(), [1,2,4,3,4,5,6].end())";
    cout << endl;
    inplace_merge(i0000000.begin(), i0000000.begin() + 3, i0000000.end());
    cout << "Return:\t";
    cout << printvector(i0000000);
    cout << endl << endl;

    i0000000 = { 1, 2, 4, 3, 4, 5, 6 };
    cout << "inplace_merge([1,2,4,3,4,5,6].begin(), [1,2,4,3,4,5,6].begin(), [1,2,4,3,4,5,6].end(), less<int>())";
    cout << endl;
    inplace_merge(i0000000.begin(), i0000000.begin() + 3, i0000000.end(), less<int>());
    cout << "Return:\t";
    cout << printvector(i0000000);
    cout << endl << endl;

    i0000000 = { 1, 2, 3, 4, 4, 5, 6 };
    cout << "includes([1,2,3,4,4,5,6].begin(), [1,2,3,4,4,5,6].end(), [3,4,5,6].begin(), [3,4,5,6].end())";
    cout << endl;
    cout << "Return:\t";
    cout << includes(i0000000.begin(), i0000000.end(), i3456.begin(), i3456.end());
    cout << endl << endl;

    i0000000 = { 1, 2, 3, 4, 4, 5, 7 };
    cout << "includes([1,2,3,4,4,5,7].begin(), [1,2,3,4,4,5,7].end(), [3,4,5,6].begin(), [3,4,5,6].end())";
    cout << endl;
    cout << "Return:\t";
    cout << includes(i0000000.begin(), i0000000.end(), i3456.begin(), i3456.end());
    cout << endl << endl;

    i0000000 = { 1, 2, 3, 4, 4, 5, 6 };
    cout << "includes([1,2,3,4,4,5,6].begin(), [1,2,3,4,4,5,6].end(), [3,4,5,6].begin(), [3,4,5,6].end())";
    cout << endl;
    cout << "Return:\t";
    cout << includes(i0000000.begin(), i0000000.end(), i3456.begin(), i3456.end());
    cout << endl << endl;

    i0000000 = { 1, 2, 3, 4, 4, 5, 7 };
    cout << "includes([1,2,3,4,4,5,7].begin(), [1,2,3,4,4,5,7].end(), [3,4,5,6].begin(), [3,4,5,6].end())";
    cout << endl;
    cout << "Return:\t";
    cout << includes(i0000000.begin(), i0000000.end(), i3456.begin(), i3456.end());
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_union([1,2,4,4].begin(), [1,2,4,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin())";
    cout << endl;
    itr = set_union(i1244.begin(), i1244.end(), i3456.begin(), i3456.end(), i0000000.begin());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_union([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin(), less<int>())";
    cout << endl;
    itr = set_union(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin(), less<int>());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_intersection ([2,4,4,6].begin(), [2,4,4,6].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin())";
    cout << endl;
    itr = set_intersection(i2446.begin(), i2446.end(), i3456.begin(), i3456.end(), i0000000.begin());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_intersection([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin(), less<int>())";
    cout << endl;
    itr = set_intersection(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin(), less<int>());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_difference ([1,2,4,4].begin(), [1,2,4,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin())";
    cout << endl;
    itr = set_difference(i1244.begin(), i1244.end(), i3456.begin(), i3456.end(), i0000000.begin());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_difference([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin(), less<int>())";
    cout << endl;
    itr = set_difference(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin(), less<int>());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_symmetric_difference([1,2,4,4].begin(), [1,2,4,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin())";
    cout << endl;
    itr = set_symmetric_difference(i1244.begin(), i1244.end(), i3456.begin(), i3456.end(), i0000000.begin());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;

    i0000000 = { 0,0,0,0,0,0,0 };
    cout << "set_symmetric_difference([1,2,4].begin(), [1,2,4].end(),[3,4,5,6].begin(), [3,4,5,6].end(),[0,0,0,0,0,0,0].begin(), less<int>())";
    cout << endl;
    itr = set_symmetric_difference(i124.begin(), i124.end(), i3456.begin(), i3456.end(), i0000000.begin(), less<int>());
    cout << "Return:\t";
    cout << printvector(i0000000, itr);
    cout << endl << endl;
}