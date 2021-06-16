#include <bits/stdc++.h>
using namespace std;

void toh(int n, int A, int B, int C)
{
    if (n > 0)
    {
        toh(n - 1, A, C, B);
        cout << "Move " << A << " to  " << C << "\n";
        toh(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    cout << "Enter no. of disks: ";
    cin >> n;
    toh(n, 1, 2, 3);
    return 0;
}