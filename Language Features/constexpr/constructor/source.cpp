struct Rectangle
{
	int h, w;
	// A constexpr constructor
	constexpr Rectangle(int h, int w) : h(h), w(w) {}
};

constexpr int getArea(const Rectangle& r) { return r.h * r.w; }

int main()
{
	constexpr Rectangle r{ 10, 20 };
	static_assert((200 == getArea(r)), "compile time");
}