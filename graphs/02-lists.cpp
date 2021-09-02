#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    vector<Node *> *neighbors;
    Node(int value = 0)
    {
        this->value = value;
        neighbors = new vector<Node *>;
    }
};

class Graph
{
private:
    Node *G;

public:
    Graph();
    void create(vector<vector<int>> edges);
    void bfs(int start);
    void dfs(int start);
    void dfsR(int start, map<Node *, int> &visited);
    void display();
};

Graph::Graph()
{
    G = new Node();
}

void Graph::display()
{
    int i, j, n = G->neighbors->size();
    for (i = 0; i < n; i++)
    {
        cout << (*(G->neighbors))[i]->value << " => [ ";
        for (j = 0; j < (*(G->neighbors))[i]->neighbors->size(); j++)
        {
            cout << (*(*(G->neighbors))[i]->neighbors)[j]->value << " ";
        }
        cout << "]\n";
    }
}

void Graph::create(vector<vector<int>> edges)
{
    map<int, Node *> verticesAdd;
    int u, v, e, edgesNum = edges.size();

    for (e = 0; e < edgesNum; e++)
    {
        u = edges[e][0];
        v = edges[e][1];

        if (verticesAdd.find(u) == verticesAdd.end())
        {
            verticesAdd[u] = new Node(u);
            G->neighbors->push_back(verticesAdd[u]);
        }
        if (verticesAdd.find(v) == verticesAdd.end())
        {
            verticesAdd[v] = new Node(v);
            G->neighbors->push_back(verticesAdd[v]);
        }

        verticesAdd[u]->neighbors->push_back(verticesAdd[v]);
    }
    display();
}

void Graph::bfs(int start)
{
    Node *u, *v;
    int i;
    deque<Node *> vertices;
    map<Node *, int> visited;
    u = G->neighbors->at(start - 1);
    cout << u->value;
    visited[u] = 1;
    vertices.push_back(u);
    while (!vertices.empty())
    {
        u = vertices.front();
        vertices.pop_front();
        for (i = 0; i < u->neighbors->size(); i++)
        {
            v = u->neighbors->at(i);
            if (visited.find(v) == visited.end())
            {
                cout << " -> ";
                visited[v] = 1;
                cout << v->value;
                vertices.push_back(v);
            }
        }
    }
    cout << "\n";
}

void Graph::dfs(int start)
{
    Node *u, *v;
    int i;
    stack<Node *> vertices;
    map<Node *, int> visited;
    u = G->neighbors->at(start - 1);
    cout << u->value;
    visited[u] = 1;
    vertices.push(u);
    while (!vertices.empty())
    {
        u = vertices.top();
        vertices.pop();
        for (i = 0; i < u->neighbors->size(); i++)
        {
            v = u->neighbors->at(i);
            if (visited.find(v) == visited.end())
            {
                cout << " -> ";
                visited[v] = 1;
                cout << v->value;
                vertices.push(v);
                break;
            }
        }
    }
    cout << "\n";
}

void Graph::dfsR(int start, map<Node *, int> &visited)
{
    Node *v, *u = G->neighbors->at(start - 1);
    if (visited.find(u) == visited.end())
    {
        visited[u] = 1;
        cout << u->value;
    }

    for (int i = 0; i < u->neighbors->size(); i++)
    {
        v = u->neighbors->at(i);
        if (visited.find(v) == visited.end())
        {
            cout << " -> " << v->value;
            visited[v] = 1;
            dfsR(v->value, visited);
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 1}, {3, 2}, {3, 1}, {3, 4}, {3, 5}, {4, 1}, {4, 3}, {4, 5}, {5, 4}, {5, 3}};
    Graph *g = new Graph();
    g->create(edges);
    cout << "BFS:\n";
    g->bfs(1);
    g->bfs(4);
    cout << "DFS:\n";
    g->dfs(1);
    g->dfs(4);
    map<Node *, int> visited;
    g->dfsR(1, visited);
    visited.clear();
    cout << "\n";
    g->dfsR(4, visited);

    delete g;
    return 0;
}