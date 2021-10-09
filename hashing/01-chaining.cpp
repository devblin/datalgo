#include <iostream>
#include <queue>
using namespace std;

/*
Chaining:
Loading factor = k = hashTable Size / number of keys
Successful search = T = 1 + k/2
Unsuccesful search = T = 1 + k
*/

int hashFunction(int key)
{
    return key % 10;
}

void insert(vector<priority_queue<int, vector<int>, greater<int>>> &hashTable, int key)
{
    int index = hashFunction(key);
    hashTable[index].push(key);
}

int search(vector<priority_queue<int, vector<int>, greater<int>>> &hashTable, int key)
{
    int index = hashFunction(key);

    if (hashTable[index].empty())
        return -1;

    priority_queue<int, vector<int>, greater<int>> temp = hashTable[index];

    while (!temp.empty())
    {
        if (temp.top() == key)
        {
            return index;
        }
        if (key < temp.top())
        {
            return -1;
        }
        temp.pop();
    }

    return -1;
}

int main()
{
    vector<priority_queue<int, vector<int>, greater<int>>> hashTable(10, priority_queue<int, vector<int>, greater<int>>());
    int keys[9] = {16, 12, 25, 39, 6, 122, 5, 68, 75}, i;

    for (i = 0; i < 9; i++)
    {
        insert(hashTable, keys[i]);
    }

    cout << search(hashTable, 1) << "\n";
    cout << search(hashTable, 16) << "\n";
    cout << search(hashTable, 85) << "\n";
    cout << search(hashTable, 62);

    return 0;
}