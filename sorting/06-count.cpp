#include "dispaly.h"
#include "max.h"

/*
T = O(n)
m - max number in array
S = O(n + m) = O(n) 
*/

void countSort(int *a, int n)
{
    int h = findMax(a, n), i, j;
    int b[h + 1] = {0};

    for (i = 0; i < n; i++)
    {
        b[a[i]] += 1;
    }
    j = 0, i = 0;
    while (i < h + 1)
    {
        if (b[i] > 0)
        {
            a[j++] = i;
            b[i] -= 1;
        }
        else
        {
            i += 1;
        }
    }
    display(a, n);
}

int main()
{
    int a[8] = {8, 3, 7, 4, 9, 2, 6, 5};
    countSort(a, 8);
    return 0;
}