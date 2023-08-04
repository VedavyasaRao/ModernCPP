#include <iostream>
using namespace std;

template<typename T>
bool validate(T t)
{
    cout << "validating:\t" << t << endl;
    return true;
}

template<typename ... Ts>
auto validate(Ts... ts)->initializer_list<bool>
{
    // “validate(ts)...” is a pack expansion
    // “validate(ts)” is its pattern
    //validate(ts)... expands to  validate(var1), validate(var2), validate(var3)
    auto result = {validate(ts)...};
    return result;
}

int main()
{
    cout << R"(validate(1,0.2,"3 4"))" << endl;
    validate(1, 0.2,"3 4");
}