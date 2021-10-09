#include "dispaly.h"

/*
Shell sort:
T = O(nlogn)
S = O(1)
*/

void shellSort(int *a, int n)
{
    int gap = n, pass, i, j, p;
    for (p = gap / 2; p >= 1; p /= 2)
    {
        for (i = 0; i < n; i++)
        {
            if (p + i < n && a[i] > a[p + i])
            {
                swap(a[i], a[p + i]);
            }
            j = i - p;
            while (j >= 0 && a[j] > a[i])
            {
                swap(a[j], a[i]);
                j = j - p;
            }
        }
    }
    display(a, n);
}

int main()
{
    int a[11] = {9, 15, 16, 8, 13, 6, 12, 10, 4, 2, 3};
    shellSort(a, 11);
    return 0;
}