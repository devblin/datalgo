#include <bits/stdc++.h>
using namespace std;

set<int> mySet;
unordered_set<int> myUnorderedSet;
multiset<int> myMultiSet;
unordered_multiset<int> myUnorderedMultiSet;

void setMenu()
{
    int value, option;
    cout << "SET:\n";
    cout << "1. Insert\n";
    cout << "2. Erase\n";
    cout << "3. Count\n";
    cout << "4. Size\n";

    cout << "Enter option:";
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Value to insert: ";
        cin >> value;
        mySet.insert(value);
        break;
    case 2:
        cout << "Value to erase: ";
        cin >> value;
        mySet.erase(value);
        break;
    case 3:
        cout << "Value to count: ";
        cin >> value;
        cout << "Count: " << mySet.count(value) << "\n";
        break;
    case 4:
        cout << "Size: " << mySet.size() << "\n";
        break;
    default:
        break;
    }

    for (auto x : mySet)
        cout << x << " ";
    cout << "\n---------------------\n";
}

void unSetMenu()
{
    int value, option;
    cout << "UNORDERED SET:\n";
    cout << "1. Insert\n";
    cout << "2. Erase\n";
    cout << "3. Count\n";
    cout << "4. Size\n";

    cout << "Enter option:";
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Value to insert: ";
        cin >> value;
        myUnorderedSet.insert(value);
        break;
    case 2:
        cout << "Value to erases: ";
        cin >> value;
        myUnorderedSet.erase(value);
        break;
    case 3:
        cout << "Value to count: ";
        cin >> value;
        cout << "Count: " << myUnorderedSet.count(value) << "\n";
        break;
    case 4:
        cout << "Size: " << myUnorderedSet.size() << "\n";
        break;
    default:
        break;
    }
    for (auto x : myUnorderedSet)
        cout << x << " ";
    cout << "\n---------------------\n";
}

void multiSetMenu() {}

void unMultiSetMenu() {}

void menu()
{
    int option;
    cout << "MENU:\n";
    cout << "1. Set\n";
    cout << "2. Unordered Set\n";
    cout << "3. Multiset\n";
    cout << "4. Unordered Multiset\n";
    cout << "Enter option:";
    cin >> option;
    switch (option)
    {
    case 1:
        setMenu();
        break;
    case 2:
        unSetMenu();
        break;
    case 3:
        multiSetMenu();
        break;
    case 4:
        unMultiSetMenu();
        break;
    default:
        break;
    }
    menu();
}

int main()
{
    menu();
    return 0;
}