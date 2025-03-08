#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
T* string_copy(T* dst, const T* src)
{
    int len = char_traits<T>::length(src);
    auto ret = char_traits<T>::copy(dst, src, len);
    dst[len]='\0';
    return ret;
}

template<typename T>
char_traits<T>::pos_type string_find(const T* src, T c)
{
    int len = char_traits<T>::length(src);
    auto ret = char_traits<T>::find(src, len, c);
    if (ret == nullptr)
        return -1;
    return (ret-src);
}


int main()
{
    const char *src  = reinterpret_cast<const char*>(u8"ಖ್ರಿಷಾ Rao👸");
    char dst[100];
    string_copy(dst,src);
    //prints ಖ್ರಿಷಾ Rao👸
    cout << dst << endl;

    const char32_t *src32  = U"ಖ್ರಿಷಾ Rao👸";
    //prints 10
    cout << string_find(src32, U'👸' ) << endl;
    //prints -1
    cout << string_find(src32, U'x' ) << endl;   
}