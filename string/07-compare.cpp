#include <bits/stdc++.h>
using namespace std;

char toLowerCase(char x)
{
    if (x >= 97 && x <= 122)
        x -= 32;
    return x;
}

void compare(string a, string b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (toLowerCase(a[i]) != toLowerCase(b[i]))
            break;
        i++;
    }
    if (a[i] > b[i])
        cout << a << " greater than " << b << "\n";
    else if (a[i] < b[i])
        cout << a << " smaller than " << b << "\n";
    else if (a[i] == b[i])
        cout << "Both are same\n";
}

void palindromeReverse(string x)
{
    int i, strLen = x.size();
    string y = "";
    for (i = 0; i < strLen; i++)
        y = x[i] + y;
    if (y == x)
        cout << "Palindrome\n";
    else
        cout << "Not palindrome\n";
}

void palindromeCompare(string x)
{
    int i, strLen = x.size();
    string res = "Palindrome";
    for (i = 0; i < strLen / 2; i++)
        if (x[i] != x[strLen - 1 - i])
        {
            res = "Not palindrome";
            break;
        }
    cout << res << "\n";
}

int main()
{
    string a, b;
    cin >> a >> b;
    compare(a, b);
    palindromeReverse(a);
    palindromeCompare(a);
    return 0;
}