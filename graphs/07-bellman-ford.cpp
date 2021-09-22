#include "display2.h"

/*
Perform relaxation for (V-1) times on all edges.

Bellmand-Ford algorithm fails if there is an 
-ve weight cycle.
*/

void bellmanFord(int &source, int &vertices, vector<vector<int>> &edges, vector<int> &dist)
{
    int i, j, e = edges.size(), u, v, cost;
    for (i = 1; i <= vertices - 1; i++)
    {
        for (j = 0; j < e; j++)
        {
            u = edges[j][0];
            v = edges[j][1];
            cost = edges[j][2];
            if (dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
            }
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2, 3}, {1, 4, 5}, {4, 3, 2}, {3, 2, -3}}; //{u, v, cost}
    int source = 1, vertices = 4;
    vector<int> dist(vertices + 1, I);
    dist[source] = 0;
    bellmanFord(source, vertices, edges, dist);
    display(dist);
    return 0;
}