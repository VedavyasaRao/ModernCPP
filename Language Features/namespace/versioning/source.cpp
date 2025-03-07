namespace shapes
{
    inline namespace ver3_0
    {
        struct circle {};
    }

    namespace ver2_0
    {
        struct circle {};
    }

    namespace ver1_0
    {
        struct circle {};
    }
}

using namespace shapes;
circle c; //shapes::ver3_0::circle

int main()
{
}