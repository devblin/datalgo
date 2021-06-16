#include <bits/stdc++.h>
using namespace std;

void stringLen(char x[])
{
    int i;
    for (i = 0; x[i] != '\0'; i++)
        i++;

    cout << "String length: " << i << "\n";
}

int main()
{
    char x[10];
    gets(x);
    stringLen(x);
}