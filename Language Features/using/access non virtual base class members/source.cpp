using namespace std;

struct X
{
    void print(int){}
};

struct Y: public X
{
    void print(double){}
};

struct Y2: public X
{
    using X::print; //brings base class versions of print
    void print(double){}
};

int main()
{
    Y y;
    y.print(1); //calls print(double)

    Y2 y2;
    y2.print(1); //calls overloaded print(int)
}