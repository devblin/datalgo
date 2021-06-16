#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return factorial(n - 1) * n;
}

int ncrI(int n, int r)
{
    int t1 = factorial(n), t2 = factorial(r), t3 = factorial(n - r);
    return t1 / (t2 * t3);
}

int ncrR(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return ncrR(n - 1, r - 1) + ncrR(n - 1, r);
}

int main()
{
    int n, r;
    cout << "Enter n and r(0...n):";
    cin >> n >> r;
    cout << "nCr - iterative: " << ncrI(n, r) << "\n";
    cout << "nCr - recursive: " << ncrR(n, r) << "\n";
    return 0;
}