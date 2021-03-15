#include <bits/stdc++.h>
using namespace std;

int taylorRecursion(int x, int n)
{
    static int p = 1, f = 1;
    int r;
    if (n == 0)
        return 1;
    else
    {
        r = taylorRecursion(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
}

/*
T(n) = O(n^2)
S(n) = O(n)
*/

// int taylorHorner(int x, int n)
// {
// }

int main()
{
    int x, n;
    cin >> x >> n;
    cout << "taylor series (recursion): " << taylorRecursion(x, n) << endl;
    return 0;
}