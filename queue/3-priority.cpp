#include "queue.h"

//Priority queue level based
class PriorityLevel
{
private:
    QueueLink *P;
    int level;

public:
    PriorityLevel(int level);
    void display();
    void enqueue(int value, int level);
    void dequeue();
    ~PriorityLevel();
};

PriorityLevel::PriorityLevel(int level)
{
    P = new QueueLink[level];
    this->level = level;
}

void PriorityLevel::display()
{
    for (int i = 0; i < level; i++)
    {
        cout << i + 1 << " : ";
        P[i].display();
    }
}

void PriorityLevel::enqueue(int value, int level)
{
    if (level >= 0 && level <= this->level)
        if (!P[level - 1].full())
            P[level - 1].enqueue(value);
        else
            cout << "Queue level " << level << "full\n";
    else
        cout << "Invalid queue level\n";
}

void PriorityLevel::dequeue()
{
    int i;
    for (i = 0; i < level; i++)
        if (!P[i].empty())
        {
            P[i].dequeue();
            return;
        }
    cout << "Queue empty\n";
}

PriorityLevel::~PriorityLevel()
{
    delete[] P;
}

//PriorityLevel queue based on position of element
class PriorityPosition
{
private:
    Node *frontnode;

public:
    PriorityPosition();
    void display();
    void enqueue(int value);
    void dequeue();
    int front();
    bool empty();
    bool full();
    ~PriorityPosition();
};

PriorityPosition::PriorityPosition()
{
    frontnode = nullptr;
}

bool PriorityPosition::empty()
{
    if (!frontnode)
        return true;
    return false;
}

bool PriorityPosition::full()
{
    Node *temp = new Node(0);
    if (!temp)
        return true;
    return false;
}

int PriorityPosition::front()
{
    if (!empty())
        return frontnode->data;
    return -1;
}

void PriorityPosition::enqueue(int value)
{
    if (!full())
    {
        Node *temp, *follow;
        Node *newnode = new Node(value);
        if (empty())
            frontnode = newnode;
        else
        {
            if (value > frontnode->data)
            {
                newnode->next = frontnode;
                frontnode = newnode;
            }
            else
            {
                temp = frontnode;
                while (!(value > frontnode->data))
                {
                    follow = frontnode;
                    frontnode = frontnode->next;
                    if (!frontnode)
                    {
                        follow->next = newnode;
                        frontnode = temp;
                        return;
                    }
                }
                newnode->next = frontnode;
                follow->next = newnode;
                frontnode = temp;
            }
        }
    }
    else
        cout << "Queue full\n";
}

void PriorityPosition::dequeue()
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

void PriorityPosition::display()
{
    Node *head = frontnode;
    if (!empty())
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
    else
        cout << "Queue empty";
    cout << "\n";
}

PriorityPosition::~PriorityPosition()
{
    Node *temp;
    while (frontnode)
    {
        temp = frontnode;
        frontnode = frontnode->next;
        delete temp;
    }
}

int main()
{
    int level = 5;
    PriorityLevel *p = new PriorityLevel(level);
    PriorityPosition *q = new PriorityPosition();
    for (int i = 1; i <= level; i++)
        for (int j = 1; j <= 3; j++)
            p->enqueue(i, i);
    cout << "Created queue:\n";
    p->display();

    cout << "-------------------\n";
    for (int i = 0; i < level; i++)
    {
        p->dequeue();
        p->display();
        cout << "-------------------\n";
    }

    q->display();
    q->enqueue(4);
    q->display(); // 4
    q->enqueue(1);
    q->display(); // 4 1
    q->enqueue(3);
    q->display(); // 4 3 1
    q->enqueue(2);
    q->display(); // 4 3 2 1
    q->dequeue();
    q->display(); // 3 2 1
    q->enqueue(6);
    q->display(); // 6 3 2 1

    return 0;
}