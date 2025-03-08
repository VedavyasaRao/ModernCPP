#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <cuchar>
#include <cwchar>
#include <climits>
#include <clocale>

using namespace std;
//ಖ್ರಿಷಾ Rao👸

string printvector(string& iv)
{
	return  '[' + iv + ']';
}

string getitrstring(string& iv, string::iterator& itr)
{
	return  printvector(iv) + ((itr != iv.end()) ? ".begin()+" + to_string(distance(iv.begin(), itr)) : ".end()");
}

string UTF32toNarrow(const u32string& strv)
{
	string outs;
	mbstate_t state{};
	char out[MB_LEN_MAX]{};
	for (char32_t c : strv)
	{
		size_t rc = c32rtomb(out, c, &state);
		if (rc != (size_t)-1)
			for (unsigned char c8 : string{ out, rc })
				outs.push_back(c8);
	}
	return outs;
}




int main()
{
	string s("khrisha rao");
	string s2("khrisha");
	string s3(" rao");
	string s4;

	setlocale(LC_ALL, "en_US.utf8");
	cout << boolalpha;
	cout << "append(const string& s)" << endl;
	cout << "[khrisha].append([ rao])\t\t\t\t\t\t = [";
	s = s2;
	s.append(s3);
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(const string& s, size_t p, size_t n)" << endl;
	cout << "[khrisha].append([ rao],0,string::npos)\t\t\t\t\t = [";
	s = s2;
	s.append(s3, 0, string::npos);
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(const char* s)" << endl;
	cout << R"([khrisha].append(" rao"))" << "\t\t\t\t\t\t = [";
	s = s2;
	s.append(s3, 0, string::npos);
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(const  char* s, size_t n)" << endl;
	cout << R"([khrisha].append(" rao",4))" << "\t\t\t\t\t\t = [";
	s = s2;
	s.append(s3.data(), 4);
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(size_t n, char c)" << endl;
	cout << R"([khrisha].append(4,'a'))" << "\t\t\t\t\t\t\t = [";
	s = s2;
	s.append(4, 'a');
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(InputIterator b, InputIterator e)" << endl;
	cout << R"([khrisha].append([ rao].begin(),[ rao].end()))" << "\t\t\t\t = [";
	s = s2;
	s.append(s3.begin(), s3.end());
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "append(initializer_list<char> il)" << endl;
	cout << R"([khrisha].append({' ','r','a','o'}))" << "\t\t\t\t\t = [";
	s = s2;
	s.append({ ' ', 'r', 'a', 'o' });
	cout << s;
	cout << "]";
	cout << endl << endl;

	cout << "assign(const string& s)" << endl;
	cout << "[].assign([khrisha rao])\t\t\t\t\t\t = [";
	s4.assign(s);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(const string& s, size_t p, size_t n)" << endl;
	cout << "[].assign([khrisha rao],0,string::npos)\t\t\t\t\t = [";
	s4.clear();
	s4.assign(s, 0, string::npos);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(const char* s)" << endl;
	cout << R"([].assign("khrisha rao"))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.assign("khrisha rao");
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(const char* s)" << endl;
	cout << R"([].assign("khrisha rao"))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.assign("khrisha rao");
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(const char* s, size_t n)" << endl;
	cout << R"([].assign("khrisha rao", 11))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.assign("khrisha rao", 11);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(size_t n, char c)" << endl;
	cout << R"([].assign(7,'k'))" << "\t\t\t\t\t\t\t = [";
	s4.clear();
	s4.assign(7, 'k');
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(InputIterator b, InputIterator e)" << endl;
	cout << R"([].assign([khrisha rao].begin(),[khrisha rao].end()))" << "\t\t\t = [";
	s4.clear();
	s4.assign(s.begin(), s.end());
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign(initializer_list<char> il)" << endl;
	cout << R"([].assign({'k','h','r','i','s','h','a',' ','r','a','o'})" << "\t\t\t = [";
	s4.clear();
	s4.assign({ 'k','h','r','i','s','h','a',' ','r','a','o' });
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "assign (string&& s)" << endl;
	cout << R"([].assign(move([khrisha rao]))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.assign(move(s));
	cout << s4;
	cout << "]";
	cout << endl << endl;
	s = s4;

	cout << "insert (size_t p, const string& s)" << endl;
	cout << "[].insert(0,[khrisha rao])\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, s);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (size_t p, const string& s, size_t sp, size_t n)" << endl;
	cout << "[].insert(0,[khrisha rao],0,11)\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, s, 0, 11);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (size_t p, const char* s)" << endl;
	cout << R"([].insert(0,"khrisha rao"))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, "khrisha rao");
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (size_t p, const char* s, size_t n)" << endl;
	cout << R"([].insert(0,"khrisha rao", 11))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, "khrisha rao", 11);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (size_t p, const char* s, size_t n)" << endl;
	cout << R"([].insert(0,"khrisha rao", 11))" << "\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, "khrisha rao", 11);
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (size_t p, size_t n, char c)" << endl;
	cout << R"([].insert(0, 7,'k'))" << "\t\t\t\t\t\t\t = [";
	s4.clear();
	s4.insert(0, 7, 'k');
	cout << s4;
	cout << "]";
	cout << endl << endl;

	cout << "insert (const_iterator p, size_t n, char c)" << endl;
	cout << R"([].insert([].begin(), 7,'k'))" << "\t\t\t\t\t\t = ";
	s4.clear();
	auto itr = s4.insert(s4.begin(), 7, 'k');
	cout << getitrstring(s4, itr);
	cout << endl << endl;

	cout << "insert (const_iterator p, char c)" << endl;
	cout << R"([].insert([].begin(), 'k'))" << "\t\t\t\t\t\t = ";
	s4.clear();
	itr = s4.insert(s4.begin(), 'k');
	cout << getitrstring(s4, itr);
	cout << endl << endl;

	cout << "insert (iterator p, InputIterator b, InputIterator e)" << endl;
	cout << R"([].insert([].begin(), 
[khrisha rao].begin(), [khrisha rao].end()))" << "\t\t\t\t = ";
	s4.clear();
	itr = s4.insert(s4.begin(), s.begin(), s.end());
	cout << getitrstring(s4, itr);
	cout << endl << endl;

	cout << "insert(iterator p, initializer_list<char> il)" << endl;
	cout << R"([].insert([].begin(),
{'k','h','r','i','s','h','a',' ','r','a','o'})" << "\t\t\t\t = ";
	s4.clear();
	itr = s4.insert(s4.begin(), { 'k','h','r','i','s','h','a',' ','r','a','o' });
	cout << getitrstring(s4, itr);
	cout << endl << endl;

	cout << "erase ()" << endl;
	cout << R"([khrisha rao].erase())" << "\t\t\t\t\t\t\t = [";
	s.erase();
	cout << s;
	cout << "]";
	cout << endl << endl;

	s = "khrisha rao";
	cout << "erase (size_t p, size_t n)" << endl;
	cout << R"([khrisha rao].erase(0, 11))" << "\t\t\t\t\t\t = [";
	s.erase(7, 4);
	cout << s;
	cout << "]";
	cout << endl << endl;

	s = "khrisha rao";
	cout << "erase (const_iterator p)" << endl;
	cout << R"([khrisha rao].erase([khrisha rao].begin()+7))" << "\t\t\t\t = ";
	itr = s.erase(s.begin() + 7);
	cout << getitrstring(s, itr);
	cout << endl << endl;

	s = "khrisha rao";
	cout << "erase (const_iterator b, const_iterator e)" << endl;
	cout << R"([khrisha rao].erase(
