#include <bits/stdc++.h>
using namespace std;

void FindDuplicatesSorted(int a[], int n)
{
    int i, j = -1;
    cout << "Duplicates: ";
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            if (j != a[i])
            {
                cout << a[i] << " ";
                j = a[i];
            }
        }
    }
    cout << "\n";
}

int CountDuplicatesSorted(int a[], int n)
{
    int i, j = -1;
    cout << "Duplicates count: ";
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            if (j != a[i])
            {
                j = 0;
                while (a[i] == a[i + 1])
                {
                    j++;
                    i++;
                }
                cout << a[i] << " = " << j << "\n";
                j = a[i];
            }
        }
    }
    cout << "\n";
    return 0;
}

void FindCountDuplicates(int a[], int n)
{
    int max = *max_element(a, a + n), min = *min_element(a, a + n), i;
    int h[max + 1] = {0};

    for (i = 0; i < n + 1; i++)
        cout << h[i] << " ";
    cout << "\n";
    for (i = 0; i < n; i++)
        h[a[i]]++;

    cout << "Duplicates Count: \n";
    for (i = min; i <= max; i++)
        if (h[i] > 1)
            cout << i << " = " << h[i] << "\n";
}

void FindDuplicatesUnsorted(int a[], int n)
{
    int i, j;
    cout << "Duplicates: ";
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] == a[j])
                cout << a[i] << " ";
    cout << "\n";
}

void menu()
{
    int option, n, i;
    cout << "1. FindDuplicatesSorted\n";
    cout << "2. CountDuplicatesSorted\n";
    cout << "3. FindCountDuplicates\n";
    cout << "4. FindDuplicatesUnsorted\n";
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
    }
    switch (option)
    {
    case 1:
        FindDuplicatesSorted(a, n);
        break;
    case 2:
        CountDuplicatesSorted(a, n);
        break;
    case 3:
        FindCountDuplicates(a, n);
        break;
    case 4:
        FindDuplicatesUnsorted(a, n);
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