#include <bits/stdc++.h>
using namespace std;

double taylorRecursion(double x, double n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = taylorRecursion(x, n - 1);
    p = p * x;
    f = f * n;
    return r + (p / f);
}

/*
T(n) = O(n^2)
S(n) = O(n)
*/

double taylorHornerI(double x, double n)
{
    double ans = 1, i;
    for (i = n; i > 0; i--)
        ans = 1 + (x / i) * ans;
    return ans;
}

double taylorHornerR(double x, double n)
{
    static double ans = 1;
    if (n == 0)
        return ans;
    ans = 1 + (x / n) * ans;
    return taylorHornerR(x, n - 1);
}

int main()
{
    double x, n;
    cin >> x >> n;
    cout << "taylor(recursion): " << taylorRecursion(x, n) << endl;
    cout << "taylor-horner(iterative): " << taylorHornerI(x, n) << endl;
    cout << "taylor-horner(recursion): " << taylorHornerR(x, n) << endl;

    return 0;
}