#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

void setUnion(vector<int> &set, int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(vector<int> set, int u)
{
    int x = u;
    while (set[x] > 0)
    {
        x = set[x];
    }
    return x;
}

void krushkal(vector<vector<int>> &graph)
{
    int u, v, n = graph.size(), min = INT_MAX, i, j;
    vector<int> vertices(n, 0);
    vector<int> set(n, -1);
    multimap<int, int> mst;
    multimap<int, int>::iterator m;

    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = 1; j < n; j++)
        {
            if (graph[i][j] < min && find(set, i) != find(set, j) && (vertices[i] == 0 || vertices[j] == 0))
            {
                min = graph[i][j];
                u = i;
                v = j;
            }
        }

        mst.insert({u, v});
        vertices[u] = 1;
        vertices[v] = 1;
        setUnion(set, find(set, u), find(set, v));
    }

    for (m = mst.begin(); m != mst.end(); m++)
    {
        cout << m->first << " - " << m->second << "\n";
    }
}

int main()
{
    vector<vector<int>> graph = {{I, I, I, I, I},
                                 {I, I, 3, 1, I},
                                 {I, 3, I, 2, 5},
                                 {I, 1, 2, I, 4},
                                 {I, I, 5, 4, I}};

    krushkal(graph);
    return 0;
}