#include <iostream>
using namespace std;
struct rect
{
    int  h,w;
    ostream& operator<<(ostream& os)
    {
        os << "height:" << h << " " << "width:" << w << endl;
        return os;
    }
    istream& operator>>(istream& is)
    {
        is >> h >> w;
        return is; 
    }
};
ostream& operator<<(ostream& os,  rect& r)
{
    r.operator<<(os);
    return os;
}
istream& operator>>(istream& is,  rect& r)
{
    r.operator>>(is);
    return is;
}
int main()
{
    rect r;
    cout << "enter height and width as integers from keyboard" << endl;
    cout << "creating rect fron cin" << endl;
    cin >> r;
    cout << "printing rect to cout" << endl;
    cout << r;
    return 0;
}