[khrisha rao].begin()+7, [khrisha rao].end()))" << "\t\t\t\t = ";
	itr = s.erase(s.begin() + 7, s.end());
	cout << getitrstring(s, itr);
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t p, size_t n, const string& s)" << endl;
	cout << R"([khrishaxxxx].replace(7, 4, [ rao]))" << "\t\t\t\t\t = ";
	s.replace(7, 4, s3);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, const string& s)" << endl;
	cout << R"([khrishaxxxx].replace(
[khrishaxxxx].begin()+7, [khrishaxxxx].end(), [ rao]))" << "\t\t\t = ";
	s.replace(s.begin() + 7, s.end(), s3);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t p, size_t n, const string& s, size_t sp, size_t sn)" << endl;
	cout << R"([khrishaxxxx].replace(7, 4, [ rao], 0, 4))" << "\t\t\t\t = ";
	s.replace(7, 4, s3, 0, 4);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t p, size_t n, const char* s)" << endl;
	cout << R"([khrishaxxxx].replace(7, 4, " rao", 0, 4))" << "\t\t\t\t = ";
	s.replace(7, 4, " rao");
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, const char* s)" << endl;
	cout << R"([khrishaxxxx].replace(
[khrishaxxxx].begin()+7, [khrishaxxxx].end(), " rao"))" << "\t\t\t = ";
	s.replace(s.begin() + 7, s.end(), " rao");
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t p, size_t n, const char* s, size_t sn)" << endl;
	cout << R"([khrishaxxxx].replace(7, 4, " rao", 4))" << "\t\t\t\t\t = ";
	s.replace(7, 4, " rao", 4);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t p, size_t n, const char* s, size_t sn)" << endl;
	cout << R"([khrishaxxxx].replace(7, 4, " rao", 4))" << "\t\t\t\t\t = ";
	s.replace(7, 4, " rao", 4);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, const char* s, size_t n)" << endl;
	cout << R"([khrishaxxxx].replace(
