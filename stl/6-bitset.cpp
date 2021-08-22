#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    bitset<3> b1(1011);
    bitset<3> b2;
    b2 = ~b1;
    cout << "b1: " << b1 << "\n";
    cout << "b1 count: " << b1.count() << "\n";
    cout << "b2: " << b2 << "\n";

    return 0;
}