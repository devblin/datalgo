#include <algorithm>
#include <set>
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    set<int, greater<int>> s;
    set<int>::iterator si;
    unordered_set<int> us;
    unordered_set<int>::iterator usi;
    multiset<int, less<int>> ms;
    multiset<int>::iterator msi;
    unordered_multiset<int> ums;
    unordered_multiset<int>::iterator umsi;

    us.insert(3);
    us.insert(4);
    us.insert(3);
    us.insert(5);
    ums.insert(3);
    ums.insert(4);
    ums.insert(3);
    ums.insert(5);

    for (int i = 1; i <= 5; i++)
    {
        s.insert(i);
        s.insert(i * 2);
        ms.insert(i);
        ms.insert(i * 2);
    }

    cout << "Set:\n";
    si = s.begin();
    while (si != s.end())
    {
        cout << *si << " ";
        si++;
    }

    cout << "\nMultiset:\n";
    msi = ms.begin();
    while (msi != ms.end())
    {
        cout << *msi << " ";
        msi++;
    }

    cout << "\nUnorderd set:\n";
    usi = us.begin();
    while (usi != us.end())
    {
        cout << *usi << " ";
        usi++;
    }

    cout << "\nUnordered multiset:\n";
    umsi = ums.begin();
    while (umsi != ums.end())
    {
        cout << *umsi << " ";
        umsi++;
    }
    cout << "\n";

    return 0;
}