[khrishaxxxx].begin()+7, [khrishaxxxx].end(), " rao", 4))" << "\t\t = ";
	s.replace(s.begin() + 7, s.end(), " rao", 4);
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (size_t  pos, size_t len, size_t n, char c)" << endl;
	cout << R"([khrishaxxxx].replace(6, 5, 6, 'a'))" << "\t\t\t\t\t = ";
	s.replace(6, 5, 6, 'a');
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, size_t n, char c)" << endl;
	cout << R"([khrishaxxxx].replace(
[khrishaxxxx].begin()+7, [khrishaxxxx].end(), 6,'a'))" << "\t\t\t = ";
	s.replace(s.begin() + 7, s.end(), 6, 'a');
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, InputIterator  b, InputIterator e)" << endl;
	cout << R"([khrishaxxxx].replace([khrishaxxxx].begin()+7, [khrishaxxxx].end(), 
[ rao].begin(), [ rao].end()))" << "\t\t\t\t\t\t = ";
	s.replace(s.begin() + 7, s.end(), s3.begin(), s3.end());
	cout << s;
	cout << endl << endl;

	s = "khrishaxxxx";
	cout << "replace (citerator i1, citerator i2, initializer_list<char> il)" << endl;
	cout << R"([khrishaxxxx].replace([khrishaxxxx].begin()+7, [khrishaxxxx].end(), 
{' ','r','a','o'}))" << "\t\t\t\t\t\t\t = ";
	s.replace(s.begin() + 7, s.end(), s3.begin(), s3.end());
	cout << s;
	cout << endl << endl;


	u32string u32s = U"ಖ್ರಿಷಾ Rao!";
	cout << "pop_back()" << endl;
	cout << R"([ಖ್ರಿಷಾ Rao!].pop_back())" << endl;
	u32s.pop_back();
	cout << "result:\t\t\t\t\t\t\t\t\t = " << UTF32toNarrow(u32s);
	cout << endl << endl;

	u32s = U"ಖ್ರಿಷಾ Rao";
	cout << "push_back(char c)" << endl;
	cout << R"([ಖ್ರಿಷಾ Rao].push_back('👸'))" << endl;
	u32s.push_back(U'👸');
	cout << "result:\t\t\t\t\t\t\t\t\t = " << UTF32toNarrow(u32s);
	cout << endl << endl;

	return 0;
}