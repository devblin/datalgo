#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int, greater<int>> s;
    set<int>::iterator si;
    multiset<int, less<int>> ms;
    multiset<int>::iterator msi;

    for (int i = 1; i <= 5; i++)
    {
        s.insert(i);
        s.insert(i * 2);
        ms.insert(i);
        ms.insert(i * 2);
    }
    si = s.begin();
    while (si != s.end())
    {
        cout << *si << " ";
        si++;
    }
    cout << "\n";
    msi = ms.begin();
    while (msi != ms.end())
    {
        cout << *msi << " ";
        msi++;
    }
    return 0;
}