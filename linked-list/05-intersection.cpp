#include "node1.h"

Node *CreateLink(int a[], int n, Node *first)
{
    int i;
    Node *temp, *last;
    temp = new Node(a[0]);
    first = temp;
    last = first;
    for (i = 1; i < n; i++)
    {
        temp = new Node(a[i]);
        last->next = temp;
        last = temp;
    }
    return first;
}

void Display(Node *first)
{
    Node *temp = first;
    while (first)
    {
        cout << first->data;
        first = first->next;
        if (first != NULL)
            cout << " -> ";
    }
    first = temp;
    cout << "\n";
}

Node *Intersection(Node *first, Node *second)
{
    int addr1, addr2;
    Node *t1 = first, *t2 = second;
    stack<Node *> f, s;
    while (t1)
    {
        f.push(t1);
        t1 = t1->next;
    }
    while (t2)
    {
        s.push(t2);
        t2 = t2->next;
    }
    while (!s.empty() && !f.empty())
    {
        if (s.top() == f.top())
        {
            t1 = s.top();
            s.pop();
            f.pop();
        }
        else
            return t1;
    }
    return NULL;
}

int main()
{
    Node *A, *B, *temp1, *temp2;
    int n, m, i;
    cout << "First:\n";
    cout << "Size: ";
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    A = CreateLink(a, n, A);
    Display(A);
    cout << "Second:\n";
    cout << "Size: ";
    cin >> m;
    int b[m];
    for (i = 0; i < m; i++)
        cin >> b[i];
    B = CreateLink(b, m, B);
    Display(B);
    cout << "Enter position to create intersection: ";
    cin >> m;
    temp1 = A;
    temp2 = B;
    while (--m && temp1->next != NULL)
        temp1 = temp1->next;
    while (temp2->next)
        temp2 = temp2->next;
    temp2->next = temp1;

    Display(A);
    Display(B);
    cout << Intersection(A, B)->data;
    return 0;
}