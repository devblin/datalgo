#ifndef NODE2
#define NODE2

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL, *prev = NULL;
    Node(int data = 0)
    {
        this->data = data;
    }
};

#endif