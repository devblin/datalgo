#include <bits/stdc++.h>
using namespace std;

//Queue array using single pointer
class QueueOne
{
private:
    int size, rearPt = -1;
    int *Q;

public:
    QueueOne(int size);
    void enqueue(int value); // O(1)
    void dequeue();          // O(n)
    int front();             // O(1)
    int rear();              // O(1)
    bool empty();            // O(1)
    bool full();             // O(1)
    void display();          // O(n)
    ~QueueOne();
};

QueueOne::QueueOne(int size)
{
    this->size = size;
    Q = new int[size];
}

void QueueOne::display()
{
    int i = 0;
    if (!empty())
    {
        for (i = 0; i <= rearPt; i++)
            cout << Q[i] << " ";
        cout << "\n";
    }
    else
        cout << "Queue empty\n";
}

void QueueOne::enqueue(int value)
{
    if (!full())
        Q[++rearPt] = value;
    else
        cout << "Queue full\n";
}

void QueueOne::dequeue()
{
    int i;
    if (!empty())
    {
        for (i = 0; i < rearPt; i++)
            Q[i] = Q[i + 1];
        rearPt--;
    }
    else
        cout << "Queue empty";
    cout << "\n";
}

bool QueueOne::full()
{
    if (rearPt == size - 1)
        return true;
    return false;
}

bool QueueOne::empty()
{
    if (rearPt == -1)
        return true;
    return false;
}

int QueueOne::front()
{
    if (!empty())
        return Q[0];
    return -1;
}

int QueueOne::rear()
{
    if (!empty())
        return Q[rearPt];
    return -1;
}

QueueOne::~QueueOne()
{
    delete[] Q;
}

//Queue array using double pointers
class QueueTwo
{
private:
    int *Q, size, frontp = -1, rearp = -1;

public:
    QueueTwo(int size);
    void enqueue(int value); // O(1)
    void dequeue();          // O(1)
    int front();             // O(1)
    int rear();              // O(1)
    bool empty();            // O(1)
    bool full();             // O(1)
    void display();          // O(n)
    ~QueueTwo();
};

QueueTwo::QueueTwo(int size)
{
    Q = new int[size];
    this->size = size;
}

void QueueTwo::enqueue(int value)
{
    if (!full())
        Q[++rearp] = value;
    else
        cout << "Queue full\n";
}

void QueueTwo::dequeue()
{
    if (!empty())
        frontp++;
    else
        cout << "Queue empty\n";
}

int QueueTwo::front()
{
    if (!empty())
        return Q[frontp + 1];
    return -1;
}

int QueueTwo::rear()
{
    if (!empty())
        return Q[rearp];
    return -1;
}

bool QueueTwo::full()
{
    if (rearp == size - 1)
        return true;
    return false;
}

bool QueueTwo::empty()
{
    if (rearp == frontp)
        return true;
    return false;
}

void QueueTwo::display()
{
    int i;
    if (!empty())
        for (i = frontp + 1; i <= rearp; i++)
            cout << Q[i] << " ";
    else
        cout << "Queue empty";
    cout << "\n";
}

QueueTwo::~QueueTwo()
{
    delete[] Q;
}

//Circular Queue array
class CircularQueue
{
private:
    int *Q, size, frontpoint = 0, rearpoint = 0;

public:
    CircularQueue(int size);
    void enqueue(int value); // O(1)
    void dequeue();          // O(1)
    int front();             // O(1)
    int rear();              // O(1)
    bool empty();            // O(1)
    bool full();             // O(1)
    void display();          // O(n)
    ~CircularQueue();
};

CircularQueue::CircularQueue(int size)
{
    this->size = size + 1;
    Q = new int[size + 1];
}

void CircularQueue::enqueue(int value)
{
    if (!full())
    {
        rearpoint = (rearpoint + 1) % size;
        Q[rearpoint] = value;
    }
    else
        cout << "Queue full\n";
}

void CircularQueue::dequeue()
{
    if (!empty())
        frontpoint = (frontpoint + 1) % size;
    else
        cout << "Queue empty\n";
}

int CircularQueue::front()
{
    if (!empty())
        return Q[(frontpoint + 1) % size];
    return 0;
}

int CircularQueue::rear()
{
    if (!empty())
        return Q[rearpoint];
    return 0;
}

bool CircularQueue::empty()
{
    if (frontpoint == rearpoint)
        return true;
    return false;
}

bool CircularQueue::full()
{
    if ((rearpoint + 1) % size == frontpoint)
        return true;
    return false;
}

void CircularQueue::display()
{
    int i, limit = rearpoint > frontpoint ? rearpoint : size + rearpoint;
    if (!empty())
        for (i = frontpoint + 1; i <= limit; i++)
            cout << Q[i % size] << " ";
    else
        cout << "Queue empty";
    cout << "\n";
}

CircularQueue::~CircularQueue()
{
    delete[] Q;
}

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

void menu(QueueOne *q1, QueueTwo *q2, CircularQueue *cq, QueueLink *lq)
{
    int option, value;
    cout << "----QUEUE----\n";
    cout << "1.enqueue\n2.dequeue\n3.full\n4.empty\n5.front\n6.rear\n7.display\n0.exit\n";
    cout << "Enter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter value: ";
        cin >> value;
        q1->enqueue(value);
        q2->enqueue(value);
        cq->enqueue(value);
        lq->enqueue(value);
        break;
    case 2:
        q1->dequeue();
        q2->dequeue();
        cq->dequeue();
        lq->dequeue();
        break;
    case 3:
        cout << "Full: " << q1->full() << ", " << q2->full() << ", " << cq->full() << ", " << lq->full() << "\n";
        break;
    case 4:
        cout << "Empty: " << q1->empty() << ", " << q2->empty() << ", " << cq->empty() << ", " << lq->empty() << "\n";
        break;
    case 5:
        cout << "Front: " << q1->front() << ", " << q2->front() << ", " << cq->front() << ", " << lq->front() << "\n";
        break;
    case 6:
        cout << "Rear: " << q1->rear() << ", " << q2->rear() << ", " << cq->rear() << ", " << lq->rear() << "\n";
        break;
    case 7:
        q1->display();
        q2->display();
        cq->display();
        lq->display();
        break;
    default:
        break;
    }
    if (option != 0)
        menu(q1, q2, cq, lq);
}

int main()
{
    int size;
    cout << "Enter queue size: ";
    cin >> size;
    QueueOne *q1 = new QueueOne(size);
    QueueTwo *q2 = new QueueTwo(size);
    CircularQueue *cq = new CircularQueue(size);
    QueueLink *lq = new QueueLink();
    menu(q1, q2, cq, lq);
    return 0;
}