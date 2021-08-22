#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
int main()
{
    deque<int> v;

    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i);
        v.push_front(-i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << "F: " << v.front() << ", B: " << v.back() << "\n";
        v.pop_front();
        v.pop_back();
    }

    return 0;
}