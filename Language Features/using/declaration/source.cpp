using namespace std; //global scope

//geometry.h
namespace geometry {struct circle {};}

//trigonometry.h
namespace trigonometry  {struct circle {};}

void driver() 
{
    using namespace geometry;    //local to function
    circle c; //geometry::circle
}

int main()
{

}