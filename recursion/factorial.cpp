#include <bits/stdc++.h>
using namespace std;

int factRecursion(int n)
{
    if (n > 1)
        return factRecursion(n - 1) * n;
    return 1;
}
/*
T(n) = O(n)
S(n) = O(n)
*/

int factLoop(int n)
{
    int f = 1, i = 0;
    for (i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}
/*
T(n) = O(n)
S(n) = O(1)
*/

int main()
{
    int x;
    cin >> x;
    cout << "Factorial using recursion: " << factRecursion(x) << endl;
    cout << "Factorial using loop: " << factLoop(x) << endl;
    return 0;
}