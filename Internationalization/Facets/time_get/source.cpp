#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

ostream& operator << (ostream& os, const time_base::dateorder& dord)
{
    switch (dord)
    {
        case time_base::no_order: os << "no_order\n"; break;
        case time_base::dmy: os << "day, month, year\n"; break;
        case time_base::mdy: os << "month, day, year\n"; break;
        case time_base::ymd: os << "year, month, day\n"; break;
        case time_base::ydm: os << "year, day, month\n"; break;
    }
    return os;
}


 
int main()
{
    map<string,string> times = {{"en_US.utf-8","09:23:38 PM"}, {"ja_JP.utf8","21時23分38秒"},{"de_DE.utf-8","21:23:38"}};
    map<string,string> dates = {{"en_US.utf-8","05/05/2023"}, {"ja_JP.utf8","2023年05月05日"},{"de_DE.utf-8","05.05.2023"}};
    map<string,string> weekday = {{"en_US.utf-8","Friday"}, {"ja_JP.utf8","金曜日"},{"de_DE.utf-8","Freitag"}};
    map<string,string> months = {{"en_US.utf-8","May"}, {"ja_JP.utf8","5月"},{"de_DE.utf-8","Mai"}};
    map<string,vector<string>> fulldates = {{"en_US.utf-8",{"2023-may-18 23:12:34","%Y-%b-%d %H:%M:%S"}}, 
    {"ja_JP.utf8",{"2023年05月05日 21時23分38秒","%Y年%m月%d日 %H時%M分%S秒"}},
    {"de_DE.utf-8",{"2023-mai-18 23:12:34","%Y-%b-%d %H:%M:%S"}}};

    for (auto ln:{"en_US.utf-8","ja_JP.utf8","de_DE.utf-8"})
    {
        auto l = locale(ln);
        auto &f = use_facet<time_get<char>>(l);
        cout.imbue(l);
        cout << "Locale is " << l.name() << endl;
        cout <<  "date_order()" <<endl;
        cout << "The default date order is: ";
        cout << f.date_order();


        {
            cout <<  "get_time(\"" << times[ln] << "\")" << endl;
            tm t={};
            istringstream iss(times[ln]);
            iss.imbue(l);
            ios_base::iostate err = ios_base::goodbit;
            istreambuf_iterator<char> ret = f.get_time({iss}, {}, iss, err, &t);
            iss.setstate(err);
            if (iss)
                cout << "Hours: "   << t.tm_hour << ", Minutes: " << t.tm_min  << ", SSeconds: " << t.tm_sec  << endl;
            else
                cout << "Parse failed" << endl;
        }
        
        {
            cout <<  "get_date(\"" << dates[ln] << "\")" << endl;
            tm t={};
            istringstream iss(dates[ln]);
            iss.imbue(l);
            ios_base::iostate err = ios_base::goodbit;
            istreambuf_iterator<char> ret = f.get_date({iss}, {}, iss, err, &t);
            iss.setstate(err);
            if (iss)
                cout << "Day: "   << t.tm_mday << ", Month: " << t.tm_mon+1  << ", Year: " << t.tm_year+1900  << endl;
            else
                cout << "Parse failed" << endl;
        }

        {
            cout <<  "get_weekday(\"" << weekday[ln] << "\")" << endl;
            tm t={};
            istringstream iss(weekday[ln]);
            iss.imbue(l);
            ios_base::iostate err = ios_base::goodbit;
            istreambuf_iterator<char> ret = f.get_weekday({iss}, {}, iss, err, &t);
            iss.setstate(err);
            if (iss)
                cout << "Week Day: "   << t.tm_wday << endl;
             else
                cout << "Parse failed" << endl;
        }

        {
            cout <<  "get_monthname(\"" << months[ln] << "\")" << endl;
            tm t={};
            istringstream iss(months[ln]);
            iss.imbue(l);
            ios_base::iostate err = ios_base::goodbit;
            istreambuf_iterator<char> ret = f.get_monthname({iss}, {}, iss, err, &t);
            iss.setstate(err);
            if (iss)
                cout << "Month: "   << t.tm_mon+1 << endl;
             else
                cout << "Parse failed" << endl;
        }

        {
            cout <<  "get_year(\"" << "23" << "\")" << endl;
            tm t={};
            istringstream iss("23");
            iss.imbue(l);
            ios_base::iostate err = ios_base::goodbit;
            istreambuf_iterator<char> ret = f.get_year({iss}, {}, iss, err, &t);
            iss.setstate(err);
            if (iss)
                cout << "Year: "   << t.tm_year+1900 << endl;
             else
                cout << "Parse failed" << endl;
        }

         {
            cout <<  "get(\"" << fulldates[ln][0] << "\")" << endl;
            tm t={};
            string d = fulldates[ln][0];
            istringstream iss(d);
            ios_base::iostate err = std::ios_base::goodbit;
            iss.imbue(l);
            string s = fulldates[ln][1];
            auto ret = f.get({iss}, {}, iss, err, &t, &s[0], &s[0] + s.size());
            iss.setstate(err);
            if (iss)
                cout << "parsed date is : "  << put_time(&t, "%c")  << endl;
             else
                cout << "Parse failed" << endl;
        }

        cout << endl;
    }
} 