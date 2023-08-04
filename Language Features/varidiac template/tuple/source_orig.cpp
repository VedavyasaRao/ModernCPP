#include <iostream>

template <typename T, typename... Ts>
struct Tuple {
    Tuple(const T& t, const Ts&... ts)
        : value(t)
        , rest(ts...)
    {
    }

    constexpr int size() const { return 1 + rest.size(); }

    T value;
    Tuple<Ts...> rest;
};
template <typename T>
struct Tuple<T> {
    Tuple(const T& t)
        : value(t)
    {
    }

    constexpr int size() const { return 1; }

    T value;
};

template <size_t i, typename T, typename... Ts>
struct nthType : nthType<i-1, Ts...> {
    static_assert(i < sizeof...(Ts) + 1, "index out of bounds");
};

template <typename T, typename... Ts>
struct nthType<0, T, Ts...> { T value; };

template <size_t i>
struct getter {
    template <typename... Ts>
    static decltype(nthType<i, Ts...>::value)& get(Tuple<Ts...>& t) {
        return getter<i-1>::get(t.rest);
    }
};
template <>
struct getter<0> {
    template <typename T, typename... Ts>
    static T& get(Tuple<T, Ts...>& t) {
        return t.value;
    }
};

template <size_t i, typename... Ts>
decltype(nthType<i, Ts...>::value)& get(Tuple<Ts...>& t) {
    return getter<i>::get(t);
}


int main()
{
    Tuple<int,int,float> t(1,2,3.4);
    
    std::cout << get<0>(t) << "\n";
    std::cout << get<1>(t) << "\n";
    std::cout << get<2>(t) << "\n";
    // std::cout << get<3>(t) << "\n"; // error with useful information
    
    return 0;
}
