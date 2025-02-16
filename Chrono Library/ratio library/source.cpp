#include <iostream>
#include <ratio>

using namespace std;

template<typename R>
void  print_ratio(ostream& os)
{
    os << "ratio<" << R::num << "," << R::den << ">";
}

int main() 
{
    typedef ratio<2, 3> twothird;
    typedef ratio<4, 5> fourfifth;
    cout << "ratio_add<ratio<2, 3>,ratio<4, 5>>" << endl;
    print_ratio<ratio_add<twothird, fourfifth>>(cout);

    cout << endl << endl;
    cout << "ratio_equal<ratio<2, 3>,ratio<4, 6>>" << endl;
    cout << boolalpha << ratio_equal<twothird, ratio<4, 6>>::value;

    return 0;
}
