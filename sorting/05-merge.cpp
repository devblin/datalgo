#include "dispaly.h"

/*
Average time complexity
T = O(nlogn)
S = O(n + logn) = O(m)
*/

void merge(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, n = high - low + 1;
    int b[high];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSortI(int *a, int n)
{
    int high, low, mid, pass, i, p;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            merge(a, low, mid, high);
        }
    }
    while (p / 2 < n)
    {
        merge(a, 0, p / 2 - 1, n - 1);
    }
    display(a, n);
}

void mergeSortR(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSortR(a, low, mid);
        mergeSortR(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[8] = {8, 3, 7, 4, 9, 2, 6, 5};
    mergeSortI(a, 8);
    int b[8] = {8, 3, 7, 4, 9, 2, 6, 5};
    mergeSortR(b, 0, 7);
    display(b, 8);
    return 0;
}