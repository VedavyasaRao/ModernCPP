#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct person
{
    person(string name):name(name){};
    person()=default;
    void update (int age){age=age;}
    void update (bool age)=delete;
    person(const person& p)=default;
    person& operator =(const person& p)=default;
    string name;
    int age;

} p("test"), p2("test2");

    

int main()
{
    person p3 = p; //error cannot construct
    p2=p; //error cannot clone
    p.update(true); //error function deleted
}