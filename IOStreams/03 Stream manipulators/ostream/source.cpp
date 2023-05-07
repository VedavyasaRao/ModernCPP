#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    cout << "****************************" << endl;
    cout << "ios::manipulators for ostream" << endl;
    cout << "****************************" << endl << endl;

    cout << "boolalpha example" << endl;
    cout << boolalpha << "true is:" << true << endl
        << "false is:" << false << endl << endl;
    
    cout << "noboolalpha example" << endl;
    cout << noboolalpha << "true is:" << true << endl
        << "false is:" << false << endl << endl;
    
    cout << "showpos example" << endl;
    cout << showpos << "1:" << 1 << endl << endl;
    
    cout << "noshowpos example" << endl;
    cout << noshowpos << "1:" << 1 << endl << endl;

    cout << showbase;
    cout << "uppercase example" << endl;
    cout << "1234: " << uppercase << hex << 1234 << endl << endl;
    
    cout << "nouppercase example" << endl;
    cout << "1234: " << nouppercase << hex << 1234 << endl << endl;

    cout << "oct hex dec example" << endl;
    cout << "1234 in " << showbase << endl
        << "oct:" << oct << 1234 << endl 
        << "dec:" << dec << 1234 << endl 
        << "hex:" << hex << 1234  
        << endl << endl;

    cout << "showbase example" << endl;
    cout << "1234: " << showbase << hex << 1234 << endl << endl;
    
    cout << "noshowbase example" << endl;
    cout << "1234: " << noshowbase << hex << 1234 << endl << endl;

    cout << dec << fixed;
    cout << "setprecision(3) example" << endl;
    cout << "1234.56795: "  << setprecision(3) << 1234.56795 << endl << endl;
    
    cout << dec << setprecision(0);
    cout << "showpoint example" << endl;
    cout << "1234.0: " << showpoint  << 1234.0 << endl << endl;
   
    cout << "noshowpoint example" << endl;
    cout << "1234.0: " << noshowpoint << 1234.0 << endl << endl;

    cout << "left right internal example" << endl;
    cout << setw(10) << setfill('$'); 
    cout << "1234 with setw(10) setfill('$') "  << endl
        << "left:"  
        << setw(10) << setfill('$') << left << 1234 << endl 
        << "right:" 
        << setw(10) << setfill('$') <<  right << 1234 << endl 
        << "internal:" 
        << setw(10) << setfill('$') << internal << 1234  
        << endl << endl;

    cout << "fixed scientific hexfloat defaultfloat example" << endl;
    cout << "1234.56 in "  << endl
        << "fixed:"  
        << setprecision(2) 
        << fixed << 1234.56 << endl 
        << "scientific:" 
        <<  scientific << 1234.56 << endl 
        << "hexfloat:" 
        << hexfloat << 1234.56  << endl 
        << "defaultfloat:" 
        << defaultfloat << 1234.56  
        << endl << endl;

    cout << "put_money example" << endl;
    cout.imbue(locale("en_US.UTF-8"));
    cout << showbase
              << "en_US: " << put_money(1234)
              << " or " << put_money(1234, true) << endl << endl;

    cout << "put_time example" << endl;   
    time_t t = std::time(nullptr);
    tm tm = *localtime(&t);
     cout << "en_US: " << put_time(&tm, "%c %Z") << endl << endl;

  cout << "quoted example" << endl;   
  string in = "quoted() quotes this string and embedded \"quotes\" too";
  stringstream ss;
  ss << quoted(in);
  string out;
  ss >> quoted(out);
 
  cout << "Default delimiter case:" << endl
              <<   "read in     [" << in << "]" << endl
              <<   "stored as   [" << ss.str() << "]" << endl
              <<   "written out [" << out << "]" 
               << endl << endl;
 
  const char delim {'$'};
  const char escape {'%'};
 
  in = "quoted() quotes this string and embedded $quotes$ $too";
  ss = stringstream();
  ss << quoted(in, delim, escape);
  ss >> quoted(out, delim, escape);
 
  cout << "Custom delimiter case:" << endl
            <<   "read in     [" << in << "]" << endl
            <<     "stored as   [" << ss.str() << "]" << endl
            <<     "written out [" << out << "]" 
               << endl << endl;
 
    return 0;
}