#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator it;
    int n = 5;

    while (n--)
    {
        v.push_back(n);
    }
    it = v.begin();
    random_shuffle(v.begin() + 1, v.end());

    while (it != v.end())
    {
        cout << v[*it] << " ";
        it++;
    }

    cout << "\n";
    sort(v.begin(), v.end() - 2);
    it = v.begin();

    while (it != v.end())
    {
        cout << v[*it] << " ";
        it++;
    }

    return 0;
}