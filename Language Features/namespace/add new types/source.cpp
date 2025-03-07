using namespace std; //global scope

//geometry.h
namespace geometry {struct circle {};}

//sphere.h
namespace geometry  {struct sphere {};}

namespace geo = geometry;   //alias for geometry
geo::circle c;    //geometry::circle
geometry::sphere s;
int main()
{
}