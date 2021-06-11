#include <bits/stdc++.h>
using namespace std;

bool validString(string x)
{
    int strLen = x.size(), i;
    for (i = 0; i < strLen; i++)
    {
        if (!(x[i] >= 65 && x[i] <= 90) && !(x[i] >= 97 && x[i] <= 122) && !(x[i] >= 48 && x[i] <= 57))
            return false;
    }
    return true;
}

int main()
{
    string x;
    getline(cin, x);
    if (validString(x))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}