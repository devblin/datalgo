#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
KMP(Knuth-Morris-Pratt) pattern matching algo:
m - length of pattern
n - length of string
T = O(m+n)
*/

vector<int> prefixFunction(string s)
{
    int i, j, n = s.size();
    vector<int> pi(n, 0);

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        while (j > 0 && s[i] != s[j])
        {
            j -= 1;
        }
        if (s[i] == s[j])
        {
            j += 1;
        }
        pi[i] = j;
    }

    return pi;
}

int KMP(string search, string pattern)
{
    vector<int> pi = prefixFunction(pattern);
    int i, j, n = search.size(), m = pattern.size();
    j = -1;
    i = 0;
    while (i < n)
    {
        if (pattern[j + 1] == search[i])
        {
            j += 1;
            i += 1;
        }
        else
        {
            if (j != -1)
            {
                j = pi[j] - 1;
            }
            else
            {
                i += 1;
            }
        }
        if (j == m - 1)
            return i - m;
    }
    return -1;
}

int main()
{
    string search = "ababcabcabababd";
    string pattern = "afaf";
    cout << KMP(search, pattern);
    return 0;
}