#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace chrono;


int main()
{
	using SC = system_clock;
	{
		auto crt_tt = time(nullptr);
		cout << "system_clock::to_time_t" << endl;
		cout << put_time(localtime(&crt_tt), "%c") << endl;
		cout << "time(nullptr)\t\t\t:" << crt_tt << endl;
		cout << "SC::to_time_t(SC::now())\t:" << SC::to_time_t(SC::now()) << endl;
		cout << endl;

	}

	{
		tm tm{}; // Zero initialise
		tm.tm_year = 2018 - 1900; // 2018
		tm.tm_mon = 9 - 1; // September
		tm.tm_mday = 21; // 21st
		tm.tm_hour = 11;
		tm.tm_min = 48;
		tm.tm_isdst = 0; // Not daylight saving
		time_t crt_tt = mktime(&tm);

		cout << endl;
		cout << "system_clock::from_time_t" << endl;
		cout << R"xx(mktime("09/21/18 11:48:00"))xx" << "\t\t\t:" << crt_tt << endl;
		cout << R"xx(duration_cast<seconds>
(SC::from_time_t(mktime("09/21/18 11:48:00"))
.time_since_epoch()))xx" << "\t\t\t\t:" 
<< duration_cast<seconds>(SC::from_time_t(crt_tt).time_since_epoch()).count() << endl;

	}

	return 0;
}