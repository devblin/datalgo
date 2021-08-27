#include "dispaly.h"

/*
min = O(n^2) 
max = O(n^2)
(Not adaptive)
(Not stable)
*/
void selectionSort(int *a, int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(a[i], a[k]);
    }
}

int main()
{
    int n = 5;
    int a[n] = {8, 5, 7, 3, 2};
    selectionSort(a, n);
    display(a, n);
    return 0;
}