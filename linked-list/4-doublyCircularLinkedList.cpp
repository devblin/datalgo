#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = NULL, *next = NULL;
};

class DoublyCircularLink
{
private:
    Node *first, *last;

public:
    DoublyCircularLink();
    DoublyCircularLink(int a[], int n);
    void Display();
    void Insert(int pos, int value);
    void Delete(int pos);
    ~DoublyCircularLink();
};

DoublyCircularLink::DoublyCircularLink(int a[], int n)
{
    int i;
    Node *temp;
    first = new Node;
    first->data = a[0];
    last = first;
    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        last->next = temp;
        last = temp;
    }
    last->next = first;
    first->prev = last;
    Display();
}

void DoublyCircularLink::Display()
{
    Node *temp = first;
    if (first == NULL)
    {
        cout << "Empty\n";
        return;
    }
    while (temp->next != first)
    {
        cout << temp->data;
        temp = temp->next;
        if (temp != first)
            cout << " <-> ";
        if (temp->next == first)
            cout << temp->data;
    }
    if (first != NULL && first == last)
        cout << first->data;
    cout << "\n";
}

void DoublyCircularLink::Insert(int pos, int value)
{
    Node *t, *p = first;
    t = new Node;
    t->data = value;
    if (pos == 0)
    {
        t->next = first;
        t->prev = last;
        first->prev = t;
        last->next = t;
        first = t;
    }
    else
    {
        while (--pos)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
        last = first->prev;
    }
    Display();
}

void DoublyCircularLink::Delete(int pos)
{
    Node *t, *p = first;
    if (first != NULL)
    {
        if (first == last && pos == 1)
            first = NULL;
        else if (pos == 1)
        {
            t = first;
            first = first->next;
            first->prev = last;
            last->next = first;
        }
        else
        {
            pos = pos - 1;
            while (--pos)
                p = p->next;
            t = p->next;
            p->next = p->next->next;
            p->next->prev = p;
        }
        delete t;
    }
    Display();
}

void menu(DoublyCircularLink *link)
{
    int i, option, pos, value;
    cout << "-----DOUBLY CIRCULAR LINKEDLIST-----\n";
    cout << "1. Display\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "0. Exit\n";
    cout << "Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        link->Display();
        break;
    case 2:
        cout << "Position & Value: ";
        cin >> pos >> value;
        link->Insert(pos, value);
        break;
    case 3:
        cout << "Position: ";
        cin >> pos;
        link->Delete(pos);
        break;
    default:
        break;
    }
    cout << "\n";
    if (option != 0)
        menu(link);
}

int main()
{
    int n, i;
    cout << "Size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    DoublyCircularLink *link;
    link = new DoublyCircularLink(a, n);
    menu(link);
    return 0;
}