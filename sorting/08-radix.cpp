#include "dispaly.h"
#include "max.h"

/*
Radix sort:
d - number of max num's digit
T = O(dn) = O(m)
S = O(1)
*/

void radixSort(int *a, int n)
{
    int i, j, k = 1, index, pass = length(findMax(a, n)), p;
    vector<list<int>> b(10, list<int>());

    for (p = 1; p <= pass; p++)
    {
        for (i = 0; i < n; i++)
        {
            index = (a[i] / k) % 10;
            b[index].push_back(a[i]);
        }
        i = 0, j = 0;
        while (i < 10)
        {
            if (!b[i].empty())
            {
                a[j++] = b[i].front();
                b[i].pop_front();
            }
            else
            {
                i += 1;
            }
        }
        k *= 10;
    }

    display(a, n);
}

int main()
{
    int a[10] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    radixSort(a, 10);
    return 0;
}