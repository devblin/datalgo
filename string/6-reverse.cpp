#include <bits/stdc++.h>
using namespace std;

string reverseStr(string x)
{
    char temp;
    int strLen = x.size(), i, j;
    for (i = 0, j = strLen - 1 - i; i < strLen / 2; i++, j--)
    {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
    return x;
}

int main()
{
    string x;
    getline(cin, x);
    cout << reverseStr(x);
    return 0;
}
