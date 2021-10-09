#include "dispaly.h"
#include "max.h"

/*
Bin/Bucket sort:
T = O(n)
S = O(m + n)
*/

void binSort(int *a, int n)
{
    int h = findMax(a, n), i, j;
    vector<vector<int>> b(h + 1, vector<int>());

    for (i = 0; i < n; i++)
    {
        b[a[i]].push_back(a[i]);
    }

    i = 0, j = 0;
    while (i < h + 1)
    {
        if (!b[i].empty())
        {
            a[j++] = b[i].back();
            b[i].pop_back();
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
    int a[10] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    binSort(a, 10);
    return 0;
}