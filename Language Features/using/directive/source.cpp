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
    using namespace geometry;
    geometry::circle c; //OK
    trigonometry::circle c2; //OK
    circle c4; //OK same as geometry::circle

int main()
{
}