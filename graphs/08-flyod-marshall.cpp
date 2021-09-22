#include "display2.h"

void flyodMarshall(vector<vector<int>> &graph)
{
    int vertices = graph.size() - 1, via, u, v;
    for (via = 1; via <= vertices; via++)
    {
        for (u = 1; u <= vertices; u++)
        {
            for (v = 1; v <= vertices; v++)
            {
                if (graph[u][via] != I && graph[via][v] != I)
                {
                    graph[u][v] = min(graph[u][v], graph[u][via] + graph[via][v]);
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{I, I, I, I, I},
                                 {I, 0, 3, I, 7},
                                 {I, 8, 0, 2, I},
                                 {I, 5, I, 0, 1},
                                 {I, 2, I, I, 0}};
    flyodMarshall(graph);
    display(graph[2]);
    return 0;
}