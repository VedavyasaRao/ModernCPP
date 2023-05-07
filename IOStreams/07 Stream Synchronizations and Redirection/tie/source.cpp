#include <fstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    cout << "Tie Demo" << endl << endl;

    for (int i=0; i<2; ++i)
    {
        string value("");
        if (i == 0)
            cout << "Without tie() ifstream with ofstream" << endl;
        else
            cout << "With tie() ifstream with ofstream" << endl;

        cout << "ofstream: Opening output.txt for write" << endl;
        ofstream os("output.txt");
        cout << "ifstream: Opening output.txt for read" << endl;
        ifstream is("output.txt");
        
        if (i == 1)
            is.tie(&os);
            
        cout << "ofstream: Writing \"Hello\" to output.txt" << endl;
        os << "Hello ";
        cout << "ifstream: Reading from output.txt" << endl;
        is >> value;
        cout << "Read Value:" << quoted(value) << "\n";
        os.close();
        is.close();
        cout << endl;
    }
 
}