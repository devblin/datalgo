#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    //ordered map
    map<int, int> m;
    map<int, int>::iterator mi;
    m[1] = 40;
    m[4] = 10;
    m[3] = 20;
    m[2] = 20;

    cout << "Ordered map:\n";
    for (mi = m.begin(); mi != m.end(); mi++)
    {
        cout << mi->first << " => " << mi->second << "\n";
    }

    //unordered map
    unordered_map<int, int> u;
    unordered_map<int, int>::iterator ui;
    u[2] = 10;
    u[1] = 20;
    u[4] = 5;
    u[3] = 40;
    // u.insert(pair<int, int>(2, 10));
    // u.insert(pair<int, int>(1, 20));
    // u.insert(pair<int, int>(4, 5));
    // u.insert(pair<int, int>(3, 40));

    cout << "Uordered map:\n";
    for (ui = u.begin(); ui != u.end(); ui++)
    {
        cout << ui->first << " => " << ui->second << "\n";
    }

    //multimap
    multimap<int, int> mm;
    multimap<int, int>::iterator mmi;

    mm.insert({1, 1});
    mm.insert({3, 3});
    mm.insert({1, 11});
    mm.insert({4, 4});

    cout << "Ordered multi-map:\n";
    for (mmi = mm.begin(); mmi != mm.end(); mmi++)
    {
        cout << mmi->first << " => " << mmi->second << "\n";
    }

    //Unorderd multimap
    unordered_multimap<int, int> um;
    unordered_multimap<int, int>::iterator umi;

    um.insert({4, 4});
    um.insert({1, 11});
    um.insert({3, 3});
    um.insert({1, 1});

    cout << "Unordered multi-map:\n";
    for (umi = um.begin(); umi != um.end(); umi++)
    {
        cout << umi->first << " => " << umi->second << "\n";
    }

    return 0;
}