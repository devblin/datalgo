#ifndef DISPLAY1
#define DISPLAY1

#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

void display(vector<vector<int>> &graph, multimap<int, int> mst)
{
    int cost = 0, u, v;
    multimap<int, int>::iterator m;

    for (m = mst.begin(); m != mst.end(); m++)
    {
        u = m->first, v = m->second;
        cout << u << " - " << v << " : " << graph[u][v] << "\n";
        cost += graph[u][v];
    }
    cout << "Min cost: " << cost << "\n";
}

#endif