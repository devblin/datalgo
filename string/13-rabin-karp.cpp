#include <string>
#include <iostream>
#include <cmath>
#define NUM 26

using namespace std;

/*
Rabin-Karp pattern matching algo:
n - length of string
m - length of pattern
Tmin = O(n-m+1)
Tmax = O(mn)
*/

int charCode(char x)
{
    return x - 96;
}

int hashFunction(string s)
{
    int hashVal = 0, i, n = s.size();
    for (i = 0; i < n; i++)
    {
        hashVal += charCode(s[i]) * pow(NUM, n - i - 1);
    }
    return hashVal;
}

int rabinKarp(string search, string pattern)
{
    int m = pattern.size(), n = search.size(), i = m, j = 0, temp;
    int patternHash = hashFunction(pattern);
    int searchHash = hashFunction(search.substr(0, m));
    char startChar = search[j++];

    do
    {
        if (searchHash == patternHash)
            return i - m;

        temp = charCode(startChar) * pow(NUM, m - 1);
        searchHash = (searchHash - temp) * NUM;
        searchHash += charCode(search[i]);
        startChar = search[j++];
        i++;
    } while (i < n + 1);

    return -1;
}

int main()
{
    string search = "ccaccaaedba";
    string pattern = "aae";
    cout << rabinKarp(search, pattern);
    return 0;
}