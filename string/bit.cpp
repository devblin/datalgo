#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int d)
{
    int r;
    string ans = "";
    if (d == 0)
        ans = "0";
    while (d != 0)
    {
        r = d % 2;
        d = d / 2;
        if (r == 0)
            ans = "0" + ans;
        else if (r == 1)
            ans = "1" + ans;
    }
    return ans;
}

int binaryToDecimal(string x)
{
    int i = 0, strLen = x.size(), ans = 0, y;
    for (i = 0; i < strLen; i++)
    {
        y = (int)x[i] - 48;
        ans += pow(2, strLen - 1 - i) * y;
    }
    return ans;
}

//masking
void checkBit(string x, int pos)
{
    int a = 1;
    int h = binaryToDecimal(x);
    cout << "Checking-bit:\n";
    cout << "h = " << h << " in bin: " << decimalToBinary(h) << "\n";
    cout << "a = " << a << " in bin: " << decimalToBinary(a) << "\n";
    cout << "Checking bit set at " << pos << ": ";
    a = (a << pos);
    cout << (h & a) << "\n";
}

//merging
void changeBit(string x, int pos)
{
    int a = 1;
    int h = binaryToDecimal(x);
    cout << "Changing h's bit at " << pos << ":\n";
    cout << "Before h = " << decimalToBinary(h) << "\n";
    h = (h | (a << pos));
    cout << "After changing bit, h = " << decimalToBinary(h) << "\n";
}

int main()
{
    int x1 = 1, x2 = 2;
    cout << "x1 in bin: " << decimalToBinary(x1) << "\n";
    cout << "x2 in bin: " << decimalToBinary(x2) << "\n";
    cout << "Left shift x1:\n"
         << "Decimal:" << (x1 << 1) << "\nBin:" << decimalToBinary(x1 << 1) << "\n";
    cout << "Right shift x2:\n"
         << "Decimal:" << (x2 << 1) << "\nBin:" << decimalToBinary(x2 << 1) << "\n";

    string x = "0001001";
    checkBit(x, 3);
    checkBit(x, 2);
    checkBit(x, 0);
    changeBit(x, 3);
    changeBit(x, 2);
    changeBit(x, 1);
    return 0;
}