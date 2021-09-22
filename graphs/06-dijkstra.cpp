#include "display2.h"

void relax(int source, vector<vector<int>> &graph, vector<int> &dist)
{
    int u = source, v, n = graph.size();
    for (v = 1; v < n; v++)
    {
        if (graph[u][v] != I && dist[u] + graph[u][v] < dist[v])
        {
            dist[v] = dist[u] + graph[u][v];
        }
    }
}

void dijkstra(int source, vector<vector<int>> &graph, vector<int> &visited, vector<int> &dist)
{
    relax(source, graph, dist);
    int u = source, v, minSource = -1, minDist = -1;
    visited[source] = 1;

    for (int v = 1; v < graph.size(); v++)
    {
        if (visited[v] == 0 && graph[u][v] != I)
        {
            if (minDist == -1 || dist[v] < minDist)
            {
                minDist = dist[v];
                minSource = v;
            }
        }
    }

    if (minSource != -1)
    {
        visited[minSource] = 1;
        dijkstra(minSource, graph, visited, dist);
    }
}

int main()
{
    vector<vector<int>> graph = {{I, I, I, I, I, I, I},
                                 {I, I, 2, 4, I, I, I},
                                 {I, I, I, 1, 7, I, I},
                                 {I, I, I, I, I, 3, I},
                                 {I, I, I, I, I, I, 1},
                                 {I, I, I, I, 2, I, 5},
                                 {I, I, I, I, I, I, I}};
    vector<int> visited(graph.size(), 0);
    vector<int> dist(graph.size(), I);
    int source = 1;
    dist[source] = 0;
    dijkstra(source, graph, visited, dist);
    display(dist);
    return 0;
}