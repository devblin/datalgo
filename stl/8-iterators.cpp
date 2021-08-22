#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[5];
    vector<int> v(5, 0);
    v[3] = 5;
    a[2] = 5;
    int *it = find(a, a + 5, 5);
    if (it == a + 5)
        cout << "No\n";
    else
        cout << it - a << ", " << *it << "\n";

    vector<int>::iterator vit;
    vit = find(v.begin(), v.end(), 5);

    if (vit == v.end())
        cout << "No\n";
    else
        cout << vit - v.begin() << ", " << *vit << "\n";
    return 0;
}