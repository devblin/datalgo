#ifndef DISPLAY2
#define DISPLAY2

#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

void display(vector<int> &dist)
{
    int n = dist.size(), i, j;
    for (i = 1; i < n; i++)
    {
        cout << i << " => " << dist[i] << "\n";
    }
}

#endif