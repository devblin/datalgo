#include <bits/stdc++.h>
using namespace std;

string lowerCase(string x)
{
    int strLen = x.size(), i;
    for (i = 0; i < strLen; i++)
    {
        if (x[i] >= 65 && x[i] <= 90)
            x[i] += 32;
    }
    return x;
}

string upperCase(string x)
{
    int strLen = x.size(), i;
    for (i = 0; i < strLen; i++)
    {
        if (x[i] >= 97 && x[i] <= 122)
            x[i] -= 32;
    }
    return x;
}

string toogleCase(string x)
{
    int strLen = x.size(), i;
    for (i = 0; i < strLen; i++)
    {
        if (x[i] >= 65 && x[i] <= 90)
            x[i] += 32;
        else if (x[i] >= 97 && x[i] <= 122)
            x[i] -= 32;
    }
    return x;
}

int main()
{
    string x;
    getline(cin, x);
    cout << "Toggledcase: " << toogleCase(x) << "\n";
    cout << "Lowercase: " << lowerCase(x) << "\n";
    cout << "Uppercase: " << upperCase(x) << "\n";
}