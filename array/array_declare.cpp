#include <bits/stdc++.h>
using namespace std;

void arrayValues(int a[], int n, int m = 1)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (m == 1)
        {
            cout << a[i] << " ";
        }
        else
        {
            cout << (int)&a[i] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    int a1[5];
    arrayValues(a1, 5);

    int a2[3] = {1, 2, 3};
    arrayValues(a2, 3);

    int a3[3] = {1, 2};
    arrayValues(a3, 3);

    int a4[3] = {0};
    arrayValues(a4, 3);

    int a5[] = {2, 3, 4};
    arrayValues(a5, 3);
    arrayValues(a5, 3, 0);

    cout << a2[0] << ", " << 0 [a2] << "," << *(a2) << "\n";
}