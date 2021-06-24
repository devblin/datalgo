#include <bits/stdc++.h>
using namespace std;

void SingleMissingSum(int a[], int n)
{
    int i, actualSum = 0, sum = 0;
    actualSum = ((n + 2) * (n + 1)) / 2;

    for (i = 0; i < n; i++)
        sum += a[i];

    cout << "Missing number: " << actualSum - sum << "\n";
}

void SingleMissingDiff(int a[], int n)
{
    int diff = a[0], i;
    for (i = 0; i < n; i++)
        if (a[i] - i != diff)
        {
            cout << "Missing number: " << i + diff << "\n";
            break;
        }
}

void MultipleMissingDiff1(int a[], int n)
{
    int i, j, d;
    cout << "1-Missing elements are: ";
    for (i = 0; i < n - 1; i++)
        if (a[i + 1] - a[i] > 1)
        {
            d = a[i + 1] - a[i];
            for (j = 1; j < d; j++)
                cout << a[i] + j << " ";
        }
    cout << "\n";
}

void MultipleMissingDiff2(int a[], int n)
{
}

void menu()
{
    int i, n, option;
    cout << "1. SingleMissingSum\n";
    cout << "2. SingleMissingDiff\n";
    cout << "3. MultipleMissingDiff1\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter sequence of natural no. excluding missing one: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    switch (option)
    {
    case 1:
        SingleMissingSum(a, n);
        break;
    case 2:
        SingleMissingDiff(a, n);
        break;
    case 3:
        MultipleMissingDiff1(a, n);
        break;
    default:
        break;
    }

    if (option != 0)
        menu();
}

int main()
{
    menu();
    return 0;
}