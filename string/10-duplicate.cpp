#include <bits/stdc++.h>
using namespace std;

void duplicateCompare(string x)
{
    int strLen = x.size(), i, j, c = 0;
    for (i = 0; i < strLen; i++)
    {
        c = 0;
        for (j = 0; j < strLen; j++)
        {
            if (x[i] == x[j] && i != j && x[i] != '0')
            {
                c++;
                x[j] = '0';
            }
        }
        if (x[i] != '0')
            cout << x[i] << " : " << c << "\n";
    }
}

void duplicateHashTable(string x)
{
    int hash[52] = {0};
    int strLen = x.size(), i;
    for (i = 0; i < strLen; i++)
    {
        if (x[i] >= 65 && x[i] <= 90)
            hash[x[i] - 65]++;
        else if (x[i] >= 97 && x[i] <= 122)
            hash[x[i] - 71]++;
    }
    for (i = 0; i < 52; i++)
    {
        if (hash[i] > 0)
        {
            if (i >= 26)
                cout << (char)(i + 71);
            else
                cout << (char)(i + 65);

            cout << " : " << hash[i] - 1 << "\n";
        }
    }
}

void duplicateBitwise(string x)
{
    long long int h = 0, y = 0;
    int strLen = x.size(), i;
    cout << "Duplicates are: ";
    for (i = 0; i < strLen; i++)
    {
        y = 1;
        if (x[i] >= 65 && x[i] <= 90)
            y = (y << (x[i] - 65));
        else if (x[i] >= 97 && x[i] <= 122)
            y = (y << (x[i] - 71));

        if ((y & h) > 0)
            cout << x[i] << " ";
        else
            h = y | h;
    }
}

int main()
{
    string x;
    getline(cin, x);
    duplicateCompare(x);
    duplicateHashTable(x);
    duplicateBitwise(x);
}