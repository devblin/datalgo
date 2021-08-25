#include <iostream>
#include <map>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <typeinfo>
using namespace std;

int main()
{

    map<int, int, less<int>> m1;
    map<int, int>::iterator mi1;
    map<char, int, greater<char>> m2;
    map<char, int>::iterator mi2;

    char x = 'a';

    for (int i = 1; i <= 5; i++)
    {
        m1[rand() % 100] = i;
        m2[i + x] = i;
    }
    mi1 = m1.begin();
    while (mi1 != m1.end())
    {
        cout << mi1->first << " => " << mi1->second << "\n";
        mi1++;
    }

    mi2 = m2.begin();
    while (mi2 != m2.end())
    {
        cout << mi2->first << " => " << mi2->second << "\n";
        mi2++;
    }
    return 0;
}