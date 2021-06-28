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
    Node *first, *last;

    LinkedList() { first = NULL; }
    LinkedList(int a[], int n);
    ~LinkedList();

    void DisplayI();
    void DisplayR();
    void DisplayRR();
    int NodeCount();
    int NodeCountR();
    int SumI();
    int SumR();
    int MaxI();
    int MaxR();
    Node *LSearchI(int key);
    Node *LSearchR(int key);
    Node *LSearchMTH(int key);
    Node *LSearchT(int key);
    void Insert(int pos, int val);
    void Append(int val);
    void InsertSorted(int val);
    void Delete(int pos);
    bool CheckSorted();
    void RemoveDuplicates();
    void ReverseElement();
    void ReverseLinksI();
    void ReverseLinksR(Node *q, Node *p);
    void Concat(LinkedList *second);
    void Merging(LinkedList *second);
    void AddLoop(int pos);
    bool CheckLoop();
};

LinkedList::LinkedList(int a[], int n)
{
    Node *temp;
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

void LinkedList::DisplayRR()
{
    int data;
    if (first != NULL)
    {
        data = first->data;
        first = first->next;
        DisplayRR();
        cout << data << " ";
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

int LinkedList::SumR()
{
    int data;
    if (first == NULL)
        return 0;

    data = first->data;
    first = first->next;
    return SumR() + data;
}

int LinkedList::MaxI()
{
    int max = INT_MIN;
    Node *temp = first;
    while (temp)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

int LinkedList::MaxR()
{
    static int max = INT_MIN;
    if (first == NULL)
        return max;
    if (first->data > max)
        max = first->data;
    first = first->next;
    return MaxR();
}

Node *LinkedList::LSearchI(int key)
{
    Node *temp;
    temp = first;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Node *LinkedList::LSearchR(int key)
{
    if (first == NULL)
        return NULL;
    if (first->data == key)
        return first;
    first = first->next;
    return LSearchR(key);
}

Node *LinkedList::LSearchMTH(int key)
{
    Node *lead, *follower;
    follower = NULL;
    lead = first;
    if (lead == NULL)
        return NULL;
    if (lead->data == key)
        return lead;
    while (lead->data != key)
    {
        follower = lead;
        lead = lead->next;
        if (lead == NULL)
            return NULL;
    }
    follower->next = lead->next;
    lead->next = first;
    first = lead;
    return first;
}

Node *LinkedList::LSearchT(int key)
{
    Node *p, *q, *temp, *ans;
    q = NULL;
    p = first;
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    while (p->next->data != key)
    {
        q = p;
        p = p->next;
        if (p->next == NULL)
            return NULL;
    }
    ans = p->next;
    q->next = p->next;
    temp = p->next->next;
    q->next->next = p;
    p->next = temp;
    return ans;
}

void LinkedList::Insert(int pos, int val)
{
    Node *newNode, *p;
    newNode = new Node;
    newNode->data = val;
    p = first;
    if (pos < 0 || pos > NodeCount())
        cout << "Invalid pos\n";
    else
    {
        if (first == NULL)
            first = last = newNode;
        else
        {
            if (pos == NodeCount())
                last = newNode;
            if (pos == 0)
            {
                newNode->next = first;
                first = newNode;
            }
            else
            {
                pos = pos - 1;
                while (pos--)
                    p = p->next;
                newNode->next = p->next;
                p->next = newNode;
            }
        }
    }
    DisplayI();
}

void LinkedList::Append(int val)
{
    Node *newNode;
    newNode = new Node;
    newNode->data = val;
    if (first == NULL)
        first = last = newNode;
    else
    {
        last->next = newNode;
        last = newNode;
    }
    DisplayI();
}

void LinkedList::InsertSorted(int val)
{
    Node *newNode, *p, *temp;
    newNode = new Node;
    newNode->data = val;
    p = first;
    if (!first)
        first = last = newNode;
    else if (first->data > val)
    {
        newNode->next = first;
        first = newNode;
    }
    else
    {
        while (p->next != NULL && p->next->data < val)
            p = p->next;
        if (p->next == NULL)
            last->next = newNode;
        else
        {
            temp = p->next;
            p->next = newNode;
            newNode->next = temp;
        }
    }
    DisplayI();
}

void LinkedList::Delete(int pos)
{
    if (first == NULL)
    {
        cout << "Linked list empty\n";
        return;
    }
    Node *p, *temp;
    p = first;
    pos = pos - 1;
    if (pos == 0)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    else if (pos >= 0 && pos <= NodeCount())
    {
        while (--pos)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
    else
        cout << "Invalid pos\n";
    DisplayI();
}

bool LinkedList::CheckSorted()
{
    Node *temp;
    temp = new Node;
    temp = first;
    while (temp->next != NULL)
    {
        if (temp->data > temp->next->data)
            return false;
        temp = temp->next;
    }
    return true;
}

void LinkedList::RemoveDuplicates()
{
    Node *p, *temp;
    p = new Node;
    p = first;
    if (!first)
        return;
    else
    {
        while (p->next != NULL)
        {
            if (p->data == p->next->data)
            {
                temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
                p = p->next;
        }
    }
    DisplayI();
}

void LinkedList::ReverseElement()
{
    Node *p;
    p = new Node;
    p = first;
    int a[NodeCount()], i = 0;

    while (p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = first;
    while (i--)
    {
        p->data = a[i];
        p = p->next;
    }
    DisplayI();
}

void LinkedList::ReverseLinksI()
{
    Node *p, *q, *r;
    r = NULL;
    q = NULL;
    p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    DisplayI();
}

void LinkedList::ReverseLinksR(Node *q, Node *p)
{
    if (p != NULL)
    {
        ReverseLinksR(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void LinkedList::Concat(LinkedList *second)
{
    last->next = second->first;
    last = second->last;
    second->first = NULL;
    second->last = NULL;
    delete second->first;
    delete second->last;
    DisplayI();
}

void LinkedList::Merging(LinkedList *second)
{
    Node *f, *s, *temp;
    temp = first;
    if (first->data < second->first->data)
    {
        f = s = first;
        first = first->next;
    }
    else
    {
        f = s = second->first;
        second->first = second->first->next;
    }
    s->next = NULL;
    while (first && second->first)
    {
        if (first->data < second->first->data)
        {
            s->next = first;
            s = first;
            first = first->next;
        }
        else
        {
            s->next = second->first;
            s = second->first;
            second->first = second->first->next;
        }
        s->next = NULL;
    }
    if (first)
        s->next = first;
    if (second->first)
        s->next = second->first;
    first = temp;
    first = f;
    DisplayI();
}

void LinkedList::AddLoop(int pos)
{
    Node *temp = first;
    while (--pos)
        temp = temp->next;
    last->next = temp;
    cout << "Added loop from: " << last->next->data << "\n";
}

bool LinkedList::CheckLoop()
{
    Node *f, *s;
    s = f = first;
    while (f && s)
    {
        s = s->next;
        f = f->next;
        if (f != NULL)
            f = f->next;
        if (f == s)
            return true;
    }
    return false;
}

void menu(LinkedList *link)
{
    Node *temp;
    temp = link->first;
    int option, i, n, m, key, pos;
    cout << "-----LINKED-LIST-----\n";
    cout << "1. Display\n";
    cout << "2. CountNode\n";
    cout << "3. Sum\n";
    cout << "4. Max\n";
    cout << "5. Search\n";
    cout << "6. Insert\n";
    cout << "7. Append\n";
    cout << "8. InsertSorted\n";
    cout << "9. Delete\n";
    cout << "10. CheckSorted\n";
    cout << "11. RemoveDuplicates\n";
    cout << "12. Reverse\n";
    cout << "13. Concat\n";
    cout << "14. Merge\n";
    cout << "15. CheckLoop\n";
    cout << "Enter option: ";
    cin >> option;
    int a[n], b[m];
    switch (option)
    {
    case 1:
        link->DisplayI();
        cout << "Linked list: ";
        link->DisplayR();
        cout << "\nLinked list(reverse): ";
        link->first = temp;
        link->DisplayRR();
        cout << "\n";
        link->first = temp;
        break;
    case 2:
        cout << "No. of nodes: " << link->NodeCount() << "\n";
        cout << "No. of nodes(recursive): " << link->NodeCountR() << "\n";
        link->first = temp;
        break;
    case 3:
        cout << "Sum of nodes(iterative): " << link->SumI() << "\n";
        cout << "Sum of nodes(recursive): " << link->SumR() << "\n";
        link->first = temp;
        break;
    case 4:
        cout << "Max (iterative): " << link->MaxI() << "\n";
        cout << "Max (recursive): " << link->MaxR() << "\n";
        link->first = temp;
        break;
    case 5:
        cout << "Enter search value: ";
        cin >> key;
        cout << "LinearSearch(iterative): " << link->LSearchI(key) << "\n";
        cout << "LinearSearch(recursive): " << link->LSearchR(key) << "\n";
        link->first = temp;
        cout << "LinearSearch(MTH): " << link->LSearchMTH(key) << "\n";
        cout << "LinearSearch(T): " << link->LSearchT(key) << "\n";
        break;
    case 6:
        cout << "Enter pos & value: ";
        cin >> pos >> key;
        link->Insert(pos, key);
        break;
    case 7:
        cout << "Enter value: ";
        cin >> key;
        link->Append(key);
        break;
    case 8:
        cout << "Enter value: ";
        cin >> key;
        link->InsertSorted(key);
        break;
    case 9:
        cout << "Enter pos: ";
        cin >> pos;
        link->Delete(pos);
        break;
    case 10:
        cout << "Is sorted: " << link->CheckSorted() << "\n";
        break;
    case 11:
        link->RemoveDuplicates();
        break;
    case 12:
        cout << "Reverse elements: ";
        link->ReverseElement();
        cout << "Reverse links(iterative): ";
        link->ReverseLinksI();
        cout << "Reverse links(recursive): ";
        link->ReverseLinksR(NULL, link->first);
        link->DisplayI();
        break;
    case 13:
    case 14:
        LinkedList *newLink;
        cout << "Size: ";
        cin >> m;
        cout << "Enter elements: ";
        for (i = 0; i < m; i++)
            cin >> b[i];
        newLink = new LinkedList(b, m);
        cout << "Linkedlist created...\n";
        link->DisplayI();
        newLink->DisplayI();
        if (option == 13)
        {
            cout << "Concating....\n";
            link->Concat(newLink);
        }
        else if (option == 14)
        {
            cout << "Merging....\n";
            link->Merging(newLink);
        }
        break;
    case 15:
        cout << "Enter loop pos: ";
        cin >> pos;
        if (pos >= 1 && pos <= link->NodeCount())
            link->AddLoop(pos);
        cout << "Is loop: " << link->CheckLoop() << "\n";
        link->last->next = NULL;
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