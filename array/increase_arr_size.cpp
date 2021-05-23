#include <bits/stdc++.h>
using namespace std;

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int *p;
    p = new int[3];
    printArr(p, 3);

    int *q;
    q = new int[6];
    printArr(q, 6);

    delete[] p;
    p = q;
    q = NULL;
    printArr(p, 6);
}