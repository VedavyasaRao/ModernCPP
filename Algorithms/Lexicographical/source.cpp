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


int main()
{
    auto caseless = [](char a, char b) {return (tolower(a) < tolower(b)); };
    cout << boolalpha;

    string s = "ab", s2 = "abcd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end())";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end());
    cout << endl << endl;

    s = "abcD", s2 = "abcd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end())";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end());
    cout << endl << endl;

    s = "abc4", s2 = "abcD";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end())";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end());
    cout << endl << endl;

    s = "abcD", s2 = "abCd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end())";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end());
    cout << endl << endl;


    s = "ab", s2 = "abcd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end(), caseless)";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), caseless);
    cout << endl << endl;

    s = "abcD", s2 = "abcd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end(), caseless)";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), caseless);
    cout << endl << endl;

    s = "abc4", s2 = "abcD";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end(), caseless)";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), caseless);
    cout << endl << endl;

    s = "abcD", s2 = "abCd";
    cout << "lexicographical_compare(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(),";
    cout << "\"" << s2 << "\".begin(), " << "\"" << s2 << "\".end(), caseless)";
    cout << endl;
    cout << "Return:\t";
    cout << lexicographical_compare(s.begin(), s.end(), s2.begin(), s2.end(), caseless);
    cout << endl << endl;

    s = "abc";
    while (true)
    {
	cout << "next_permutation(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end())";
	cout << endl;
	bool b = next_permutation(s.begin(), s.end());
	cout << "Return:\t" << b;
	cout << endl;
	cout << "output:\t" << s;
	cout << endl << endl;
	if (!b)
            break;
    } 

    s = "abc";
    while (true)
    {
        cout << "next_permutation(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(), less<int>())";
	cout << endl;
	bool b = next_permutation(s.begin(), s.end(), less<int>());
	cout << "Return:\t" << b;
	cout << endl;
	cout << "output:\t" << s;
	cout << endl << endl;
	if (!b)
	    break;
    }

    s = "cba";
    while (true)
    {
	cout << "prev_permutation(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end())";
	cout << endl;
	bool b = prev_permutation(s.begin(), s.end());
	cout << "Return:\t" << b;
	cout << endl;
	cout << "output:\t" << s;
	cout << endl << endl;
	if (!b)
	    break;
    }

    s = "cba";
    while (true)
    {
	cout << "prev_permutation(" << "\"" << s << "\".begin(), " << "\"" << s << "\".end(), less<int>())";
	cout << endl;
	bool b = prev_permutation(s.begin(), s.end(), less<int>());
	cout << "Return:\t" << b;
	cout << endl;
	cout << "output:\t" << s;
	cout << endl << endl;
	if (!b)
	    break;
    }
}