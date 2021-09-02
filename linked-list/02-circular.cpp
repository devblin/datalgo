#include "node1.h"

class CircularLink
{
public:
    Node *first, *last;
    CircularLink();
    CircularLink(int a[], int n);
    void Display();
    void DisplayR();
    int Count();
    void Insert(int pos, int value);
    void Delete(int pos);
};

CircularLink::CircularLink()
{
    first = new Node;
    first->next = first;
    last = first;
}

CircularLink::CircularLink(int a[], int n)
{
    int i;
    Node *temp;
    first = new Node(a[0]);
    last = first;
    last->next = first;
    for (i = 1; i < n; i++)
    {
        temp = new Node(a[i]);
        last->next = temp;
        last = temp;
        last->next = first;
    }
    cout << "Circular links created\n";
}

int CircularLink::Count()
{
    Node *temp = first;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != first);
    return count;
}

void CircularLink::Display()
{
    Node *temp = first;
    if (first->next == first)
    {
        cout << "Empty\n";
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
    cout << "\n";
}

void CircularLink::DisplayR()
{
    static int flag = 0;
    static Node *temp = first;
    if (first->next == first)
    {
        cout << "Empty\n";
        return;
    }
    if (temp != first || flag != 1)
    {
        flag = 1;
        cout << temp->data << " ";
        temp = temp->next;
        DisplayR();
    }
    else
    {
        flag = 0;
    }
}

void CircularLink::Insert(int pos, int value)
{
    Node *newNode, *temp = first;
    newNode = new Node(value);
    if (pos == 0)
    {
        newNode->next = first;
        first = newNode;
        last->next = first;
    }
    else
    {
        while (--pos)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    Display();
}

void CircularLink::Delete(int pos)
{
    Node *temp, *p;
    p = first;
    if (pos == 1)
    {
        temp = first;
        first = first->next;
        last->next = first;
    }
    else
    {
        pos = pos - 1;
        while (--pos)
            p = p->next;
        temp = p->next;
        p->next = p->next->next;
    }
    delete temp;
    Display();
}

void menu(CircularLink *link)
{
    Node *temp = link->first;
    int option, pos, value;
    cout << "-----CIRCULAR LINKED LISTS-----\n";
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
        link->DisplayR();
        cout << "\n";
        break;
    case 2:
        cout << "Position: ";
        cin >> pos;
        cout << "Value: ";
        cin >> value;
        link->Insert(pos, value);
        break;
    case 3:
        cout << "Position: ";
        cin >> pos;
        link->Delete(pos);
        break;
    case 4:
        cout << "Total nodes: " << link->Count() << "\n";
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
    CircularLink *link;
    int n, i;
    cout << "Size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    link = new CircularLink(a, n);
    menu(link);
    return 0;
}