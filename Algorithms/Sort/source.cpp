#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <iterator>
#include <sstream>
#include <functional>

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
    return '[' + s + ']' + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");;
}


int main()
{
    vector<int> i12345 = { 1,2,3,4,5 };
    vector<int> i123 = { 1,3,5 };

    random_shuffle(i12345.begin(), i12345.end());
    cout << "sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end())" << endl;
    sort(i12345.begin(), i12345.end());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;

    random_shuffle(i12345.begin(), i12345.end());
    cout << "sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), greater<int>())" << endl;
    sort(i12345.begin(), i12345.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;

    random_shuffle(i12345.begin(), i12345.end());
    cout << "stable_sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end())" << endl;
    stable_sort(i12345.begin(), i12345.end());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;

    random_shuffle(i12345.begin(), i12345.end());
    cout << "stable_sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), greater<int>())" << endl;
    stable_sort(i12345.begin(), i12345.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;

    random_shuffle(i12345.begin(), i12345.end());
    cout << "partial_sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".begin()+3, " << printvector(i12345) << ".end())" << endl;
    partial_sort(i12345.begin(), i12345.begin() + 3, i12345.end());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    cout << "partial_sort (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".begin()+3, " << printvector(i12345) << ".end(), greater<int>())" << endl;
    partial_sort(i12345.begin(), i12345.begin() + 3, i12345.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i12345);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    i123 = { 0,0,0 };
    random_shuffle(i12345.begin(), i12345.end());
    cout << "partial_sort_copy (" << printvector(i12345) << ".begin(), "  << printvector(i12345) << ".end(), [0, 0, 0].begin(), [0, 0, 0].end())" << endl;
    partial_sort_copy(i12345.begin(), i12345.end(), i123.begin(), i123.end());
    cout << "Return:\t";
    cout << printvector(i123);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    i123 = { 0,0,0 };
    random_shuffle(i12345.begin(), i12345.end());
    cout << "partial_sort_copy (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), [0, 0, 0].begin(), [0, 0, 0].end(), greater<int>())" << endl;
    partial_sort_copy(i12345.begin(), i12345.end(), i123.begin(), i123.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i123);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    cout << boolalpha;
    random_shuffle(i12345.begin(), i12345.end());
    cout << "is_sorted (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end())" << endl;
    cout << "Return:\t";
    cout << is_sorted(i12345.begin(), i12345.end());
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    cout << "is_sorted (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end())" << endl;
    cout << "Return:\t";
    cout << is_sorted(i12345.begin(), i12345.end());
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    cout << "is_sorted (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), greater<int>())" << endl;
    cout << "Return:\t";
    cout << is_sorted(i12345.begin(), i12345.end(), greater<int>());
    cout << endl << endl;
    i12345 = { 5,4,3,2,1 };

    cout << "is_sorted (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), greater<int>())" << endl;
    cout << "Return:\t";
    cout << is_sorted(i12345.begin(), i12345.end(), greater<int>());
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    partial_sort(i12345.begin(), i12345.begin() + 3, i12345.end(), less<int>());
    cout << "is_sorted_until (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".end())" << endl;
    cout << "Return:\t";
    auto itr = is_sorted_until(i12345.begin(), i12345.end());
    cout << printvector(i12345, itr);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    partial_sort(i12345.begin(), i12345.begin() + 3, i12345.end(), greater<int>());
    cout << "is_sorted_until ("	<< printvector(i12345) << ".begin(), " << printvector(i12345) << ".end(), greater<int>())" << endl;
    cout << "Return:\t";
    itr = is_sorted_until(i12345.begin(), i12345.end(), greater<int>());
    cout << printvector(i12345, itr);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    cout << "nth_element  (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".begin()+3, " << printvector(i12345) << ".end())" << endl;
    cout << "Return:\t";
    nth_element(i12345.begin(), i12345.begin() + 3, i12345.end());
    cout << printvector(i12345);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };

    random_shuffle(i12345.begin(), i12345.end());
    cout << "nth_element  (" << printvector(i12345) << ".begin(), " << printvector(i12345) << ".begin()+3, " << printvector(i12345)	<< ".end(), greater<int>())" << endl;
    cout << "Return:\t";
    nth_element(i12345.begin(), i12345.begin() + 3, i12345.end(), greater<int>());
    cout << printvector(i12345);
    cout << endl << endl;
}
