#include <bits/stdc++.h>
using namespace std;

int words(string x)
{
    int wordCount = 0, i, strLen = x.size();
    for (i = 0; i < strLen; i++)
        if (x[i] == ' ' && x[i - 1] != ' ')
            wordCount++;

    return wordCount + 1;
}

int vowels(string x)
{
    int vowelCount = 0, i, strLen = x.size();
    for (i = 0; i < strLen; i++)
        if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u' ||
            x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U')
            vowelCount++;

    return vowelCount;
}

int consonants(string x)
{
    int consonantCount = 0, i, strLen = x.size();
    consonantCount = strLen - vowels(x);
    for (i = 0; i < strLen; i++)
        if (x[i] == ' ')
            consonantCount--;

    return consonantCount;
}

int main()
{
    string x;
    getline(cin, x);
    cout << "No. of words: " << words(x) << "\n";
    cout << "No. of vowels: " << vowels(x) << "\n";
    cout << "No. of consonants: " << consonants(x) << "\n";
    return 0;
}