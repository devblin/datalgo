#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    list<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    // random_shuffle(v.begin(), v.end());

    for (int j = 0; j < 10; j++)
    {
        cout << "F: " << v.front() << ", B:" << v.back() << "\n";
        v.pop_front();
        v.pop_back();
    }
    cout << "\n";
    for (int j = 0; j < 10; j++)
    {
        cout << v.front() << " ";
        cout << v.back() << " ";
    }
    cout << "\n";

    return 0;
}