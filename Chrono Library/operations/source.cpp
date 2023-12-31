#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main()
{

    typedef duration<int, std::ratio<60 * 60 * 24>> days_type;

    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
    std::cout << "current days since epoch\t:" <<  today.time_since_epoch().count() <<  std::endl;
    std::cout << "min days since epoch\t\t:" << today.min().time_since_epoch().count() << std::endl;
    std::cout << "max days since epoch\t\t:" << today.max().time_since_epoch().count()  << std::endl;

    return 0;
}