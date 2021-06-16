#include <bits/stdc++.h>
using namespace std;

string myStr = "";
void menu()
{
    cout << "STRINGS:\n";
    cout << "1. Concat character\n";
    cout << "2. Find occurence of substring\n";
    cout << "3. Get substring\n";
    string v;
    int x, k;
    cout << "Enter option:";
    cin >> x;
    switch (x)
    {
    case 1:
        cin >> v;
        myStr += v;
        break;
    case 2:
        cin >> v;
        cout << "Position of " << v << ":" << myStr.find(v) << "\n";
        break;
    case 3:
        cout << "Start position:";
        cin >> x;
        cout << "Length:";
        cin >> k;
        if (myStr.size() > 0 && (x + k) < myStr.size())
            cout << "Substr starting at " << x << " of length " << k << ":" << myStr.substr(x, k) << "\n";
        else
            cout << "Position and Length constraints out of range\n";
        break;
    default:
        break;
    }
    cout << "String: " << myStr << "\n";
    cout << "-------------------------\n";
    menu();
}

int main()
{
    menu();
    return 0;
}