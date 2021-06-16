#include <bits/stdc++.h>
using namespace std;

void anagramGeneral(string a, string b)
{
    string ans = " Anagram of ";
    int aLen = a.size(), bLen = b.size(), i, j;

    for (i = 0; i < aLen; i++)
    {
        for (j = 0; j < bLen; j++)
        {
            if (a[i] != b[j])
            {
                ans = " Not an anagram of ";
                break;
            }
        }
    }
    cout << b << ans << a << "\n";
}

void anagramHashTable(string a, string b)
{
    string ans = " Anagram of ";
    int h[52] = {0};
    int aLen = a.size(), bLen = b.size(), i;
    for (i = 0; i < aLen; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            h[a[i] - 65]++;
        else if (a[i] >= 97 && a[i] <= 122)
            h[a[i] - 71]++;
    }
    for (i = 0; i < bLen; i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
        {
            h[b[i] - 65]--;
            if (h[b[i] - 65] < 0)
            {
                ans = " Not an anagram of ";
                break;
            }
        }
        else if (b[i] >= 97 && b[i] <= 122)
        {
            h[b[i] - 71]--;
            if (h[b[i] - 71] < 0)
            {
                ans = " Not an anagram of ";
                break;
            }
        }
    }
    cout << b << ans << a << "\n";
}

int main()
{
    string a, b;
    cin >> a >> b;
    anagramGeneral(a, b);   // O(n^2)
    anagramHashTable(a, b); // O(n)
    return 0;
}