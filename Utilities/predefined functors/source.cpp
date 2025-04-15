#include <iostream>     // std::cout
#include <functional>   // std::binary_negate, std::equal_to


using namespace std;


int main () 
{
    cout << hex << boolalpha << showbase;
    cout << "**** bitwise ****" << endl;
    cout << "bit_and{}(0xff,0x0c)\t\t= " << bit_and{}(0xff,0x0c) << endl;
    cout << "bit_or{}(0xf0,0x0c)\t\t= " << bit_or{}(0xf0,0x0c) << endl;
    cout << "bit_xor{}(0xff,0x0c)\t\t= " << bit_xor{}(0xff,0x0c) << endl;
    cout <<  endl;

    cout << "**** relational ****" << endl;
    cout << "not_equal_to{}(10,2)\t\t= " << not_equal_to{}(10,2) << endl;
    cout << "equal_to{}(10,2)\t\t= " << equal_to{}(10,2) << endl;
    cout << "greater{}(10,2)\t\t\t= " << greater{}(10,2) << endl;
    cout << "greater_equal{}(10,2)\t\t= " << greater_equal{}(10,2) << endl;
    cout << "less{}(10,2)\t\t\t= " << less{}(10,2) << endl;
    cout << "less_equal{}(10,2)\t\t= " << less_equal{}(10,2) << endl;
    cout <<  endl;

    cout << "**** logical ****" << endl;
    cout << "logical_and{}(true,false)\t= " << logical_and{}(true,false) << endl;
    cout << "logical_not{}(true)\t\t= " << logical_not{}(true) << endl;
    cout << "logical_or{}(true,false)\t= " << logical_or{}(true,false) << endl;
    cout <<  endl;

    cout << dec;
    cout << "**** arithmatic ****" << endl;
    cout << "minus{}(10,2)\t\t\t= " << minus{}(10,2) << endl;
    cout << "modulus{}(10,2)\t\t\t= " << modulus{}(10,2) << endl;
    cout << "multiplies{}(10,2)\t\t= " << multiplies{}(10,2) << endl;
    cout << "negate{}(10)\t\t\t= " << negate{}(10) << endl;
    cout << "divides{}(10,2)\t\t\t= " << divides{}(10,2) << endl;
    cout << "plus{}(10,2)\t\t\t= " << plus{}(10,2) << endl;
}