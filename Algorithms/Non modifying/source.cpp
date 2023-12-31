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

string getitrstring(vector<int>& iv, vector<int>::iterator& itr)
{
    return  printvector(iv) + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}


int main()
{
    vector<int> i12323 = { 1,2,3,2,3 };
    vector<int> i1234 = { 1,2,3,4 };
    vector<int> i4321 = { 4,3,2,1 };
    vector<int> i1223 = { 1,2,2,3 };
    vector<int> i12 = { 1,2 };
    vector<int> i24 = { 2,4 };
    vector<int> i13 = { 1,3 };
    vector<int> i23 = { 2,3 };
    vector<int> i22 = { 2,2 };
    vector<int> i56 = { 5,6 };

    auto isodd = [](int i) {return (i % 2) == 1; };
    auto issame = [](int i, int j) {return i == j; };
    auto print = [](int i) {cout << i << " "; };

    cout << boolalpha;

    cout << R"(all_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << all_of(i1234.begin(), i1234.end(), isodd) << endl << endl;

    cout << R"(all_of([1, 3].begin(), [1, 3].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << all_of(i13.begin(), i13.end(), isodd) << endl << endl;

    cout << R"(any_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << any_of(i1234.begin(), i1234.end(), isodd) << endl << endl;

    cout << R"(any_of([2, 4].begin(), [2, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << any_of(i24.begin(), i24.end(), isodd) << endl << endl;

    cout << R"(none_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << none_of(i12.begin(), i12.end(), isodd) << endl << endl;

    cout << R"(none_of([2, 4].begin(), [2, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << none_of(i24.begin(), i24.end(), isodd) << endl << endl;

    cout << R"(for_each([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), print))" << endl;
    cout << "Result:\t";
    for_each(i1234.begin(), i1234.end(), print);
    cout << endl << endl;

    cout << R"(find([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), 2))" << endl;
    auto itr = find(i1234.begin(), i1234.end(), 2);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;

    cout << R"(find([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), 5))" << endl;
    itr = find(i1234.begin(), i1234.end(), 5);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;

    cout << R"(find_if([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    itr = find_if(i1234.begin(), i1234.end(), isodd);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;

    cout << R"(find_if([2, 4].begin(), [2, 4].end(), isodd))" << endl;
    itr = find_if(i24.begin(), i24.end(), isodd);
    cout << "Return:\t";
    cout << getitrstring(i24, itr) << endl << endl;

    cout << R"(find_end([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 3].begin(), [2, 3].end()))" << endl;
    itr = find_end(i12323.begin(), i12323.end(), i23.begin(), i23.end());
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;;

    cout << R"(find_end([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [1, 3].begin(), [1, 3].end()))" << endl;
    itr = find_end(i12323.begin(), i12323.end(), i13.begin(), i13.end());
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;;

    cout << R"(find_end([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 3].begin(), [2, 3].end(), issame))" << endl;
    itr = find_end(i12323.begin(), i12323.end(), i23.begin(), i23.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;;

    cout << R"(find_end([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [1, 3].begin(), [1, 3].end(), issame))" << endl;
    itr = find_end(i12323.begin(), i12323.end(), i13.begin(), i13.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;;

    cout << R"(find_first_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 3].begin(), [1, 3].end()))" << endl;
    itr = find_first_of(i1234.begin(), i1234.end(), i13.begin(), i13.end());
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(find_first_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [5, 6].begin(), [5, 6].end()))" << endl;
    itr = find_first_of(i1234.begin(), i1234.end(), i56.begin(), i56.end());
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(find_first_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 3].begin(), [1, 3].end(), issame))" << endl;
    itr = find_first_of(i1234.begin(), i1234.end(), i13.begin(), i13.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(find_first_of([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [5, 6].begin(), [5, 6].end(), issame))" << endl;
    itr = find_first_of(i1234.begin(), i1234.end(), i56.begin(), i56.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(adjacent_find([1, 2, 2, 3].begin(), [1, 2, 2, 3].end()))" << endl;
    itr = adjacent_find(i1223.begin(), i1223.end());
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;;

    cout << R"(adjacent_find([1, 2, 3, 4].begin(), [1, 2, 3, 4].end()))" << endl;
    itr = adjacent_find(i1234.begin(), i1234.end());
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(adjacent_find([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), issame))" << endl;
    itr = adjacent_find(i1223.begin(), i1223.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;;

    cout << R"(adjacent_find([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), issame))" << endl;
    itr = adjacent_find(i1234.begin(), i1234.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i1234, itr) << endl << endl;;

    cout << R"(count([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), 2))" << endl;
    cout << "Return:\t";
    cout << count(i1223.begin(), i1223.end(), 2) << endl << endl;;

    cout << R"(count([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), 3))" << endl;
    cout << "Return:\t";
    cout << count(i12323.begin(), i12323.end(), 3) << endl << endl;;

    cout << R"(count([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), 4))" << endl;
    cout << "Return:\t";
    cout << count(i12323.begin(), i12323.end(), 4) << endl << endl;;

    cout << R"(count_if([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << count_if(i1234.begin(), i1234.end(), isodd) << endl << endl;;

    cout << R"(count_if([2, 4].begin(), [2, 4].end(), isodd))" << endl;
    cout << "Return:\t";
    cout << count_if(i24.begin(), i24.end(), isodd) << endl << endl;;

    cout << R"(mismatch([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 2, 3].begin()))" << endl;
    auto p = mismatch(i1234.begin(), i1234.end(), i1223.begin());
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i1234, p.first);
    cout << " , ";
    cout << getitrstring(i1223, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(mismatch( [1, 2].begin(), [1, 2].end(), [1, 2, 3, 4].begin()))" << endl;
    p = mismatch(i12.begin(), i12.end(), i1234.begin());
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i12, p.first);
    cout << " , ";
    cout << getitrstring(i1234, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(mismatch([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 3, 4].begin()))" << endl;
    p = mismatch(i1234.begin(), i1234.end(), i1234.begin());
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i1234, p.first);
    cout << " , ";
    cout << getitrstring(i1234, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(mismatch([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 2, 3].begin(), issame))" << endl;
    p = mismatch(i1234.begin(), i1234.end(), i1223.begin(), issame);
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i1234, p.first);
    cout << " , ";
    cout << getitrstring(i1223, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(mismatch( [1, 2].begin(), [1, 2].end(), [1, 2, 3, 4].begin(), issame))" << endl;
    p = mismatch(i12.begin(), i12.end(), i1234.begin(), issame);
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i12, p.first);
    cout << " , ";
    cout << getitrstring(i1234, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(mismatch([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 3, 4].begin(), issame))" << endl;
    p = mismatch(i1234.begin(), i1234.end(), i1234.begin(), issame);
    cout << "Return:\t";
    cout << "{";
    cout << getitrstring(i1234, p.first);
    cout << " , ";
    cout << getitrstring(i1234, p.second);
    cout << "}";
    cout << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 3, 4].begin(), [1, 2, 3, 4].end()))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i1234.begin(), i1234.end()) << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2].begin(), [1, 2].end()))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i12.begin(), i12.end()) << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), issame))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i1234.begin(), i1234.end(), issame) << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2].begin(), [1, 2].end(), issame))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i12.begin(), i12.end(), issame) << endl << endl;

    cout << R"(is_permutation ([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [4, 3, 2, 1].begin(), [4, 3, 2, 1].end()))" << endl;
    cout << "Return:\t";
    cout << is_permutation(i1234.begin(), i1234.end(), i4321.begin(), i4321.end()) << endl << endl;

    cout << R"(is_permutation([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2].begin(), [1, 2].end()))" << endl;
    cout << "Return:\t";
    cout << is_permutation(i1234.begin(), i1234.end(), i12.begin(), i12.end()) << endl << endl;

    cout << R"(is_permutation ([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(),)";
    cout << R"( [4, 3, 2, 1].begin(), [4, 3, 2, 1].end(), issame))" << endl;
    cout << "Return:\t";
    cout << is_permutation(i1234.begin(), i1234.end(), i4321.begin(), i4321.end(), issame) << endl << endl;

    cout << R"(is_permutation([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2].begin(), [1, 2].end(), issame))" << endl;
    cout << "Return:\t";
    cout << is_permutation(i1234.begin(), i1234.end(), i12.begin(), i12.end(), issame) << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2, 3, 4].begin(), [1, 2, 3, 4].end()))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i1234.begin(), i1234.end()) << endl << endl;

    cout << R"(equal([1, 2, 3, 4].begin(), [1, 2, 3, 4].end(), [1, 2].begin(), [1, 2].end()))" << endl;
    cout << "Return:\t";
    cout << equal(i1234.begin(), i1234.end(), i12.begin(), i12.end()) << endl << endl;

    cout << R"(search([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 3].begin(), [2, 3].end()))" << endl;
    itr = search(i12323.begin(), i12323.end(), i23.begin(), i23.end());
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;

    cout << R"(search([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 2].begin(), [2, 2].end()))" << endl;
    itr = search(i12323.begin(), i12323.end(), i22.begin(), i22.end());
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;

    cout << R"(search([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 3].begin(), [2, 3].end(), issame))" << endl;
    itr = search(i12323.begin(), i12323.end(), i23.begin(), i23.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;

    cout << R"(search([1, 2, 3, 2, 3].begin(), [1, 2, 3, 2, 3].end(), [2, 2].begin(), [2, 2].end(), issame))" << endl;
    itr = search(i12323.begin(), i12323.end(), i22.begin(), i22.end(), issame);
    cout << "Return:\t";
    cout << getitrstring(i12323, itr) << endl << endl;

    cout << R"(search_n([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), 2, 2))" << endl;
    itr = search_n(i1223.begin(), i1223.end(), 2, 2);
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;

    cout << R"(search_n([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), 3, 3))" << endl;
    itr = search_n(i1223.begin(), i1223.end(), 3, 3);
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;

    cout << R"(search_n([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), 2, 2), issame)" << endl;
    itr = search_n(i1223.begin(), i1223.end(), 2, 2, issame);
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;

    cout << R"(search_n([1, 2, 2, 3].begin(), [1, 2, 2, 3].end(), 3, 3, issame))" << endl;
    itr = search_n(i1223.begin(), i1223.end(), 3, 3, issame);
    cout << "Return:\t";
    cout << getitrstring(i1223, itr) << endl << endl;
}