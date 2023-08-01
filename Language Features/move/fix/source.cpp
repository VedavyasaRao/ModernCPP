#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct Person
{
    Person() 
    {
        cout << "default constructor" << endl;
    }

    Person(const string& fullname, const short& yob) 
    {
        this->fullname = fullname;
        this->yob = yob;
        cout << "memberwise constructor:" << fullname << " " << yob << endl;
    }


    Person(const Person& p) 
    {
        fullname = p.fullname;
        yob = p.yob;
        cout << "copy constructor(&):" << fullname << " " << yob << endl;
    }

    Person& operator=(const Person& p)
    {
        fullname = p.fullname;
        yob = p.yob;
        cout << "operator=(&):" << fullname << " " << yob << endl;
        return *this;
    }

    Person(Person&& p) 
    {
        fullname = move(p.fullname);
        yob = p.yob;
        *this = move(p);
        cout << "copy constructor(&&):" << fullname << " " << yob << endl;
    }

    Person& operator=(Person&& p) 
    {
        fullname = move(p.fullname);
        yob = p.yob;
        cout << "operator=(&&):" << fullname << " " << yob << endl;
        return *this;
    }

    ~Person() 
    {
        cout << "destructor" << endl;
    }

    string fullname;
    short yob; 

};


int main()
{
    vector<Person> pervec;
    cout << "pervec.push_back(Person{\"in\",1643});" << endl;
    pervec.push_back(move(Person{"in",1643}));
    cout << endl;

    cout << "pervec.push_back(Person{\"wr\",1845});" << endl;
    pervec.push_back(move(Person{"wr",1845}));
    cout << endl;
    
    cout << "pervec.push_back(Person{\"ae\",1879});" << endl;
    pervec.push_back(move(Person{"ae",1879}));
    cout << endl;
}