#include <bits/stdc++.h>
using namespace std;

void printArrSimple(int a[][2], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void printArrPt1(int *a[2], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void setArrPt1(int *a[2], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = i * 10 + j;
        }
    }
}

void printArrPt2(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void setArrPt2(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = i * 10 + j;
        }
    }
}

int main()
{
    int a1[2][2] = {{1, 2}, {3, 4}};
    printArrSimple(a1, 2);

    int *a2[2];
    a2[0] = new int[2];
    a2[1] = new int[2];
    printArrPt1(a2, 2);
    setArrPt1(a2, 2);
    printArrPt1(a2, 2);

    int **a3;
    a3 = new int *[2];
    a3[0] = new int[2];
    a3[1] = new int[2];
    printArrPt2(a3, 2);
    setArrPt2(a3, 2);
    printArrPt2(a3, 2);

    return 0;
}