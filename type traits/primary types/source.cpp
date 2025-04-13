#include <type_traits>
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    {
        std::cout << "is_void" << std::endl;
	std::cout << "is_void<void *>::value" << "\t:" << std::is_void<void *>::value << std::endl;
	std::cout << "is_void<void>::value" << "\t:" << std::is_void<void>::value << std::endl;
    }
    std::cout << std::endl;

    {
        std::cout << "is_null_pointer" << std::endl;;
	std::cout << "is_null_pointer<int *>::value" << "\t\t:" << std::is_void<void *>::value << std::endl;
	std::cout << "is_null_pointer<nullptr_t>::value" << "\t:" << std::is_void<nullptr_t>::value << std::endl;
    }
    std::cout << std::endl;
	
    {
        std::cout << "is_integral" << std::endl;
	std::cout << "is_integral<int>::value" << "\t\t:" << std::is_integral<int>::value << std::endl;
	std::cout << "is_integral<char*>::value" << "\t:" << std::is_integral<char*>::value << std::endl;
    }
    std::cout << std::endl;

    {
	std::cout << "is_floating_point" << std::endl;
	std::cout << "is_floating_point<char*>" << "\t:" << std::is_floating_point<char*>::value << std::endl;
	std::cout << "is_floating_point<float>" << "\t:" << std::is_floating_point<float>::value << std::endl;
    }
    std::cout << std::endl;

    return (0);
}