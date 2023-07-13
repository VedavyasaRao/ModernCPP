struct Rectangle
{
    int _h, _w;
    // A constexpr constructor
    constexpr Rectangle(int h, int w) : _h(h), _w(w) {}
};
 
constexpr int getArea(const Rectangle& r)  { return r._h * r._w; } 

int main()
{
    constexpr Rectangle r(10, 20);
    static_assert((200 == getArea(r)));
}