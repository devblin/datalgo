#ifndef STACK
#define STACK
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data);
};

Node::Node(int data)
{
    this->data = data;
    next = nullptr;
}

class StackLink
{
private:
    Node *topnode;

public:
    StackLink();
    bool empty();
    bool full();
    void push(int data);
    void pop();
    int top();
    int peek(int pos);
    void display();
    ~StackLink();
};

StackLink::StackLink()
{
    topnode = nullptr;
}

bool StackLink::empty()
{
    if (!topnode)
        return true;
    return false;
}

bool StackLink::full()
{
    Node *temp = new Node(0);
    if (!temp)
        return true;
    return false;
}

void StackLink::push(int data)
{
    if (!full())
    {
        Node *newnode = new Node(data);
        newnode->next = topnode;
        topnode = newnode;
    }
    else
        cout << "Stack full\n";
}

void StackLink::pop()
{
    Node *temp;
    if (!empty())
    {
        temp = topnode;
        topnode = topnode->next;
        delete temp;
    }
    else
        cout << "Stack empty\n";
}

int StackLink::top()
{
    if (!empty())
        return topnode->data;
    return -1;
}

int StackLink::peek(int pos)
{
    Node *temp = topnode;
    if (pos > 0 && !empty())
    {
        while (--pos && temp)
            temp = temp->next;
        return (temp ? temp->data : -1);
    }
    return -1;
}

void StackLink::display()
{
    Node *temp = topnode;
    if (!empty())
        while (temp)
        {
            cout << "|" << temp->data << "|\n";
            temp = temp->next;
        }
    else
        cout << "Stack empty\n";
}

StackLink::~StackLink()
{
    Node *temp;
    while (topnode)
    {
        temp = topnode;
        topnode = topnode->next;
        delete temp;
    }
}

class Stack
{
private:
    int *A;
    int size;
    int topPos = -1;

public:
    Stack(int size);
    bool empty();
    bool full();
    void push(int data);
    void pop();
    int peek(int pos);
    int top();
    void display();
};

Stack::Stack(int size)
{
    this->size = size;
    A = new int[size];
}

bool Stack::empty()
{
    if (topPos == -1)
        return true;
    return false;
}

bool Stack::full()
{
    if (topPos == size - 1)
        return true;
    return false;
}

void Stack::push(int data)
{
    if (!full())
        A[++topPos] = data;
    else
        cout << "Stack full\n";
}

void Stack::pop()
{
    if (!empty())
        A[topPos--] = -1;
    else
        cout << "Stack empty\n";
}

int Stack::peek(int pos)
{
    int index = topPos + 1 - pos;
    if (index >= 0 && index <= topPos)
        return A[index];
    return -1;
}

int Stack::top()
{
    if (!empty())
        return A[topPos];
    return -1;
}

void Stack::display()
{
    int i = 1;
    if (!empty())
        while (peek(i) != -1)
            cout << "|" << peek(i++) << "|\n";
    else
        cout << "Stack empty\n";
}

#endif