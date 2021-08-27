#include "dispaly.h"

/*
min = O(n) (After making it adaptive)
max = O(n^2)
(Stable)
*/
void bubbleSort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int a[5] = {8, 5, 7, 3, 2};
    bubbleSort(a, 5);
    display(a, 5);
    return 0;
}