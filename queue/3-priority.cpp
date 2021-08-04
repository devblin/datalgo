#include "queue.h"

//Priority queue level based
class Priority
{
private:
    QueueLink *P;
    int level;

public:
    Priority(int level);
    void display();
    void enqueue(int value, int level);
    void dequeue();
    ~Priority();
};

Priority::Priority(int level)
{
    P = new QueueLink[level];
    this->level = level;
}

void Priority::display()
{
    for (int i = 0; i < level; i++)
    {
        cout << i + 1 << " : ";
        P[i].display();
    }
}

void Priority::enqueue(int value, int level)
{
    if (level >= 0 && level <= this->level)
        if (!P[level - 1].full())
            P[level - 1].enqueue(value);
        else
            cout << "Queue level " << level << "full\n";
    else
        cout << "Invalid queue level\n";
}

void Priority::dequeue()
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

Priority::~Priority()
{
    delete[] P;
}

int main()
{
    int level = 5;
    Priority *p = new Priority(level);
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

    return 0;
}