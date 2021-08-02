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

void menu(Stack *s, StackLink *sl)
{
    int option, value, pos;
    cout << "----STACK----\n";
    cout << "1. pop\n2. push\n3. peek\n4. top\n5. display\n6. empty\n7. full\n";
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        s->pop();
        sl->pop();
        break;
    case 2:
        cout << "Value: ";
        cin >> value;
        s->push(value);
        sl->push(value);
        break;
    case 3:
        cout << "Position: ";
        cin >> pos;
        cout << "Peek: " << s->peek(pos) << ", " << sl->peek(pos) << "\n";
        break;
    case 4:
        cout << "Top: " << s->top() << ", " << sl->top() << "\n";
        break;
    case 5:
        s->display();
        cout << "----\n";
        sl->display();
        break;
    case 6:
        cout << "Empty: " << s->empty() << ", " << sl->empty() << "\n";
        break;
    case 7:
        cout << "Full: " << s->full() << ", " << sl->full() << "\n";
        break;
    default:
        break;
    }
    if (option != 0)
        menu(s, sl);
}

int main()
{
    Stack *s = new Stack(5);
    StackLink *sl = new StackLink();
    menu(s, sl);
    return 0;
}