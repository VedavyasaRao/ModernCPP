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

string printheap(vector<int>& iv)
{
    ostringstream ss;

    size_t j = 0;
    size_t i = 0;
    size_t k = 0;
    ss << "{";
    while (i < iv.size())
    {
    	ss << iv[i];
    	if (i == k)
	{
            ss << "} {";
	    ++j;
	    k += (size_t)pow(2, j);
	}
	else
    	    ss << ", ";
	    ++i;
    }
    auto s = ss.str();
    s.pop_back();
    s.pop_back();
    if (*(s.end() - 1) != '}')
    s.push_back('}');
    return "[" + s + "]";
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
    vector<int> i1234567 = { 1,2,3,4,5,6,7 };
    cout << boolalpha;


    cout << "make_heap  ([1,2,3,4,5,6,7].begin(), [1,2,3,4,5,6,7].end())";
    cout << endl;
    make_heap(i1234567.begin(), i1234567.end());
    cout << "Return:\t";
    cout << printheap(i1234567);
    cout << endl << endl;

    i1234567 = { 1,2,3,4,5,6,7 };
    cout << "make_heap  ([1,2,3,4,5,6,7].begin(), [1,2,3,4,5,6,7].end(), greater<int>())";
    cout << endl;
    make_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "Return:\t";
    cout << printheap(i1234567);
    cout << endl << endl;

    make_heap(i1234567.begin(), i1234567.end());
    cout << "sort_heap  ([{7} {5, 6} {4, 2, 1, 3}].begin(), [{7} {5, 6} {4, 2, 1, 3}].end())";
    cout << endl;
    sort_heap(i1234567.begin(), i1234567.end());
    cout << "Return:\t";
    cout << printvector(i1234567);
    cout << endl << endl;

    make_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "sort_heap  ([{1} {2, 3} {4, 5, 6, 7}].begin(), [{1} {2, 3} {4, 5, 6, 7}].end(), greater<int>())";
    cout << endl;
    sort_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i1234567);
    cout << endl << endl;

    i1234567 = { 1,2,3,4,5,6,7 };
    cout << "is_heap ([{1} {2, 3} {4, 5, 6, 7}].begin(), [{1} {2, 3} {4, 5, 6, 7}].end())";
    cout << endl;
    cout << "Return:\t";
    cout << is_heap(i1234567.begin(), i1234567.end());
    cout << endl << endl;

    cout << "is_heap ([{1} {2, 3} {4, 5, 6, 7}].begin(), [{1} {2, 3} {4, 5, 6, 7}].end(), greater<int>())";
    cout << endl;
    cout << "Return:\t";
    cout << is_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << endl << endl;

    make_heap(i1234567.begin(), i1234567.end());
    cout << "pop_heap ([{7} {5, 6} {4, 2, 1, 3}].begin(), [{7} {5, 6} {4, 2, 1, 3}].end())";
    cout << endl;
    pop_heap(i1234567.begin(), i1234567.end());
    cout << "Return:\t";
    cout << printvector(i1234567);
    cout << endl << endl;

    cout << "is_heap_until ([{6} {5, 4} {1, 3, 2}, 7].begin(), [{6} {5, 4} {1, 3, 2}, 7].end())";
    cout << endl;
    auto itr = is_heap_until(i1234567.begin(), i1234567.end());
    cout << "Return:\t";
    cout << printvector(i1234567, itr);
    cout << endl << endl;

    cout << "push_heap ([{6} {5, 4} {2, 1, 3}, 7].begin(), [{6} {5, 4} {2, 1, 3}, 7].end())";
    cout << endl;
    push_heap(i1234567.begin(), i1234567.end());
    cout << "Return:\t";
    cout << printheap(i1234567);
    cout << endl << endl;

    make_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "pop_heap ([{1} {2, 3} {4, 5, 6, 7}].begin(), [{1} {2, 3} {4, 5, 6, 7}].end(), greater<int>())";
    cout << endl;
    pop_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i1234567);
    cout << endl << endl;

    cout << "is_heap_until ([{2} {3, 4} {5, 6, 7}, 1].begin(), [{2} {3, 4} {5, 6, 7}, 1].end(), greater<int>())";
    cout << endl;
    itr = is_heap_until(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "Return:\t";
    cout << printvector(i1234567, itr);
    cout << endl << endl;

    cout << "push_heap ([{2} {3, 4} {5, 6, 7}, 1].begin(), [{2} {3, 4} {5, 6, 7}, 1].end(), greater<int>())";
    cout << endl;
    push_heap(i1234567.begin(), i1234567.end(), greater<int>());
    cout << "Return:\t";
    cout << printheap(i1234567);
    cout << endl << endl;

}
