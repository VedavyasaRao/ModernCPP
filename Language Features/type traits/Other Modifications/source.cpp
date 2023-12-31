#include <iostream>
#include <type_traits>
#include <cstring>
#include <string>


// 1. the return type (bool) is only valid if T is an integral type. Won't compile otherwise.
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i)
{
    return bool((i % 2) == 1);
}

// 2. the second template argument is only valid if T is an integral type. Won't compile otherwise.
template < class T,
	class = typename std::enable_if<std::is_integral<T>::value>::type>
	bool is_even(T i) { return bool((i % 2) == 0); }

int main()
{
    {
	std::cout << "common_type" << std::endl;
	struct Base {};
	struct Derived : Base {};

	typedef std::common_type<char, short, int>::type A;           // int
	typedef std::common_type<float, double>::type B;             // double
	typedef std::common_type<Derived, Base>::type C;             // Base
	typedef std::common_type<Derived*, Base*>::type D;           // Base*
	typedef std::common_type<const int, volatile int>::type E;   // int

	std::cout << R"(common_type<char, short, int>)" << "\t\t:" << typeid(A).name() << std::endl;
	std::cout << R"(common_type<float, double>)" << "\t\t:" << typeid(B).name() << std::endl;
	std::cout << R"(common_type<Derived, Base>)" << "\t\t:" << typeid(C).name() << std::endl;
	std::cout << R"(common_type<Derived*, Base*>)" << "\t\t:" << typeid(D).name() << std::endl;
	std::cout << R"(common_type<const int, volatile int>)" << "\t:"  << typeid(E).name() << std::endl;
    }
    std::cout << std::endl;

    {
	std::cout << "conditional" << std::endl;
	typedef std::conditional<true, int, float>::type A;  // int
	typedef std::conditional<false, int, float>::type B; // float

	std::cout << R"(conditional<true, int, float>)" << "\t\t:" << typeid(A).name() << std::endl;
	std::cout << R"(conditional<false, int, float>)" << "\t\t:" << typeid(B).name() << std::endl;
    }
    std::cout << std::endl;

    {
	std::cout << "decay" << std::endl;
	typedef std::decay<int>::type A;           // int
	typedef std::decay<int&>::type B;          // int
	typedef std::decay<int&&>::type C;         // int
	typedef std::decay<const int&>::type D;    // int
	typedef std::decay<int[2]>::type E;        // int*
	typedef std::decay<int(int)>::type F;      // int(*)(int)


        std::cout << R"(decay<int>)" << "\t\t:" << typeid(A).name() << std::endl;
	std::cout << R"(decay<int&>)" << "\t\t:" << typeid(B).name() << std::endl;
	std::cout << R"(decay<int&&>)" << "\t\t:" << typeid(C).name() << std::endl;
	std::cout << R"(decay<const int&>)" << "\t:" << typeid(D).name() << std::endl;
	std::cout << R"(decay<int[2]>)" << "\t\t:" << typeid(E).name() << std::endl;
	std::cout << R"(decay<int(int)>)" << "\t\t:" << typeid(F).name() << std::endl;
    }
    std::cout << std::endl;

    {
	std::cout << "enable_if" << std::endl;

	std::cout << R"(template <class T> 
typename std::enable_if<std::is_integral<T>::value, bool>::type 
is_odd(T))" << std::endl;

		
	std::cout << R"(template <class T,
class = typename std::enable_if<std::is_integral<T>::value>::type> 
bool is_even(T))" << std::endl;

    }
    std::cout << std::endl;

    {
        std::cout << "underlying_type" << std::endl;

	enum class traffic_singnal { red, green, blue };
	enum rainbow : short { violet, indigo, blue, green, yellow, orange, red };

	typedef std::underlying_type<traffic_singnal>::type A;   // int
	typedef std::underlying_type<rainbow>::type B;   // short

	std::cout << R"(underlying_type<traffic_singnal>::type)" << "\t:" << typeid(A).name() << std::endl;
	std::cout << R"(underlying_type<rainbow>::type)" << "\t\t:" << typeid(B).name() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}