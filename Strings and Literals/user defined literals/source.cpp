#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;


double  operator ""_Fahrenheit(long double deg )
{
    return (deg * 9/5.0) + 32.0;
}


double  operator ""_Fahrenheit(unsigned long long int deg )
{
    return operator ""_Fahrenheit(static_cast<long double>(deg));
}

int main()
{
   cout  << "24.5°C \t=  " << 24.5_Fahrenheit << "°F" << endl;
   cout  << "17°C \t=  " << 17_Fahrenheit << "°F" << endl;
}