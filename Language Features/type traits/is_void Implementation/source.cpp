#include <iostream>
#include <type_traits>

template<class _Ty>
struct is_void
	: std::false_type
{	// determine whether _Ty is void
};

template<>
struct is_void<void>
	: std::true_type
{	/* determine whether _Ty is void */
};

//usage
int main()
{
    std::cout << std::boolalpha;
    {
        std::cout << "is_void:" << std::endl;
    	std::cout << "is_void<int*>::value" << "\t:"  << is_void<int*>::value << std::endl;
    	std::cout << "is_void<void>::value" << "\t:" << is_void<void>::value << std::endl;
    	std::cout << "is_void<long>::value" << "\t:" << is_void<int*>::value << std::endl;
    }
    std::cout << std::endl;

    return (0);
}
