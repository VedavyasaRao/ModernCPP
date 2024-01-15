#include <iostream>
#include <string>

using namespace std;

void printerror(int result)
{
    try
    {
        if (result == 1)    
            throw 10;
        else if (result == 2)
            throw "test";
        else if (result == 3)
            throw 2.0f;
        else if (result >= 4)
            throw 'a';
    }
    catch(const int& result)
    {
         cout << "int thrown: " << result << endl;
    }
    catch (const char*& result)
    {
        cout << "string thrown: " << result << endl;
    }
    catch (const float& result)
    {
        cout << "float thrown: " << result << endl;
    }
    catch (...)
    {
        cout << "something else thrown" << endl;
    }
}

int main()
{
    printerror(1);
    printerror(2);
    printerror(3);
    printerror(4);
}