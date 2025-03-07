namespace shapes
{
    namespace round
    {
        struct circle {};
    }

    namespace rect
    {
        struct square{};
    }
}

using namespace shapes;
round::circle c;  //shapes::round::circle
rect::square s;   //shapes::rect::square

int main()
{
}