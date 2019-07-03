//  This is a file to test basics of C++

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

int main()
{
    string x = "A1";
    int temp_dig = x[1];
    int temp_alpha = (toupper(x[0]));
    cout << temp_alpha << "\n"
         << temp_dig;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << endl
         << endl;
    return 0;
}