#ifndef HASHING
#define HASHING

#include "../sorting/dispaly.h"

int hashFunction(int key)
{
    return key % 10;
}

int search(int *hashTable, int key)
{
    int index = hashFunction(key), i = 0, newIndex = probe(index, i);
    while (hashTable[newIndex] != key && hashTable[newIndex] != 0)
    {
        i += 1;
        newIndex = probe(index, i);
    }
    if (hashTable[newIndex] == 0)
    {
        return -1;
    }
    return newIndex;
}

void insert(int *hashTable, int key)
{
    int index = hashFunction(key), i = 0, nextIndex = probe(index, i);
    while (hashTable[nextIndex] != 0)
    {
        i += 1;
        nextIndex = probe(index, i);
    }
    hashTable[nextIndex] = key;
}

int main()
{
    int hashTable[10] = {0};
    insert(hashTable, 12);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 45);
    insert(hashTable, 65);
    display(hashTable, 10);
    cout << search(hashTable, 25) << "\n";
    cout << search(hashTable, 65);
    return 0;
}

#endif