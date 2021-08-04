#ifndef QUEUE
#define QUEUE

#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int data);
};

Node::Node(int data)
{
    this->data = data;
}

//Queue using linkedlists
class QueueLink
{
private:
    Node *frontnode, *rearnode;

public:
    QueueLink();
    void enqueue(int value); // O(1)
    void dequeue();          // O(1)
    int front();             // O(1)
    int rear();              // O(1)
    bool empty();            // O(1)
    bool full();             // O(1)
    void display();          // O(n)
    ~QueueLink();
};

QueueLink::QueueLink()
{
    frontnode = nullptr;
    rearnode = nullptr;
}

bool QueueLink::empty()
{
    if (!frontnode || !rearnode)
        return true;
    return false;
}

bool QueueLink::full()
{
    Node *temp = new Node(0);
    if (!temp)
        return true;
    return false;
}

void QueueLink::enqueue(int value)
{
    if (!full())
    {
        Node *newnode = new Node(value);
        if (empty())
            rearnode = frontnode = newnode;
        else
        {
            rearnode->next = newnode;
            rearnode = newnode;
        }
    }
    else
        cout << "Queue full\n";
}

void QueueLink::dequeue()
{
    Node *temp;
    if (!empty())
    {
        temp = frontnode;
        frontnode = frontnode->next;
        delete temp;
    }
    else
        cout << "Queue empty\n";
}

int QueueLink::front()
{
    if (frontnode)
        return frontnode->data;
    return -1;
}

int QueueLink::rear()
{
    if (rearnode)
        return rearnode->data;
    return -1;
}

void QueueLink::display()
{
    if (!empty())
    {
        Node *temp = frontnode;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    else
        cout << "Queue empty";
    cout << "\n";
}

QueueLink::~QueueLink()
{
    Node *temp;
    while (frontnode)
    {
        temp = frontnode;
        frontnode = frontnode->next;
        delete temp;
    }
}
#endif