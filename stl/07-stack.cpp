#include <stack>
#include <iostream>
#include <list>
using namespace std;

int main()
{
    stack<int> s;
    int n = 5;

    while (n--)
    {
        s.push(n);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}