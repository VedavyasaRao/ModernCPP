#include <iostream>
#include <type_traits>
#include <cstring>

int main()
{
    {
        std::cout << "align" << std::endl;
	struct A
	{  // non-POD type
	    int avg;
	    A(int a, int b) : avg((a + b) / 2) {}
	};

	typedef std::aligned_storage<sizeof(A), alignof(A)>::type A_pod;

	std::cout << R"(
struct A
{  // non-POD type
	int avg;
	A(int a, int b) : avg((a + b) / 2) {}
};

std::aligned_storage<sizeof(A), alignof(A)>::type A_pod;
	)" << std::endl;
	A_pod a;
	new (&a) A(10, 20);
	auto avg = reinterpret_cast<A&>(a).avg;
    }

    std::cout << std::endl;

    {
        union U
	{
	    int i;
    	    char c;
	    double d;
	    U(const char* str) : c(str[0]) {}
	};   // non-POD

	typedef std::aligned_union<sizeof(U), int, char, double>::type U_pod;

	std::cout << "aligned_union" << std::endl;
        std::cout << R"(
union U
{
	int i;
	char c;
	double d;
	U(const char* str) : c(str[0]) {}
};   // non-POD

std::aligned_union<sizeof(U), int, char, double>::type U_pod;
)";

        U_pod a;              // default-initialized (ok: type is POD)
        memset(&a, 0, sizeof a);
        new (&a) U("hello");   // call U's constructor in place
        auto i = reinterpret_cast<U&>(a).i;
    }
    return 0;
}
