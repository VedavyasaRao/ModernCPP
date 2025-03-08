//sets classic C locale
cin.imbue(locale::classic());

//sets global locale
cout.imbue(locale());

//sets a specific locale
cerr.imbue(locale("en_US.ISO8859-1"));

//to print unicode letters in filestream in windows
ofstream ofs("output.txt");
ofs.imbue(locale(locale("kn_IN"), new codecvt_utf8<wchar_t>()));
