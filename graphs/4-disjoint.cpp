#include <iostream>
#include <vector>
using namespace std;

void Union(vector<int> &set, int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[u] + set[v];
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

void display(vector<int> set)
{
    for (int i = 0; i < set.size(); i++)
    {
        cout << set[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> super = {-1, -1, -1, -1, -1, -1};
    // display(super);
    // Union(super, 2, 1);
    // Union(super, 1, 3);
    // display(super);
    // Union(super, 4, 5);
    // display(super);
    cout << "Parent of " << 3 << " : " << find(super, 3) << "\n";
    cout << "Parent of " << 4 << " : " << find(super, 4) << "\n";
    return 0;
}