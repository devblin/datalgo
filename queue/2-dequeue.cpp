#include <bits/stdc++.h>
using namespace std;

//Dequeue using array
class Dequeue
{
private:
    int *D, size, front = -1, rear = -1;

public:
    Dequeue(int size);
    ~Dequeue();
};

Dequeue::Dequeue(int size)
{
    D = new int[size];
    this->size = size;
}

Dequeue::~Dequeue()
{
    delete[] D;
}

//Node structure
class Node
{
public:
    int data;
    Node *next = nullptr, *prev = nullptr;
    Node(int data);
};

Node::Node(int data)
{
    this->data = data;
}

//Dequeue using doubly-linkedlist
class DequeueLink
{
private:
    Node *rearnode, *frontnode;

public:
    DequeueLink();
    void pushFront(int value);
    void pushRear(int value);
    void popFront();
    void popRear();
    bool empty();
    bool full();
    void display();
    ~DequeueLink();
};

DequeueLink::DequeueLink()
{
    rearnode = frontnode = nullptr;
}

bool DequeueLink::empty()
{
    if (!frontnode)
        return true;
    return false;
}

bool DequeueLink::full()
{
    Node *temp = new Node(0);
    if (!temp)
        return true;
    return false;
}

void DequeueLink::pushFront(int value)
{
    if (!full())
    {
        Node *newnode = new Node(value);
        if (empty())
            rearnode = frontnode = newnode;
        else
        {
            newnode->next = frontnode;
            frontnode->prev = newnode;
            frontnode = newnode;
        }
    }
    else
        cout << "Dequeue full\n";
}

void DequeueLink::pushRear(int value)
{
    if (!full())
    {
        Node *newnode = new Node(value);
        if (empty())
            rearnode = frontnode = newnode;
        else
        {
            rearnode->next = newnode;
            newnode->prev = rearnode;
            rearnode = newnode;
        }
    }
}

void DequeueLink::popFront()
{
    Node *temp;
    if (!empty())
    {
        temp = frontnode;
        frontnode = frontnode->next;
        if (frontnode)
            frontnode->prev = nullptr;
        delete temp;
    }
    else
        cout << "Dequeue empty\n";
}

void DequeueLink::popRear()
{
    Node *temp;
    if (!empty())
    {
        temp = rearnode;
        rearnode = rearnode->prev;
        if (rearnode)
            rearnode->next = nullptr;
        delete temp;
    }
    else
        cout << "Dequeue empty\n";
}

void DequeueLink::display()
{
    Node *temp = frontnode;
    if (!empty())
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    else
        cout << "Dequeue empty";
    cout << "\n";
}

DequeueLink::~DequeueLink()
{
    Node *temp;
    while (frontnode)
    {
        temp = frontnode;
        frontnode = frontnode->next;
        delete temp;
    }
}

void menu(DequeueLink *dl)
{
    int option, value;
    cout << "----DEQUEUE----\n";
    cout << "1.push front\n2.push rear\n3.pop front\n4.pop rear\n5.display\n0.exit\n";
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
    case 2:
        cout << "Enter value: ";
        cin >> value;
        if (option == 1)
            dl->pushFront(value);
        else
            dl->pushRear(value);
        break;
    case 3:
        dl->popFront();
        break;
    case 4:
        dl->popRear();
        break;
    case 5:
        dl->display();
        break;
    default:
        break;
    }
    if (option != 0)
        menu(dl);
}

int main()
{
    DequeueLink *dl = new DequeueLink();
    menu(dl);
    return 0;
}