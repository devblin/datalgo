#include "dispaly.h"

/*
min = O(n) 
max = O(n^2)
(Adaptive)
(Stable)
*/
void insertionSort(int *a, int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && x < a[j])
        {
            a[j + 1] = a[j--];
        }
        a[j + 1] = x;
    }
}

int main()
{
    int n = 5;
    int a[n] = {8, 5, 7, 3, 2};
    insertionSort(a, n);
    display(a, n);
    return 0;
}