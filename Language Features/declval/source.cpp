#include <iostream>
#include <utility>

struct Default
{
    int foo() const { return 1; }
};

struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

int main()
{
    // type of n1 is int
    decltype(Default().foo()) n1 = 1;  

    //  error: no default constructor            
    //  decltype(NonDefault().foo()) n2 = n1;   
    
    // type of n2 is int
    decltype(std::declval<NonDefault>().foo()) n2 = n1; 
    std::cout << "n1 = " << n1 << '\n'
		<< "n2 = " << n2 << '\n';
}