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
    vector<int> i1234 = { 1,2,3,4 };
    vector<int> i12345 = { 1,2,3,4,5 };
    vector<int> i135 = { 1,3,5 };
    vector<int> i24 = { 2,4 };
	
    auto isodd = [](int i) {return (i % 2) == 1; };
    auto issame = [](int i, int j) {return i == j; };
    auto print = [](int i) {cout << i << " "; };
    auto doubler = [](int i) {return i * 2; };
    auto adder = [](int i, int j) {return i + j; };
    auto rgen = [](int i) { return rand() % i; };

    cout << R"(partition ([1, 2, 3, 4, 5].begin(), [1, 2, 3, 4, 5].end(), isodd))" << endl;
    auto itr = partition(i12345.begin(), i12345.end(), isodd);
    cout << "Return:\t";
    cout << getitrstring(i12345, itr) << endl;
    cout << endl;
    i12345 = { 1,2,3,4,5 };

    cout << R"(stable_partition ([1, 2, 3, 4, 5].begin(), [1, 2, 3, 4, 5].end(), isodd))" << endl;
    itr = stable_partition(i12345.begin(), i12345.end(), isodd);
    cout << "Return:\t";
    cout << getitrstring(i12345, itr) << endl;
    cout << endl;
    i12345 = { 1,2,3,4,5 };

    cout << R"(partition_copy ([1, 2, 3, 4, 5].begin(), [1, 2, 3, 4, 5].end(), )";
    cout << R"([1, 3, 5].begin(), [2, 4].begin(), isodd))" << endl;
    auto p = partition_copy(i12345.begin(), i12345.end(), i135.begin(), i24.begin(), isodd);
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i135, p.first);
    cout << ",";
    cout << getitrstring(i24, p.second);
    cout << "}  ";
    printvector(i12345);
    cout << endl << endl;
    i12345 = { 1,2,3,4,5 };
	
    cout << R"(partition_point ([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    itr = partition_point(i1234.begin(), i1234.end(), isodd);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl;
    cout << endl;
    i1234 = { 1,2,3,4 };

    cout << R"(is_partitioned ([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    auto b = is_partitioned(i1234.begin(), i1234.end(), isodd);
    cout << "Return:\t";
    cout << boolalpha << b << endl;
    cout << endl;

    cout << R"(is_partitioned ([1, 3, 5].begin(), [1, 3, 5].end(), isodd))" << endl;
    b = is_partitioned(i135.begin(), i135.end(), isodd);
    cout << "Return:\t";
    cout << boolalpha << b << endl;
    cout << endl;
}