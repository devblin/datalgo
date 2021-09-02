#ifndef NODE1
#define NODE1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int data = 0)
    {
        this->data = data;
    }
};

#endif