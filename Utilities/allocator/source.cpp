#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main() 
{
    string numbers[] = {"one", "two", "three", "four"};
    size_t sz = sizeof(numbers);
    
    allocator<string> sal;
    auto sbuf = sal.allocate(sz);
    auto itr = sbuf;
    
    for (auto &s:numbers)
    {
        sal.construct(itr,s);
        ++itr;
    }

    //prints one two three four 
    for (itr = sbuf; itr != sbuf+sz; ++itr)
        cout << *itr  << " ";

    for (auto itr = sbuf; itr != sbuf+sz; ++itr)
       sal.destroy(itr);

    sal.deallocate(sbuf,sz);
   
}