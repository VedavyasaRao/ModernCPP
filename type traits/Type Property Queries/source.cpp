#include <iostream>
#include <type_traits>

int main() 
{
    {
        std::cout << "rank:" << std::endl;
	std::cout << "rank<int>::value" << "\t\t:" << std::rank<int>::value  << std::endl;
	std::cout << "rank<int[]>::value" << "\t\t:" << std::rank<int[]>::value << std::endl;
	std::cout << "rank<int[][10]>::value" << "\t\t:" << std::rank<int[][10]>::value << std::endl;
	std::cout << "rank<int[10][10]>::value" << "\t:" << std::rank<int[10][10]>::value << std::endl;
    }
    std::cout << std::endl;

    {
        std::cout << "alignment_of:" << std::endl;
	std::cout << "alignment_of<char>::value" << "\t\t:" << std::alignment_of<char>::value << std::endl;
	std::cout << "alignment_of<int>::value " << "\t\t:" << std::alignment_of<int>::value << std::endl;
	std::cout << "alignment_of<int[20]>::value" << "\t\t:" << std::alignment_of<int[20]>::value << std::endl;
	std::cout << "alignment_of<long long int>::value" << "\t:" << std::alignment_of<long long int>::value << std::endl;
    }
    std::cout << std::endl;

    {
        std::cout << "extent:" << std::endl;
	std::cout << "extent<int[][24][60], 0>::value" << "\t:" << std::extent<int[][24][60], 0>::value << std::endl;
	std::cout << "extent<int[][24][60], 1>::value" << "\t:" << std::extent<int[][24][60], 1>::value << std::endl;
	std::cout << "extent<int[][24][60], 2>::value" << "\t:" << std::extent<int[][24][60], 2>::value << std::endl;
	std::cout << "extent<int[][24][60], 3>::value" << "\t:" << std::extent<int[][24][60], 3>::value << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
