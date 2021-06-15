#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void printVector(vector<int> v)
{
    for (auto x : v)
        cout << x << " ";
    cout << "\n";
}

void intro()
{
    cout << "VECTORS:\n";
    cout << "1. push_back(value)\n";
    cout << "2. pop_back()\n";
}

void menu()
{
    int x;
    intro();
    cout << "Enter option: ";
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "Enter value to push: ";
        cin >> x;
        v.push_back(x);
        cout << "Pushed:" << x << "\n";
        break;
    case 2:
        if (v.size() > 0)
        {
            cout << "Poped:" << v.back() << "\n";
            v.pop_back();
        }
        else
        {
            cout << "Vector Empty\n";
        }
        break;
    default:
        break;
    }
    cout << "Vector now\n";
    if (v.size() > 0)
        printVector(v);
    else
        cout << "Nothing to print\n";
    cout << "--------------------------------------\n";
    menu();
}

int main()
{
    menu();
    return 0;
}