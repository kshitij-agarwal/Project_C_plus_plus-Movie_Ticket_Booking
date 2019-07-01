// A file to check the characters in C++

#include <iostream>

using namespace std;

int main()
{
    for (int i = -128; i < 128; i++)
    {
        cout << i << " = " << (char)i;
        cout << endl;
    }

    cout << endl
         << endl;
    return 0;
}


