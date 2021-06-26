#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

class LinkedList
{
public:
    Node *first;

    LinkedList() { first = NULL; }
    LinkedList(int a[], int n);
    ~LinkedList();

    void DisplayI();
    void DisplayR();
    void DisplayRR(Node *head);
    int NodeCount();
    int NodeCountR();
    int SumI();
    int SumR();
};

LinkedList::LinkedList(int a[], int n)
{

    Node *last, *temp;
    int i = 0;
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
}

LinkedList::~LinkedList()
{
    Node *temp = first;
    while (first != NULL)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
    cout << "Killed linkedlist\n";
}

void LinkedList::DisplayI()
{
    if (first == NULL)
        cout << "Linked list empty";
    else
    {
        cout << "Linked list: ";
        Node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << "\n";
}

void LinkedList::DisplayR()
{
    if (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
        DisplayR();
    }
}

void LinkedList::DisplayRR(Node *head)
{
    if (head != NULL)
    {
        DisplayRR(head->next);
        cout << head->data << " ";
    }
}

int LinkedList::NodeCount()
{
    Node *temp = first;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int LinkedList::NodeCountR()
{
    if (first == NULL)
        return 0;
    else
    {
        first = first->next;
        return NodeCountR() + 1;
    }
}

int LinkedList::SumI()
{
    int sum = 0;
    Node *temp = first;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void menu(LinkedList *link)
{
    Node *temp;
    temp = link->first;
    int option, i, n;
    cout << "-----LINKED-LIST-----\n";
    cout << "1. Display\n";
    cout << "2. CountNode\n";
    cout << "3. Sum\n";
    cout << "Enter option: ";
    cin >> option;
    int a[n];
    switch (option)
    {
    case 1:
        link->DisplayI();
        cout << "Linked list: ";
        link->DisplayR();
        cout << "\nLinked list(reverse): ";
        link->first = temp;
        link->DisplayRR(link->first);
        cout << "\n";
        link->first = temp;
        break;
    case 2:
        cout << "No. of nodes: " << link->NodeCount() << "\n";
        cout << "No. of nodes(recursive): " << link->NodeCountR() << "\n";
        link->first = temp;
        break;
    case 3:
        cout << "Sum of nodes: " << link->SumI() << "\n";
        break;
    default:
        break;
    }
    if (option != 0)
        menu(link);
}

int main()
{
    int i, n;
    LinkedList *link;
    cout << "Size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    link = new LinkedList(a, n);
    cout << "Linkedlist created...\n";
    menu(link);
    return 0;
}