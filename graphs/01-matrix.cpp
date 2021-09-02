#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int size;
    int **G;
    Graph(int size);
    void create(vector<vector<int>> edges);
    void display();
    void bfs(int start);
    void dfs(int start);
    void dfsR(int start, vector<int> &visited);
    ~Graph();
};

Graph::Graph(int size)
{
    int i, j;
    this->size = size;
    G = new int *[size];
    for (i = 0; i < size; i++)
    {
        G[i] = new int[size]{0};
    }
}

void Graph::display()
{
    int u, v;
    for (u = 0; u < size; u++)
    {
        cout << u + 1 << " -> ";
        for (v = 0; v < size; v++)
        {
            cout << G[u][v] << " ";
        }
        cout << "\n";
    }
}

void Graph::create(vector<vector<int>> edges)
{
    int edgesNum = edges.size();
    int u, v, e;
    for (e = 0; e < edgesNum; e++)
    {
        u = edges[e][0] - 1;
        v = edges[e][1] - 1;
        G[u][v] = 1;
    }
    display();
}

void Graph::bfs(int start)
{
    int u, v;
    deque<int> vertexs;
    vector<int> visited(size, 0);
    cout << start;
    visited[start - 1] = 1;
    vertexs.push_back(start - 1);

    while (!vertexs.empty())
    {
        u = vertexs.front();
        vertexs.pop_front();
        for (v = 0; v < size; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << " -> " << v + 1;
                vertexs.push_back(v);
                visited[v] = 1;
            }
        }
    }
    cout << "\n";
}

void Graph::dfs(int start)
{
    int u, v;
    stack<int> vertices;
    vector<int> visited(size, 0);
    cout << start;
    u = start - 1;
    visited[u] = 1;
    vertices.push(u);

    while (!vertices.empty())
    {
        u = vertices.top();
        vertices.pop();
        for (v = 0; v < size; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << " -> " << v + 1;
                vertices.push(v);
                visited[v] = 1;
                break;
            }
        }
    }
    cout << "\n";
}

void Graph::dfsR(int start, vector<int> &visited)
{
    int v, u = start - 1;

    if (visited[u] == 0)
    {
        cout << u + 1;
        visited[u] = 1;
    }

    for (v = 0; v < size; v++)
    {
        if (G[u][v] == 1 && visited[v] == 0)
        {
            cout << " -> " << v + 1;
            visited[v] = 1;
            dfsR(v + 1, visited);
        }
    }
}

Graph::~Graph()
{
    delete G;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 1}, {3, 2}, {3, 1}, {3, 4}, {3, 5}, {4, 1}, {4, 3}, {4, 5}, {5, 4}, {5, 3}};
    Graph *g = new Graph(5);
    g->create(edges);
    cout << "BFS:\n";
    g->bfs(1);
    g->bfs(4);
    cout << "DFS:\n";
    g->dfs(1);
    g->dfs(4);
    vector<int> visited(g->size, 0);
    g->dfsR(1, visited);
    cout << "\n";
    fill(visited.begin(), visited.end(), 0);
    g->dfsR(4, visited);

    return 0;
}
