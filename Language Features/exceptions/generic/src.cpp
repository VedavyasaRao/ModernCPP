#include <iostream>
#include <string>
using namespace std;

int main()
{
    try
    {
        int i=3;
        if (i==1)    
            throw 10;
        else if (i ==2)
            throw string{"test"};
        else
            throw 2.0;
    }
    catch(int i)
    {
         cout << "int thrown: " << i << endl;
    }
    catch (string str)
    {
        cout << "string thrown: " << str << endl;
    }
    catch (...)
    {
        cout << "something else thrown" << endl;
    }
}