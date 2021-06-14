#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutationSwap(string x, int k = 0)
{
    static int strLen = x.size();
    int i;
    for (i = 0; i < strLen - 1; i++)
    {
        cout << x << "\n";
        swap(x[i], x[i + 1]);
    }
    if (k <= strLen - 1)
    {
        permutationSwap(x, k + 1);
    }
}

void permutation(string x, int k = 0)
{
    static int A[10] = {0}, strLen = x.size();
    static char res[10];
    int i;
    if (x[k] == '\0')
        cout << res << "\n";
    else
    {
        for (i = 0; i < strLen; i++)
        {
            if (A[i] == 0)
            {
                res[k] = x[i];
                A[i] = 1;
                permutation(x, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    string x;
    cin >> x;
    permutation(x);
    cout << "---\n";
    permutationSwap(x);
    return 0;
}