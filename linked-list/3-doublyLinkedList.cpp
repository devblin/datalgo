#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL, *prev = NULL;
};

class DoublyLink
{
private:
    Node *first = NULL, *last = NULL;

public:
    DoublyLink(int a[], int n);
    void Display();
    void DisplayR();
    void DisplayRR();
    void Insert(int pos, int value);
    ~DoublyLink();
};

DoublyLink::~DoublyLink()
{
    Node *temp = first;
    while (first)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
    cout << "Killed doubly links\n";
}

DoublyLink::DoublyLink(int a[], int n)
{
    int i = 0;
    Node *temp;
    first = new Node;
    first->data = a[0];
    last = first;
    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    cout << "Created doubly linked list....\n";
    Display();
}

void DoublyLink::Display()
{
    Node *temp = first;
    if (!temp)
    {
        cout << "Empty\n";
        return;
    }
    while (temp)
    {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL)
            cout << " <-> ";
    }
    cout << "\n";
}

void DoublyLink::Insert(int pos, int value)
{
    Node *temp, *p = first;
    temp = new Node;
    temp->data = value;
    if (pos == 0)
    {
        temp->next = first;
        temp->prev = first->prev;
        first->prev = temp;
        first = temp;
    }
    else
    {
        while (--pos && p->next != NULL)
            p = p->next;
        temp->next = p->next;
        temp->prev = p;
        if (p->next != NULL)
            p->next->prev = temp;
        p->next = temp;
    }
    Display();
}

void menu(DoublyLink *link)
{
    int option, i, n, pos, value;
    cout << "-----DOUBLY LINKED LIST-----\n";
    cout << "1. Display\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "4. Count\n";
    cout << "0. Exit\n";
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        link->Display();
        break;
    case 2:
        cout << "Position & value: ";
        cin >> pos >> value;
        link->Insert(pos, value);
        break;
    default:
        break;
    }
    cout << "\n";
    if (option)
        menu(link);
}

int main()
{
    int i, n;
    cout << "Size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    DoublyLink *link;
    link = new DoublyLink(a, n);
    menu(link);
    return 0;
}