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
    {
        cout << "i = " << i << " | " << h[target - a[i]] << "\n";
        if (h[target - a[i]] != 0)
            cout << "(" << a[i] << ", " << target - a[i] << ") ";
    }
    cout << "\n";
}

void menu()
{
    int i, option, n, target;
    cout << "1. PairSumUnsorted\n";
    cout << "2. PairSumSorted\n";
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
        cout << "Enter target sum: ";
        cin >> target;
    }
    switch (option)
    {
    case 1:
        PairSumUnsorted1(a, n, target);
        PairSumUnsorted2(a, n, target);
        break;
    case 2:
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