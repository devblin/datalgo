#ifndef MAX
#define MAX

int findMax(int *a, int n)
{
    int i, ans = a[0];
    for (i = 0; i < n; i++)
    {
        ans = max(ans, a[i]);
    }
    return ans;
}

int length(int num)
{
    int count = 0;
    if (num == 0)
        return 1;
    while (num > 0)
    {
        num /= 10;
        count += 1;
    }
    return count;
}

#endif