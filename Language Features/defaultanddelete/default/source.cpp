#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct person
{
    person(string name):name(name){};
    person()=default;
    string name;
};


int main()
{

    person p; //no error

}