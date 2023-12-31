#include <iostream>
#include <string>
#include <chrono>


template <typename C>
void print_clock_info(std::ostream& os, const std::string& name)
{
    os << name << std::endl;
    os << "Monotonic\t:" << std::boolalpha << C::is_steady << std::endl; 
    os << "Resolution\t:" << "ratio<" << C::period::num << "," << C::period::den << ">" << std::endl;
    os << "Now\t\t:" << std::chrono::duration_cast<std::chrono::seconds>(C::now().time_since_epoch()).count()  << " seconds" << std::endl;
}

int main()
{
    print_clock_info<std::chrono::system_clock>(std::cout, "system_clock");
    std::cout << std::endl;

    print_clock_info<std::chrono::steady_clock>(std::cout, "steady_clock");
    std::cout << std::endl;

    print_clock_info<std::chrono::high_resolution_clock>(std::cout, "high_resolution_clock");
    std::cout << std::endl;

    return 0;
}