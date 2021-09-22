#include "display1.h"

void prism(vector<vector<int>> &graph)
{
    int min = INT_MAX, n = graph.size(), u, v, i, j;
    vector<int> vertices(n, 0);
    multimap<int, int> mst;

    //finding first minimum cost edge O(n^2)
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (graph[i][j] < min)
            {
                u = i, v = j;
                min = graph[i][j];
            }
        }
    }

    vertices[u] = vertices[v] = 1;
    mst.insert({u, v});

    // O(n^3)
    while (mst.size() != n - 2) // O(V-1)
    {
        min = INT_MAX;
        for (i = 1; i < n; i++) // O(V)
        {
            if (vertices[i] == 1) // O(V)
            {
                for (j = 1; j < n; j++)
                {
                    if (vertices[j] == 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        mst.insert({u, v});
        vertices[v] = 1;
    }

    display(graph, mst);
}

int main()
{
    vector<vector<int>> graph = {{I, I, I, I, I},
                                 {I, I, 3, 1, I},
                                 {I, 3, I, 2, 5},
                                 {I, 1, 2, I, 4},
                                 {I, I, 5, 4, I}};

    prism(graph);
    return 0;
}