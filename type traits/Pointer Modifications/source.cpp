#include <iostream>
#include <type_traits>
#include <cstring>
#include <string>


int main()
{
    {
        std::cout << "add_pointer" << std::endl;
	typedef std::add_pointer<int>::type A;        // int*
	typedef std::add_pointer<const int>::type B;  // const int*
	typedef std::add_pointer<int&>::type C;       // int*
	typedef std::add_pointer<int*>::type D;       // int**
	typedef std::add_pointer<int(int)>::type E;   // int(*)(int)

	std::cout << R"(add_pointer<int>::type)" << "\t\t:" << typeid(A).name() << std::endl;
	std::cout << R"(add_pointer<const int>::type)" <<  "\t:" << typeid(B).name() << std::endl;
	std::cout << R"(add_pointer<int&>::type)" <<  "\t\t:" << typeid(C).name() << std::endl;
	std::cout << R"(add_pointer<int*>::type)" <<  "\t\t:" << typeid(D).name() << std::endl;
	std::cout << R"(add_pointer<int(int)>::type)" <<  "\t:" << typeid(E).name() << std::endl;
    }
    std::cout << std::endl;

    {
	std::cout << "remove_pointer" << std::endl;
	typedef std::remove_pointer<int>::type A;          // int
	typedef std::remove_pointer<int*>::type B;         // int
	typedef std::remove_pointer<int**>::type C;        // int*
	typedef std::remove_pointer<const int*>::type D;   // const int
	typedef std::remove_pointer<int* const>::type E;   // int


	std::cout << R"(remove_pointer<int>::type)" << "\t\t:" << typeid(A).name() << std::endl;
	std::cout << R"(remove_pointer<int*>::type)" << "\t\t:" << typeid(B).name() << std::endl;
	std::cout << R"(remove_pointer<int**>::type)" << "\t\t:" << typeid(C).name() << std::endl;
	std::cout << R"(remove_pointer<const int*>::type)" << "\t:" << typeid(D).name() << std::endl;
	std::cout << R"(remove_pointer<int* const>::type)" << "\t:" << typeid(E).name() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
