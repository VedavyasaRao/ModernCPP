#include <iostream>
#include <string>
using namespace std;


template <typename T, typename... Ts>
struct Tuple 
{
	Tuple(const T& t, const Ts&... ts)
		: value(t)
		, rest(ts...)
	{
	}

	constexpr int size() const { return 1 + rest.size(); }

	void * get(size_t idx)
	{
		if (size() == idx)
			return &value;
		else
			return rest.get(idx);
	}

	T value;
	Tuple<Ts...> rest;
};

template <typename T>
struct Tuple<T> 
{
	Tuple(const T& t)
		: value(t)
	{
	}

	constexpr int size() const { return 1; }
	
	void * get(size_t idx)
	{
		return &value;
	}
	T value;
};

template <size_t i, typename T, typename... Ts>
struct nthTypePtr : nthTypePtr<i - 1, Ts...> 
{
	static_assert(i < sizeof...(Ts)+1, "index out of bounds");
};

template <typename T, typename... Ts>
struct nthTypePtr<0, T, Ts...> 
{ 
	T* valueptr;
};

template <size_t i, typename... Ts>
auto get(Tuple<Ts...>& t) -> decltype(*(nthTypePtr<i, Ts...>::valueptr))
{
	return *reinterpret_cast<decltype(nthTypePtr<i, Ts...>::valueptr)>  (t.get(t.size() - i));;
}

int main()
{
	Tuple<int, double, string> t(1, 2.0, "3,4");
	get<0>(t) = 100;
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;

	return 0;
}
