#include <bits/stdc++.h>
using namespace std;

//O(n^2)
void PairSumUnsorted1(int a[], int n, int target)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] + a[j] == target)
                cout << "(" << a[i] << ", " << a[j] << ") ";
    cout << "\n";
}

//O(n)
void PairSumUnsorted2(int a[], int n, int target)
{
    int max = *max_element(a, a + n), min = *min_element(a, a + n);
    int h[max + 1] = {0};
    int i;
    for (i = 0; i < n; i++)
        h[a[i]]++;
    for (i = 0; i < n; i++)
        if (h[target - a[i]] != 0 && target - a[i] >= 0)
            cout << "(" << a[i] << ", " << target - a[i] << ") ";
    cout << "\n";
}

void PairSumSorted1(int a[], int n, int target)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[j] > target)
            j--;
        else if (a[i] + a[j] == target)
            cout << "(" << a[i++] << ", " << a[j--] << ") ";
        else if (a[i] + a[j] > target)
            j--;
        else if (a[i] + a[j] < target)
            i++;
    }
    cout << "\n";
}

void MinMax(int a[], int n)
{
    int max = a[0], min = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << "Max: " << max << " and Min: " << min << "\n";
}

void menu()
{
    int i, option, n, target;
    cout << "1. PairSumUnsorted\n";
    cout << "2. PairSumSorted\n";
    cout << "3. Min&Max\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
    int a[n];
    if (option != 0)
    {
        cout << "Enter size: ";
        cin >> n;
        cout << "Enter elements: ";
        for (i = 0; i < n; i++)
            cin >> a[i];
        if (option != 3)
        {
            cout << "Enter target sum: ";
            cin >> target;
        }
    }
    switch (option)
    {
    case 1:
        PairSumUnsorted1(a, n, target);
        PairSumUnsorted2(a, n, target);
        break;
    case 2:
        PairSumSorted1(a, n, target);
        break;
    case 3:
        MinMax(a, n);
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