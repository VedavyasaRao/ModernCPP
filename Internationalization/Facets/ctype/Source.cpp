#include <locale>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
	wstring str = L"ಖ್ರಿಷಾ Rao ೨೧/೦೯/೧೮";
	wofstream ofs("output.txt");
	// classify every character in a string using a named locale
	auto loc = locale("kn_IN.UTF-8");
	ofs.imbue(loc);
	auto& f = use_facet<ctype<wchar_t>>(loc);
	auto locname = loc.name();
	vector<wchar_t> wcharvec(1000, L'\0');
	f.widen(&locname[0], &locname[0] + locname.size(), wcharvec.data());
	ofs << "widen() of locale name string \"kn_IN.UTF-8\" is " << wcharvec.data() << endl;
	ofs << "narrow() of the string \"" << str << "\" is ";
	vector<char> buf(1000, '\0');
	f.narrow(&str[0], &str[0] + str.size(), '?', buf.data());
	ofs << '"' << buf.data() << '"' << endl;

	ofs << "Character classifications is() of each letter in \"" << str << "\"" << endl;
	vector<ctype_base::mask> vec(str.size());
	f.is(&str[0], &str[0] + str.size(), &vec[0]);

	for (size_t n = 0; n < str.size(); ++n) {
		ofs  << str[n] << " is: ";
		if (vec[n] & ctype_base::alnum)
			ofs << " alnum ";
		if (vec[n] & ctype_base::alpha)
			ofs << " alpha ";
		if (vec[n] & ctype_base::cntrl)
			ofs << " cntrl ";
		if (vec[n] & ctype_base::graph)
			ofs << " graph ";
		if (vec[n] & ctype_base::lower)
			ofs << " lower ";
		if (vec[n] & ctype_base::print)
			ofs << " print ";
		if (vec[n] & ctype_base::punct)
			ofs << " punct ";
		if (vec[n] & ctype_base::space)
			ofs << " space ";
		if (vec[n] & ctype_base::upper)
			ofs << " upper ";
		if (vec[n] & ctype_base::xdigit)
			ofs << " xdigit ";
		if (vec[n] & ctype_base::blank)
			ofs << " blank ";
		ofs << endl;
	}

	const wchar_t* p1 = f.scan_is(ctype_base::upper, &str[0], &str[0] + str.size());
	ofs << "first scan_is() of alphabet in \"" << str << "\" is '" << p1[0]  << "'" << endl;

	const wchar_t* p2 = f.scan_not((ctype_base::alpha|ctype_base::space), p1, p1+wcslen(p1));
	ofs << "first scan_not() of non alphabet alnum in \"" << p1 << "\" is '" << p2[0] << "'" << endl;

	wstring str2 = str;
	ofs << "upper() of the string \"" << str << "\" is ";
	f.toupper(&str2[0], &str2[0] + str2.size());
	ofs << '"' << str2 << '"' << endl;

	str2 = str;
	ofs << "lower() of the string \"" << str << "\" is ";
	f.tolower(&str2[0], &str2[0] + str2.size());
	ofs << '"' << str2 << '"' << endl;
}
