#include <queue>
#include <string>
#include <iostream>
using namespace std;

typedef pair<string, int> Max;

struct Compare
{
    bool operator()(Max a, Max b)
    {
        return a.second < b.second;
    }
};

int main()
{
    //Max heap custom data type
    priority_queue<Max, vector<Max>, Compare> p;
    p.push({"a", 1});
    p.push({"c", 1});
    p.push({"b", 3});
    // p.push(make_pair("a", 1));
    // p.push(make_pair("c", 1));
    // p.push(make_pair("b", 3));

    Max top = p.top();
    string s = top.first;
    int i = top.second - 1;
    p.pop();
    p.push({s, i});

    while (!p.empty())
    {
        Max top = p.top();
        cout << top.first << " = " << top.second << "\n";
        p.pop();
    }

    //Max heap int data
    priority_queue<int> p1;
    p1.push(1);
    p1.push(3);
    p1.push(2);

    while (!p1.empty())
    {
        cout << p1.top() << " ";
        p1.pop();
    }
    cout << "\n";

    //Min heap int data
    priority_queue<int, vector<int>, greater<int>> p2;
    p2.push(1);
    p2.push(3);
    p2.push(2);

    while (!p2.empty())
    {
        cout << p2.top() << " ";
        p2.pop();
    }

    return 0;
}