#include <bits/stdc++.h>
using namespace std;

int fiboI(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fiboER(int n)
{
    if (n <= 1)
        return n;
    return fiboER(n - 2) + fiboER(n - 1);
}
static int f[100];
int fiboM(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    if (f[n - 2] == -1)
        f[n - 2] = fiboM(n - 2);
    if (f[n - 1] == -1)
        f[n - 1] = fiboM(n - 1);
    return f[n - 2] + f[n - 1];
}

int main()
{
    fill_n(f, 100, -1);
    int n;
    cin >> n;
    cout << "fibo-iterative:" << fiboI(n) << "\n";
    cout << "fibo-excessive-recursive:" << fiboER(n) << "\n";
    cout << "fibo-memoized-recursion:" << fiboM(n) << "\n";
    return 0;
}