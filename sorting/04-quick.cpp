#include "dispaly.h"

/*
min = O(nlog(n)) 
max = O(n^2)
(Not adaptive)
(Not stable)
*/

int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(a[i], a[j]);
        }

    } while (i < j);
    swap(a[l], a[j]);
    return j;
}

void quickSort(int *a, int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}

int main()
{
    int n = 5;
    int a[n] = {8, 5, 7, 3, 2};
    quickSort(a, 0, n);
    display(a, n);
    return 0;
}