#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int stringLen(char x[])
{
    int i = 0;
    while (x[i] != '\0')
        i++;
    cout << i << "\n";
    return i;
}

void printChar(char x[])
{
    int len = stringLen(x);
    for (int i = 0; i < len; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}

int main()
{
    //single char
    char x;
    cin >> x;
    cout << x << ", ASCI - " << (int)x << "\n";

    //string
    char x1[3];
    printChar(x1);

    char x2[4] = {'a', 'b', 'c', '\0'};
    printChar(x2);

    char x3[4] = {97, 98, 99, '\0'};
    printChar(x3);

    char x4[4] = {97, 98, '\0'};
    printChar(x4);

    cout << "x4 prints as string: " << x4 << "\n";

    char x5[] = "Deepanshu";
    printChar(x5);

    char x6[] = {'d', 'h', 'r', 'u', 'w', '\0'};
    printChar(x6);

    char *x7 = "devblin";
    printChar(x7);

    string x8;
    cin.ignore(1, '\n');
    getline(cin, x8);
    cout << x8 << "\n";

    return 0;
}