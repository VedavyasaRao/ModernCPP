
using namespace std; //global scope

//regions
struct circle{string address();};

//geometry.h
namespace geometry
{
    struct circle{void draw();};
}

//trigonometry.h
namespace trigonometry
{
    struct circle {double area();};
}

int main()
{
    geometry::circle c; //OK
    trigonometry::circle c2; //OK
    ::circle c3;  //OK global namespace
    circle c4; //NOT OK ambiguous scope
}