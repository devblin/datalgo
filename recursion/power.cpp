#include <bits/stdc++.h>
using namespace std;

int powerRecursion(int base, int exp)
{
    if (exp > 0)
    {
        return powerRecursion(base, exp - 1) * base;
    }
    return 1;
}

int powerLoop(int base, int exp)
{
    int ans = 1, i;
    for (i = 1; i <= exp; i++)
    {
        ans *= base;
    }
    return ans;
}

int powerRecursionOptimized(int base, int exp)
{
    if (exp == 0)
        return 1;
    if (exp % 2 == 0)
        return powerRecursionOptimized(base * base, exp / 2);
    else
        return base * powerRecursionOptimized(base * base, (exp - 1) / 2);
}

int main()
{

    int m, n;
    cin >> m >> n;
    cout << "m power n (recursion): " << powerRecursion(m, n) << endl;
    cout << "m power n (loop): " << powerLoop(m, n) << endl;
    cout << "m power n (optimized): " << powerRecursionOptimized(m, n) << endl;

    return 0;
}