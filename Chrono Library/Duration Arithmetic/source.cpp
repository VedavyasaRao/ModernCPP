#include <iostream>
#include <chrono>


template <typename T>
void print_duration(std::ostream& os, T t)
{
    os << "duration<" << t.count() << ", ratio<" << T::period::num << "," << T::period::den << ">>";
}

int main()
{
    std::cout << "zero:" << "\t";
    print_duration(std::cout, std::chrono::seconds::zero());
    std::cout << std::endl;

    std::cout << "min:" << "\t";
    print_duration(std::cout, std::chrono::seconds::min());
    std::cout << std::endl;

    std::cout << "max:" << "\t";
    print_duration(std::cout, std::chrono::seconds::max());
    std::cout << std::endl;
    std::cout << std::endl;


    std::chrono::duration<int>                      twentySeconds(20);
    std::cout << "twentySeconds:" << "\t";
    print_duration(std::cout, twentySeconds);
    std::cout << std::endl;

    std::chrono::duration<double, std::ratio<60>>    halfAMinute(0.5);
    std::cout << "halfAMinute:" << "\t";
    print_duration(std::cout, halfAMinute);
    std::cout << std::endl;

    std::chrono::duration<long, std::ratio<1, 1000>>  oneMillisecond(1);
    std::cout << "oneMillisecond:" << "\t";
    print_duration(std::cout, oneMillisecond);
    std::cout << std::endl;
    std::cout << std::endl;

    auto sum = twentySeconds + halfAMinute + oneMillisecond;
    std::cout << "twentySeconds + halfAMinute + oneMillisecond:" << std::endl;;
    print_duration(std::cout, sum);
    std::cout << std::endl;
    std::cout << std::endl;

    std::chrono::seconds secs =
    	std::chrono::duration_cast<std::chrono::seconds>(halfAMinute); 
    std::cout << "std::chrono::duration_cast<std::chrono::seconds>(halfAMinute):" << std::endl;
    print_duration(std::cout, secs);
    std::cout << std::endl;

    return 0;
}